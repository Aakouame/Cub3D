# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 04:25:39 by akouame           #+#    #+#              #
#    Updated: 2022/11/20 11:50:03 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
HEADER = include/cub.h
CFLAGS = -Wextra -Wall -Werror
LIB = srcs/libft/libft.a
SRCS = $(addprefix srcs/, main.c parsing/check.c gnl/get_next_line_utils.c\
		gnl/get_next_line.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@/bin/echo -n " ✔ "

%.o: %.c $(HEADER)
	@/bin/echo -n "░░"
	@$(CC) -I $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(LIB):
	@/bin/echo -n "loading: ▶️ "
	@make -C srcs/libft

clean:
	make fclean -C srcs/libft
	rm -rf $(OBJS)
	
fclean:
	make fclean -C srcs/libft
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
