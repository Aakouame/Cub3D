# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:40:23 by akouame           #+#    #+#              #
#    Updated: 2022/11/22 09:57:26 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c\
	   ft_isascii.c\
	   ft_memcmp.c\
	   ft_putendl_fd.c\
	   ft_strdup.c\
	   ft_strlen.c\
	   ft_strtrim.c\
	   ft_bzero.c\
	   ft_isdigit.c\
	   ft_memcpy.c\
	   ft_putnbr_fd.c\
	   ft_striteri.c\
	   ft_strmapi.c\
	   ft_substr.c\
	   ft_calloc.c\
	   ft_isprint.c\
	   ft_memmove.c\
	   ft_putstr_fd.c\
	   ft_strjoin.c\
	   ft_strncmp.c\
	   ft_tolower.c\
	   ft_isalnum.c\
	   ft_itoa.c\
	   ft_memset.c\
	   ft_split.c\
	   ft_strlcat.c\
	   ft_strnstr.c\
	   ft_toupper.c\
	   ft_isalpha.c\
	   ft_memchr.c\
	   ft_putchar_fd.c\
	   ft_strchr.c\
	   ft_strlcpy.c\
	   ft_strrchr.c
OBJS = $(SRCS:.c=.o)
all:$(NAME)

%.o :%.c libft.h
	@/bin/echo -n "█"
	@$(CC) $(CFLAGS) -c -o $@ $< -I libft.h

$(NAME):$(OBJS)
	@ar -rc $(NAME) $(OBJS)
clean:
	@rm -rf $(OBJS)
	@/bin/echo -n "."
fclean:clean
	@rm -rf $(NAME)
	@/bin/echo -n "."

re:fclean all
.PHONY: all clean fclean re
