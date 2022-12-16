# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 04:25:39 by akouame           #+#    #+#              #
#    Updated: 2022/12/16 16:13:18 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
HEADER = include/cub.h
CFLAGS = -Wextra -Wall -Werror -g
LIB = srcs/libft/libft.a
SRCS = $(addprefix srcs/, main.c parsing/check.c gnl/get_next_line_utils.c\
		gnl/get_next_line.c outils/outil_1.c parsing/check_h_1.c \
		outils/outil_2.c parsing/check_h_2.c fill.c free.c execution/draw2d.c \
		parsing/check_h_3.c execution/cast.c execution/utils.c execution/direc.c \
		execution/ver.c execution/horz.c outils/outil_3.c)
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@/bin/echo  " ✔ "

%.o: %.c $(HEADER) srcs/gnl/get_next_line.h srcs/libft/libft.h
	@/bin/echo -n "██"
	@$(CC) -I $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(LIB):
	@/bin/echo -n "loading: ▶ "
	@make -C srcs/libft

clean:
	@make clean -C srcs/libft
	@rm -rf $(OBJS)
	@/bin/echo -n "."
	
fclean:
	@/bin/echo -n "Removing: "
	@make fclean -C srcs/libft
	@rm -rf $(NAME) $(OBJS)
	@/bin/echo -n "."
	@/bin/echo  " ✔  "
	
re: fclean all

.PHONY: all clean fclean re
