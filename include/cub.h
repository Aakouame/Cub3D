/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:02:50 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/16 19:19:11 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define WIDTH 900
# define HEIGHT 900
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
# include <math.h>
# include <limits.h>

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct s_cord_double
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
	t_cord	indx;
	char	position;
	char	**map_splited;
	char	*addr;
	void	*init;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fr_space;
	int		wall;
	int		p;

}	t_map;

typedef struct s_ray
{
	double	h_distance;
	double	v_x;
	double	v_y;
	double	h_x;
	double	h_y;
	double	v_distance;
	int		found_h;
	int		found_v;
}	t_ray;

typedef struct s_player
{
	t_cord_double	pos_px;
	t_cord			pos_mp;
	t_ray			ray;
	double			fi;
	double			step_m;
	double			step_r;
	double			ray_angle;
	char			p;
}	t_player;

typedef struct s_text
{
	void	*img;
	int		height;
	int		width;
	int		*arr;
	int		line_length;
	int		bpp;
	int		endian;
}	t_text;

typedef struct s_pixel
{
	double	wall_height;
	t_text	*txt;
}	t_pixel;

typedef struct s_data
{
	t_player	player;
	t_textures	txtrs;
	t_color		color;
	t_exist		check;
	t_cord		max;
	t_map		my_map;
	t_text		r_texture;
	t_text		l_texture;
	t_text		f_texture;
	t_text		b_texture;
	t_pixel		my_txt;
	char		*all;
	char		**all_splited;
	char		**all_split;
	char		*msg;
	int			key;
	int			key_code;
	int			my_cubs_len;
	double		ray;
	double		x_offset;
	int			j;
	int			i;
	int			k;
	double		wall_height;
	double		start;
	double		end;
	double		ic_ag;
	double		d;

}	t_data;

unsigned long	get_floor(t_data *data);
unsigned long	get_cieling(t_data *data);
unsigned int	get_pixel(int start, int y, int x, t_data *data);
int				ft_check_exist(char *line, char *find, char **txtr, int size);
int				ft_check(char *file, t_data *data);
int				ft_search(char *str, int c);
int				check_color(char **splited, t_data *data);
int				h_m_repeated(char	*str, int c);
int				is_number(char *str);
int				check_map(char	**splited, t_data *data);
int				ft_search_indice(char **str, char *s, int size);
int				ft_indix_start(t_data *data);
int				ft_check_map(t_data *data);
int				check_wall(t_data *data, int x, int y);
int				is_down(t_data	*data);
int				is_up(t_data	*data);
int				is_right(t_data	*data);
int				is_left(t_data	*data);
int				length_tab(char **str);
int				is_wall(t_data *data, double y, double x);
int				get_height(char **str);
int				get_weight(char	**str);
void			ft_add_spc(char **str, t_data *data);
void			fill_map(t_data *data);
void			free_all(char **str);
void			free_data(t_data *data);
void			draw_map(t_data *data);
void			init_player(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			first_horizontal_intr(t_data *data, int ang);
void			first_vertical_intr(t_data *data, int ang);
void			draw_ray_ver(t_data *data, int ang);
void			draw_ray_hor(t_data *data, int ang);
void			normalize_angle(t_data *data);
void			cast_all_rays(t_data *data);
int				ft_check_exist_textures(char *line, char *find, \
					char **txtr, int size);
void			ft_read_h(char *line, int fd, t_data *data, char *mok);
void			ft_init(t_data *data);
void			fill_horz_inter(t_data *data, double *x, double *y);
void			normalize_rayangle(t_data *data);
void			get_distance(t_data	*data);
void			init_texture(t_text *txt, t_data *data, float wall_height);
void			cast_ver(t_data	*data);
void			cast_horz(t_data	*data);
char			**add_str(char **str, char *s);
int				length_tab(char **str);
int				init_mlx(t_data *data);
void			check_exist_map_h(char *splited, t_data *data);
void			init_texture(t_text *txt, t_data *data, float wall_height);
int				check_wall_h(t_data *data, int x, int y, t_cord r);
int				check_wall(t_data *data, int x, int y);
unsigned long	creatergb(int r, int g, int b);
unsigned long	get_floor(t_data *data);
unsigned long	get_cieling(t_data *data);
int				check_walls(t_data *data, char c);
void			check_walls_hh(t_data *data, char c);
int				ft_er_msg(char *msg);
#endif
