/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:10 by wiharel           #+#    #+#             */
/*   Updated: 2021/12/26 12:09:56 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_base_hexa(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}

void	ft_print_fonc_hex(unsigned int n, const char f)
{
	if (n >= 16)
	{
		ft_print_fonc_hex(n / 16, f);
		ft_print_fonc_hex(n % 16, f);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (f == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
			if (f == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
		}
	}
}

int	ft_print_hexa_number(unsigned int n, const char f)
{
	if (!n)
		return (write(1, "0", 1));
	else
		ft_print_fonc_hex(n, f);
	return (ft_len_base_hexa(n));
}
