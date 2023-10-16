/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:49:11 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:49:15 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	builtin_ptr(const char *str)
{
	if (!ft_strncmp(str, FT_ECHO, sizeof(FT_ECHO) / sizeof(char)))
		return (&ft_echo);
	else if (!ft_strncmp(str, FT_PWD, sizeof(FT_PWD) / sizeof(char)))
		return (&ft_pwd);
	else if (!ft_strncmp(str, FT_CD, sizeof(FT_CD) / sizeof(char)))
		return (&ft_cd);
	else if (!ft_strncmp(str, FT_ENV, sizeof(FT_ENV) / sizeof(char)))
		return (&ft_env);
	else if (!ft_strncmp(str, FT_UNSET, sizeof(FT_UNSET) / sizeof(char)))
		return (&ft_unset);
	else if (!ft_strncmp(str, FT_EXPORT, sizeof(FT_EXPORT) / sizeof(char)))
		return (&ft_export);
	else if (!ft_strncmp(str, FT_EXIT, sizeof(FT_EXIT) / sizeof(char)))
		return (&ft_exit);
	return (NULL);
}
