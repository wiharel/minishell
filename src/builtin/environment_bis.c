/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:47:00 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:47:03 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_node *node)
{
	size_t	i;

	if (ft_strarr_size(node->argv) > 1)
	{
		pset_err(FT_ENV, NULL, TOO_MANY_ARGS, GENERIC_ERR);
		return ;
	}
	i = 0;
	while (g_mini.envp[i])
	{
		ft_putendl_fd(g_mini.envp[i], STDOUT_FILENO);
		++i;
	}
	g_mini.code = SUCCESS;
}
