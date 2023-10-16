/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:44:48 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:44:50 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	return (ft_strall(str, ft_isdigit));
}

void	ft_exit(t_node *node)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (ft_strarr_size(node->argv) == 1)
		g_mini.code = SUCCESS;
	else if (!is_number(node->argv[1]))
		pset_err(FT_EXIT, node->argv[1], NUMERIC_REQ, SYNTAX_ERR);
	else if (ft_strarr_size(node->argv) > 2)
	{
		pset_err(FT_EXIT, NULL, TOO_MANY_ARGS, GENERIC_ERR);
		return ;
	}
	else
		g_mini.code = (uint32_t)(ft_atoi(node->argv[1]) % 256);
	if (node->next)
		return ;
	exit((int)g_mini.code);
}
