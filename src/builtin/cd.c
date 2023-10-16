/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:49:40 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:49:44 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(void)
{
	char	*cwd;
	char	*oldpwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		pset_err(FT_CD, NULL, strerror(errno), GENERIC_ERR);
		return ;
	}
	oldpwd = ft_getenv(ENV_PWD);
	if (oldpwd)
		ft_setenv(ENV_OLDPWD, oldpwd);
	ft_setenv(ENV_PWD, cwd);
	free(cwd);
	g_mini.code = SUCCESS;
}

void	ft_cd(t_node *node)
{
	if (ft_strarr_size(node->argv) > 1)
	{
		if (ft_strarr_size(node->argv) > 2)
		{
			pset_err(FT_CD, NULL, TOO_MANY_ARGS, GENERIC_ERR);
			return ;
		}
		if (chdir(node->argv[1]) == -1)
		{
			pset_err(FT_CD, strerror(errno), node->argv[1], GENERIC_ERR);
			return ;
		}
	}
	else if (!ft_getenv(ENV_HOME))
	{
		pset_err(FT_CD, NULL, NO_HOME, GENERIC_ERR);
		return ;
	}
	else if (chdir(ft_getenv(ENV_HOME)) == -1)
	{
		pset_err(FT_CD, NULL, strerror(errno), GENERIC_ERR);
		return ;
	}
	update_pwd();
}
