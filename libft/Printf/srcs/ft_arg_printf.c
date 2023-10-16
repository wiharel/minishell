/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 02:45:10 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/03 19:49:20 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_arg_printf(va_list ap, const char format)
{
	int	p;

	p = 0;
	if (format == 'c')
		p = p + ft_print_one_c(va_arg(ap, int));
	else if (format == 's')
		p = p + ft_print_string_c(va_arg(ap, char *));
	else if (format == 'p')
	{
		ft_putstr("0x");
		p += 2;
		p += ft_hexa(va_arg(ap, unsigned long), 1);
	}
	else if (format == 'd')
		p = p + ft_print_number(va_arg(ap, int));
	else if (format == 'i')
		p = p + ft_print_number(va_arg(ap, int));
	else if (format == 'u')
		p = p + ft_print_unsigned_number(va_arg(ap, unsigned int));
	else if (format == 'X' || format == 'x')
		p = p + ft_print_hexa_number(va_arg(ap, unsigned int), format);
	else if (format == '%')
		p = p + ft_print_percent();
	return (p);
}
