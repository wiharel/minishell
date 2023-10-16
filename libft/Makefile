# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:31:02 by wiharel           #+#    #+#              #
#    Updated: 2021/11/29 19:30:39 by wiharel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c \
       src/ft_strlen.c src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c \
       src/ft_strlcpy.c  src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c \
       src/ft_strrchr.c src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c \
       src/ft_calloc.c src/ft_strdup.c src/ft_atoi.c src/ft_substr.c \
       src/ft_strjoin.c \
       src/ft_strtrim.c src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c \
       src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c

OBJS = src/ft_isalpha.o src/ft_isdigit.o src/ft_isalnum.o src/ft_isascii.o src/ft_isprint.o \
		src/ft_strlen.o src/ft_memset.o src/ft_bzero.o src/ft_memcpy.o src/ft_memmove.o \
		src/ft_strlcpy.o  src/ft_strlcat.o src/ft_toupper.o src/ft_tolower.o src/ft_strchr.o \
		src/ft_strrchr.o src/ft_strncmp.o src/ft_memchr.o src/ft_memcmp.o src/ft_strnstr.o \
		src/ft_calloc.o src/ft_strdup.o src/ft_atoi.o src/ft_substr.o \
		src/ft_strjoin.o \
		src/ft_strtrim.o src/ft_split.o src/ft_itoa.o src/ft_strmapi.o src/ft_striteri.o \
		src/ft_putchar_fd.o src/ft_putstr_fd.o src/ft_putendl_fd.o src/ft_putnbr_fd.o

BONUS = src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstlast.c \
	src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstiter.c \
	src/ft_lstmap.c 

BONUS_OBJS = $(BONUS:.c=.o)

NAME = src/liibft.a

HEAD := -I . 

CC = clang

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	gcc $(CFLAGS) $(HEAD) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:
	rm -rf $(NAME) $(OBJS) $(BONUS_OBJS)

re: fclean all

