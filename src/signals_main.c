/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:35:01 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:35:04 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	newline(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_mini.code = INTERRUPT_SIG;
}

void	nothing(int signal)
{
	(void)signal;
}

void	stop_heredoc(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(INTERRUPT_SIG);
}

void	process_exit_status(int wstatus)
{
	if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGQUIT)
	{
		ft_putstr_fd("Quit\n", STDERR_FILENO);
		g_mini.code = QUIT_SIG;
	}
	else if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGINT)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		g_mini.code = INTERRUPT_SIG;
	}
	else if (WIFEXITED(wstatus))
		g_mini.code = WEXITSTATUS(wstatus);
	else
		g_mini.code = GENERIC_ERR;
}
