/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:36:36 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:36:41 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_mini;

char	*ft_getenv(const char *var)
{
	char	*var_name;
	char	*ret;
	size_t	i;

	var_name = ft_strjoin(var, "=");
	i = 0;
	while (g_mini.envp[i])
	{
		if (ft_strncmp(g_mini.envp[i], var_name, ft_strlen(var_name)) == 0)
		{
			ret = g_mini.envp[i] + ft_strlen(var_name);
			free(var_name);
			return (ret);
		}
		i++;
	}
	free(var_name);
	return (NULL);
}

void	ft_setenv(const char *var, const char *value)
{
	size_t		i;
	t_string	env_value;
	bool		found;
	char		*var_cpy;

	var_cpy = ft_strjoin(var, "=");
	env_value = ft_str_new_copy(var_cpy);
	ft_str_append_cstr(env_value, value);
	found = false;
	i = 0;
	while (g_mini.envp[i])
	{
		if (ft_strncmp(g_mini.envp[i], var_cpy, ft_strlen(var_cpy)) == 0)
		{
			free(g_mini.envp[i]);
			g_mini.envp[i] = ft_str_take(env_value);
			found = true;
			break ;
		}
		++i;
	}
	if (!found)
		g_mini.envp = ft_strarr_extend(g_mini.envp, ft_str_take(env_value));
	free(var_cpy);
}

char	*var_name(const char *var)
{
	t_string	name;
	char		*ptr;

	ptr = ft_strchr(var, '=');
	if (!ptr || ptr == var)
		return (NULL);
	name = ft_str_new(NULL);
	while (var != ptr)
		ft_str_add_back(name, *var++);
	return (ft_str_take(name));
}

bool	is_valid_var_name(const char *var)
{
	const char	*ptr;

	if (!var)
		return (false);
	ptr = var;
	if (ft_isdigit(*ptr))
		return (false);
	while (*ptr)
	{
		if (!(ft_isalnum(*ptr) || *ptr == '_'))
			return (false);
		++ptr;
	}
	return (true);
}
