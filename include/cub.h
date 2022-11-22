/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:43:20 by akouame           #+#    #+#             */
/*   Updated: 2022/11/22 11:19:15 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

#define CUB_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "../srcs/libft/libft.h"
#include "../srcs/gnl/get_next_line.h"

typedef struct s_cord
{
    int	x;
    int	y;
}	t_cord;

typedef struct s_textures
{
    char	*so;
    char	*no;
    char	*we;
    char	*ea;
}	t_textures;

typedef struct s_color
{
    int	c[3];
    int	f[3];
}	t_color;

typedef struct s_data
{
    t_cord		player;
    t_textures	txtrs;
    t_color		color;
    char		**map;
}	t_data;

int	ft_check(char *file, t_data *data);

#endif
