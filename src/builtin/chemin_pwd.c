/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:44:32 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:44:37 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_node *node)
{
	char	cwd[PATH_MAX];

	(void)node;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_putendl_fd(cwd, STDOUT_FILENO);
	else
	{
		pset_err(FT_PWD, NULL, strerror(errno), GENERIC_ERR);
		return ;
	}
	g_mini.code = SUCCESS;
}
