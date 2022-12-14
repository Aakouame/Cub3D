/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:43:20 by akouame           #+#    #+#             */
/*   Updated: 2022/12/14 18:54:05 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line.h"

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
	char	*c;
	char	*f;
	int		tab_c[3];
	int		tab_f[3];
}	t_color;

typedef struct s_exist
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_exist;

typedef struct s_map
{
	int		fr_space;
	int		wall;
	int		p;
	char	position;
	t_cord	indx;
	char	**map_splited;
}	t_map;

typedef struct s_data
{
	t_cord		player;
	t_textures	txtrs;
	t_color		color;
	char		*all;
	char		**all_splited;
	char		*msg;
	t_exist		check;
	t_map		map;
}	t_data;

int		ft_check_exist(char *line, char *find, char **txtr, int size);
int		ft_check(char *file, t_data *data);
int		ft_search(char *str, int c);
void	ft_er_msg(char *msg);
int		check_color(char **splited, t_data *data);
int		h_m_repeated(char	*str, int c);
int		is_number(char *str);
int		ft_indix_map(char	**splited);

#endif
