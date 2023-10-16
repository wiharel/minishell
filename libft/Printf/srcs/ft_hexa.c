/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:03:30 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/05 13:05:09 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_hexa(unsigned long nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_hexa(nb / 16, s);
	}
	if (nb % 16 < 10)
	{
		len += ft_putchar((nb % 16) + 48);
	}
	else
	{
		if (s == 1)
			len += ft_putchar((nb % 16) + 87);
		else
			len += ft_putchar((nb % 16) + 55);
	}
	return (len);
}
