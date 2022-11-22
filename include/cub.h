/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:43:20 by akouame           #+#    #+#             */
/*   Updated: 2022/11/20 13:06:05 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "../srcs/libft/libft.h"
#include "../srcs/gnl/get_next_line.h"
// #include <sys/stat.h>
#include <fcntl.h>

typedef struct s_cord
{
    int x;
    int y;
}   t_cord;

int	ft_check(char *file);

#endif
