/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 02:43:26 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/03 18:48:10 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		p;
	int		i;
	va_list	ap;

	p = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			p = p + ft_arg_printf(ap, str[1 + i]);
			i++;
		}
		else
		{
			p = p + ft_print_one_c(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (p);
}
