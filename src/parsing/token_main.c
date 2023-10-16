/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:37:23 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:37:27 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	get_type(t_string token)
{
	if (!ft_strncmp(ft_str_data(token), "|", ft_str_len(token)))
		return (PIPE);
	if (!ft_strncmp(ft_str_data(token), "<", ft_str_len(token)))
		return (INPUT);
	if (!ft_strncmp(ft_str_data(token), "<<", ft_str_len(token)))
		return (HEREDOC);
	if (!ft_strncmp(ft_str_data(token), ">", ft_str_len(token)))
		return (OUTPUT);
	if (!ft_strncmp(ft_str_data(token), ">>", ft_str_len(token)))
		return (APPEND);
	return (STRING);
}

bool	is_redirection(t_type type)
{
	if (type == OUTPUT || type == APPEND
		|| type == INPUT || type == HEREDOC)
		return (true);
	return (false);
}
