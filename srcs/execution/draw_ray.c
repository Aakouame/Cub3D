/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:06:06 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/03 19:05:11 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void first_horizontal_intr(t_data *data,int ang)
{
	float y = floor(data->player.pos_px.y/my_cubs_len) * my_cubs_len; 
	float x = data->player.pos_px.x + tan(ang) / (data->player.pos_px.y - y);
	data->ray.x = x;
	data->ray.y = y;
}

void first_vertical_intr(t_data *data,int ang)
{
	float x = floor(data->player.pos_px.x / my_cubs_len) * my_cubs_len;
	float y = -(data->player.pos_px.y + tan(ang) * (x - data->player.pos_px.x));
	data->ray.x = x;
	data->ray.y = y;
}

int check_wall_ray(t_data *data,float x,float y)
{
	if (data->my_map.map_splited[(int)roundf(y)][(int)roundf(x)] == 1)
		return (1);
	return (0);
}

void draw_ray_ver(t_data *data,int ang)
{
	int x_step;
	int y_step;
	int ray_x;
	int ray_y;
	ray_x = data->ray.x;
	ray_y = data->ray.y;

	x_step = my_cubs_len;
	y_step = tan(ang) * x_step;
	while(!check_wall_ray(data,ray_x,ray_y))
	{
		ray_x += x_step;
		ray_y += y_step;
	}
	dda(data->player.pos_px.x,data->player.pos_px.y,ray_x,ray_y,data,0xffffff);
}


void draw_ray_hor(t_data *data,int ang)
{
	int x_step;
	int y_step;
	int ray_x;
	int ray_y;

	ray_x = data->ray.x;
	ray_y = data->ray.y;

	y_step = my_cubs_len;
	x_step = y_step / tan(ang);
	while(!check_wall_ray(data,ray_x,ray_y))
	{
		ray_x += x_step;
		ray_y += y_step;
	}
	dda(data->player.pos_px.x,data->player.pos_px.y,ray_x,ray_y,data,0xffffff);
}
