/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:02:01 by wiharel           #+#    #+#             */
/*   Updated: 2021/11/14 20:46:52 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = 1 + ft_strlen(s);
	s2 = malloc(sizeof(char) * len);
	if (!s2)
		return (0);
	s2 = ft_memcpy(s2, s, len);
	return (s2);
}
