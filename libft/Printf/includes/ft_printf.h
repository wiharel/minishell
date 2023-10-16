/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:03:12 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/05 13:09:13 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_arg_printf(va_list ap, const char format);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_len_base_hexa(unsigned int n);
void	ft_print_fonc_hex(unsigned int n, const char f);
int		ft_print_hexa_number(unsigned int n, const char f);
int		ft_print_number(int n);
int		ft_print_one_c(int c);
int		ft_print_percent(void);
int		ft_print_string_c(char *str);
int		ft_length_n(unsigned int n);
int		ft_print_unsigned_number(unsigned int n);
void	ft_put_p(unsigned long int n);
int		ft_p_length(unsigned long int n);
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
int		ft_hexa(unsigned long nb, int s);
#endif
