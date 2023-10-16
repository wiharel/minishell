/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:38:29 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:38:31 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	interpolate_redir(void *redir)
{
	t_redir	*r;

	r = redir;
	r->file = interpolate(r->file);
}

void	interpolate_redirs(t_list *redirs)
{
	ft_lstiter(redirs, interpolate_redir);
}
