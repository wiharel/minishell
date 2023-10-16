/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:42:27 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:42:30 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dispatch_cmd(t_node *node, bool subshell)
{
	t_builtin	ptr;

	ptr = builtin_ptr(node->argv[0]);
	if (ptr)
		ptr(node);
	else if (subshell)
		ft_cmd_subshell(node);
	else
		ft_cmd(node);
}

static void	execute(t_node *node, bool subshell)
{
	if (!subshell && !op_control(node))
		return ;
	interpolate_arr(node->argv);
	interpolate_redirs(node->redirs);
	if (node->argv[0])
	{
		dispatch_cmd(node, subshell);
		ft_setenv("_", ft_strarr_last(node->argv));
	}
}

static void	execute_subshell(t_node *node)
{
	pid_t	pid;
	int		wstatus;

	if (!op_control(node))
		return ;
	signal(SIGINT, nothing);
	signal(SIGQUIT, nothing);
	pid = fork();
	if (pid == -1)
	{
		pset_err(SHELL_NAME, NULL, strerror(errno), GENERIC_ERR);
		return ;
	}
	if (pid == 0)
	{
		execute(node, true);
		exit((int)g_mini.code);
	}
	waitpid(pid, &wstatus, 0);
	signal(SIGINT, newline);
	signal(SIGQUIT, SIG_IGN);
	process_exit_status(wstatus);
}

static bool	process_heredocs(t_node *cmds)
{
	while (cmds)
	{
		if (!exec_heredocs(cmds->redirs, cmds->fd[0]))
			return (true);
		cmds = cmds->next;
	}
	return (false);
}

void	process_cmd(t_node *cmds)
{
	t_node	*start;
	bool	error;

	start = cmds;
	init_pipes(start);
	error = process_heredocs(cmds);
	while (!error && cmds)
	{
		if (all_same_cmd(start))
		{
			cmds = nodelast(start);
			cmds->prev = NULL;
		}
		if (cmds->next)
			execute_subshell(cmds);
		else
			execute(cmds, false);
		fd_reset();
		if (g_mini.code == QUIT_SIG || g_mini.code == INTERRUPT_SIG)
			break ;
		cmds = cmds->next;
	}
	close_pipes(start);
}
