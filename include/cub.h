/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:43:20 by akouame           #+#    #+#             */
/*   Updated: 2022/12/07 15:07:11 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
#define my_cubs_len 32
#define WIDTH 800
#define HEIGHT 700
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "../srcs/libft/libft.h"
#include "../srcs/gnl/get_next_line.h"
#include <math.h>
#include <limits.h>

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct	s_cord_double
{
	double	x;
	double	y;
}	t_cord_double;

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

typedef struct	s_exist
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}   t_exist;

typedef struct s_map
{
	int		fr_space;
	int		wall;
	int		p;
	char	position;
	t_cord	indx;
	char	**map_splited;
	
	// mlx
	void 	*init;
	void	*win;
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_map;

typedef struct s_ray
{
	double h_x;
	double h_y;
	int 	found_h;
	double h_distance;


	double v_x;
	double v_y;
	int found_v;
	double v_distance;
} t_ray;

typedef struct s_player
{
	t_cord	pos_mp;
	t_cord_double	pos_px;

	double	fi;
	double	step_m;
	double	step_r;
	char	p;
	t_ray ray;
	double ray_angle;
}	t_player;


typedef struct s_data
{
	t_player	player;
	t_textures	txtrs;
	t_color		color;
	char		*all;
	char        **all_splited;
	char        **all_split;
	char        *msg;
	t_exist		check;
	t_cord		max;
	t_map		my_map;
	int			key;
	int			key_code;
	double		ray;
}	t_data;

int		ft_check_exist(char *line, char *find, char **txtr, int size);
int		ft_check(char *file, t_data *data);
int 	ft_search(char *str, int c);
void    ft_er_msg(char *msg);
int 	check_color(char **splited, t_data *data);
int		h_m_repeated(char	*str, int c);
int		is_number(char *str);
int		check_map(char	**splited, t_data *data);
int 	ft_search_indice(char  **str, char *s, int size);
int 	ft_indix_start(t_data *data);
int		ft_check_map(t_data *data);
void	ft_add_spc(char **str, t_data *data);
void 	fill_map(t_data *data);
void    free_all(char **str);
void 	free_data(t_data *data);
int		length_tab(char **str);
char	**add_str(char **str, char *s);
void  init_mlx(t_data *data);
void  draw_map(t_data *data);
void init_player(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void dda(double X0, double Y0, double X1, double Y1,t_data *data,double color);
void first_horizontal_intr(t_data *data,int ang);
void first_vertical_intr(t_data *data,int ang);
void draw_ray_ver(t_data *data,int ang);
void draw_ray_hor(t_data *data,int ang);
void normalize_angle(t_data *data);
void cast_all_rays(t_data *data);
#endif
