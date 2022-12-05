/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:58:20 by akouame           #+#    #+#             */
/*   Updated: 2022/12/05 14:58:54 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->my_map.addr + (y * data->my_map.line_length + x * (data->my_map.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  init_mlx(t_data *data)
{
	data->my_map.init = mlx_init();
	data->my_map.win = mlx_new_window ( data->my_map.init, WIDTH, HEIGHT, "cub3d");
	data->my_map.img = mlx_new_image(data->my_map.init,WIDTH,HEIGHT);
	data->my_map.addr = mlx_get_data_addr(data->my_map.img, &data->my_map.bits_per_pixel, &data->my_map.line_length,&data->my_map.endian);
}


void dda(int X0, int Y0, int X1, int Y1,t_data *data,int color)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put(data,round(X), round(Y),color); 
        X += Xinc; 
        Y += Yinc;
    }
}

int get_height(char **str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int get_weight(char **str)
{
	int big_len;
	int i;

	big_len = 0;
	i = 0;
	while(str[i])
	{
		if (ft_strlen(str[i]) > big_len)
			big_len = ft_strlen(str[i]);
		i++;
	}
	return (big_len);
}

void drawcub(t_data *data , int x , int y,unsigned int color)
{
	int x0 = x * my_cubs_len;
	int x1 = (x + 1) * my_cubs_len;
	int y0 = y * my_cubs_len;
	int y1 = (y + 1) * my_cubs_len;
	while(y0 < y1)
	{
		dda(x0,y0,x1,y0,data,color);
		y0++;
	}
}

void init_player(t_data *data)
{
	if (data->player.p == 'E')
		data->player.fi = 0;
	if (data->player.p == 'S')
		data->player.fi = (3 * M_PI) / 2;
	if (data->player.p == 'W')
		data->player.fi = M_PI;
	if (data->player.p == 'N')
		data->player.fi =  M_PI / 2;
	data->player.pos_px.x = (data->player.pos_mp.x * my_cubs_len) + my_cubs_len/2;
	data->player.pos_px.y = (data->player.pos_mp.y * my_cubs_len) + my_cubs_len/2;
}

void draw_map(t_data *data)
{
	int y;
	int x;
	
	data->max.y = get_height(data->my_map.map_splited);
	data->max.x = get_weight(data->my_map.map_splited);
	y = 0;
	while(y < data->max.y)
	{
		x = 0;
		while(x < data->max.x)
		{
			if (data->my_map.map_splited[y][x] == ' ')
				drawcub(data,x,y,0x000000);
			else if (data->my_map.map_splited[y][x] == '1')
				drawcub(data,x,y,0x124A2A);
			else if (data->my_map.map_splited[y][x] == '0')
				drawcub(data,x,y,0x475E6B);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put(data,data->player.pos_px.x,data->player.pos_px.y,0xffff);
	cast_all_rays(data);
}

void normalize_angle(t_data *data)
{
	data->player.fi = fmod(data->player.fi,2 * M_PI);
	if (data->player.fi < 0)
		data->player.fi += 2 * M_PI;
}

int is_down(t_data *data)
{
	if (data->player.ray_angle > 0 && data->player.ray_angle < M_PI)
		return (1);
	return (0);
}

int is_up(t_data *data)
{
	if (!is_down(data))
		return (1);
	return (0);
}

int is_right(t_data *data)
{
	if (data->player.ray_angle < (0.5 * M_PI) || data->player.ray_angle > (1.5 * M_PI))
		return (1);
	return (0);
}

int is_left(t_data *data)
{
	if (!is_right(data))
		return (1);
	return (0);
}

int is_wall(t_data *data,float y,float x)
{
	int x_map;
	int y_map;

	x_map = floor(x/my_cubs_len);
	y_map = floor(y/my_cubs_len);
	//printf("y = %d   x = %d\n",y_map,x_map);
	if (y >= (data->max.y * my_cubs_len))
		return (1);
	if (data->my_map.map_splited[y_map][x_map] == '1')
		return (1);
	return (0);
}

void cast_horz(t_data *data)
{
	float first_x_inter;
	float first_y_inter;
	float y_step;
	float x_step;
	float y_check;
	float x_check;
	data->player.ray_angle = fmod(data->player.ray_angle,2 * M_PI);
	if (data->player.ray_angle < 0)
		data->player.ray_angle += 2 * M_PI;

	data->player.ray.found_h = 0;
	/* horizontal inter */
	first_y_inter = floor(data->player.pos_px.y/my_cubs_len) * my_cubs_len;
	if (is_down(data))
		first_y_inter += my_cubs_len;
	first_x_inter = data->player.pos_px.x + ((first_y_inter - data->player.pos_px.y) /tan(data->player.ray_angle));

	y_step = my_cubs_len;
	if (is_up(data))
		y_step *= -1;

	x_step = my_cubs_len / tan(data->player.ray_angle);
	if (is_left(data) && x_step > 0)
		x_step *= -1;
	if (is_right(data) && x_step < 0)
		x_step *= -1;

	y_check = first_y_inter;
	x_check = first_x_inter;
	if (is_up(data))
		y_check--;
	while(x_check >= 0 && x_check <= WIDTH && y_check >= 0 && y_check <= HEIGHT)
	{
		if (is_wall(data,y_check,x_check))
		{
			data->player.ray.found_h = 1;
			data->player.ray.h_x = first_x_inter;
			data->player.ray.h_y = first_y_inter;
			break;
		}
		y_check += y_step;
		x_check += x_step;
		first_x_inter += x_step;
		first_y_inter += y_step;
	}
}

void cast_ver(t_data *data)
{
	float first_x_inter;
	float first_y_inter;
	float y_step;
	float x_step;
	float y_check;
	float x_check;

	data->player.ray_angle = fmod(data->player.ray_angle,2 * M_PI);
	if (data->player.ray_angle < 0)
		data->player.ray_angle += 2 * M_PI;

	data->player.ray.found_v = 0;
	/* vertical inter */
	first_x_inter = floor(data->player.pos_px.x/my_cubs_len) * my_cubs_len;
	// i need to check this later
	if (is_right(data))
		first_x_inter += my_cubs_len;
	first_y_inter = data->player.pos_px.y + ((first_x_inter - data->player.pos_px.x) * tan(data->player.ray_angle));

	x_step = my_cubs_len;
	if (is_left(data))
		x_step *= -1;

	y_step = my_cubs_len * tan(data->player.ray_angle);
	if (is_up(data) && y_step > 0)
		y_step *= -1;
	if (is_down(data) && y_step < 0)
		y_step *= -1;

	y_check = first_y_inter;
	x_check = first_x_inter;
	if (is_left(data))
		x_check--;
	while(x_check >= 0 && x_check <= WIDTH && y_check >= 0 && y_check <= HEIGHT)
	{
		if (is_wall(data,y_check,x_check))
		{
			data->player.ray.found_v = 1;
			data->player.ray.v_x = first_x_inter;
			data->player.ray.v_y = first_y_inter;
			break;
		}
		y_check += y_step;
		x_check += x_step;
		first_x_inter += x_step;
		first_y_inter += y_step;
	}
}

void get_distance(t_data *data)
{
	if (data->player.ray.found_h)
		data->player.ray.h_distance = sqrt(((data->player.ray.h_x - data->player.pos_px.x) * (data->player.ray.h_x - data->player.pos_px.x)) + ((data->player.ray.h_y - data->player.pos_px.y) * (data->player.ray.h_y - data->player.pos_px.y)));
	else
		data->player.ray.h_distance = INT_MAX;
	if (data->player.ray.found_v)
		data->player.ray.v_distance = sqrt(((data->player.ray.v_x - data->player.pos_px.x) * (data->player.ray.v_x - data->player.pos_px.x)) + ((data->player.ray.v_y - data->player.pos_px.y) * (data->player.ray.v_y - data->player.pos_px.y)));
	else
		data->player.ray.v_distance = INT_MAX;
}

void cast_all_rays(t_data *data)
{
	// ************ calculate start angle and normalize it *************//
	data->player.ray_angle = data->player.fi - (M_PI /6);
	// ******************************************************************//

	int i = 0;

	float inc_ang = (M_PI/3)/WIDTH;
	while(i < WIDTH)
	{
		cast_horz(data);
		cast_ver(data);
		get_distance(data);
		if (data->player.ray.v_distance > data->player.ray.h_distance)
			dda(data->player.pos_px.x,data->player.pos_px.y,data->player.ray.h_x,data->player.ray.h_y,data,0xffffff);
		else
			dda(data->player.pos_px.x,data->player.pos_px.y,data->player.ray.v_x,data->player.ray.v_y,data,0xffffff);
		data->player.ray_angle += inc_ang;
		i++;
	}
}
