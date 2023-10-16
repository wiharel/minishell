# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiharel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 16:17:05 by wiharel           #+#    #+#              #
#    Updated: 2022/01/05 15:37:40 by wiharel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_arg_printf.c srcs/ft_hexa.c srcs/ft_itoa.c \
	   srcs/ft_itoa_unsigned.c srcs/ft_print_hexa_number.c \
	   srcs/ft_print_number.c srcs/ft_print_one_c.c srcs/ft_print_percent.c \
	   srcs/ft_print_string_c.c srcs/ft_print_unsigned_number.c \
	   srcs/ft_printf.c srcs/ft_putchar_fd.c srcs/ft_putstr.c 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

HEAD := -I .

CC = clang

GFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) $(HEAD) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all
