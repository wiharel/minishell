/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:39:47 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:39:50 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_next_token_string(t_list *tokens)
{
	if (!tokens->next)
	{
		unexpected_token("\\n");
		return (false);
	}
	if (get_type(tokens->next->content) != STRING)
	{
		unexpected_token(ft_str_data(tokens->next->content));
		return (false);
	}
	return (true);
}

static bool	all_redirs_valid(t_list *tokens)
{
	t_type	type;

	while (tokens)
	{
		type = get_type(tokens->content);
		if (is_redirection(type))
		{
			if (!is_next_token_string(tokens))
				return (false);
			tokens = tokens->next->next;
		}
		else
			tokens = tokens->next;
	}
	return (true);
}

static bool	all_pipes_valid(t_list *tokens)
{
	t_type	type;

	while (tokens)
	{
		type = get_type(tokens->content);
		if (type == PIPE)
		{
			if (!tokens->next)
			{
				unexpected_token("\\n");
				return (false);
			}
			type = get_type(tokens->next->content);
			if (is_redirection(type))
			{
				if (!is_next_token_string(tokens->next))
					return (false);
			}
			else if (!is_next_token_string(tokens))
				return (false);
		}
		tokens = tokens->next;
	}
	return (true);
}

bool	is_valid_syntax(t_list *tokens)
{
	if (get_type(tokens->content) == PIPE)
	{
		unexpected_token(ft_str_data(tokens->content));
		return (false);
	}
	return (all_redirs_valid(tokens) && all_pipes_valid(tokens));
}
