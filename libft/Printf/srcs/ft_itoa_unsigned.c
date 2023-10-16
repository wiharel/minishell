/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:52:45 by wiharel           #+#    #+#             */
/*   Updated: 2021/12/16 17:21:16 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	int		length;
	char	*nb;

	length = ft_length_n(n);
	nb = malloc(sizeof(char) * (length + 1));
	if (!nb)
		return (NULL);
	nb[length] = '\0';
	while (n != 0)
	{
		nb[length - 1] = n % 10 + '0';
		n = n / 10;
		length--;
	}
	return (nb);
}
