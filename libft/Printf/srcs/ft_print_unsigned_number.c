/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:53 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/05 13:05:44 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_length_n(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

int	ft_print_unsigned_number(unsigned int n)
{
	int		length;
	char	*number;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		number = ft_itoa_unsigned(n);
		length += ft_print_string_c(number);
		free(number);
	}
	return (length);
}
