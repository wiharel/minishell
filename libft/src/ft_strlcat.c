/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:12:58 by wiharel           #+#    #+#             */
/*   Updated: 2021/11/14 20:42:14 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;
	size_t	j;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	i = 0;
	j = dest_l;
	if (n > 0 && dest_l < (n - 1))
	{
		while (src[i] && dest_l + i < n - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (n <= dest_l)
		dest_l = n;
	return (dest_l + src_l);
}
