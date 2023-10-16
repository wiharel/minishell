/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:43:22 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:43:25 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_binary(const char *path, char *const *argv)
{
	execve(path, argv, g_mini.envp);
	pset_err(SHELL_NAME, path, strerror(errno), NOT_EXEC_ERR);
	exit(NOT_EXEC_ERR);
}

void	ft_cmd_subshell(t_node *node)
{
	char	*path;

	path = get_cmd_path(node->argv[0]);
	if (!path)
		return ;
	execve(path, node->argv, g_mini.envp);
	pset_err(SHELL_NAME, path, strerror(errno), NOT_EXEC_ERR);
	free(path);
	exit(NOT_EXEC_ERR);
}

void	ft_cmd(t_node *node)
{
	char	*path;
	pid_t	pid;
	int		wstatus;

	path = get_cmd_path(node->argv[0]);
	if (!path)
		return ;
	pid = fork();
	signal(SIGINT, nothing);
	signal(SIGQUIT, nothing);
	if (pid == -1)
	{
		free(path);
		pset_err(SHELL_NAME, NULL, strerror(errno), GENERIC_ERR);
		return ;
	}
	if (pid == 0)
		exec_binary(path, node->argv);
	waitpid(pid, &wstatus, 0);
	signal(SIGINT, newline);
	signal(SIGQUIT, SIG_IGN);
	process_exit_status(wstatus);
	free(path);
}
