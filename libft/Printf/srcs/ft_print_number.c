/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:32:47 by wiharel           #+#    #+#             */
/*   Updated: 2021/12/26 12:04:07 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_number(int n)
{
	int		length;
	char	*number;

	length = 0;
	number = ft_itoa(n);
	length = ft_print_string_c(number);
	free(number);
	return (length);
}
