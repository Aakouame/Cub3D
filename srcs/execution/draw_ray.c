/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:06:06 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/03 19:40:30 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void first_horizontal_intr(t_data *data,int ang)
{
	float y = floor(data->player.pos_px.y/my_cubs_len) * my_cubs_len; 
	float x = data->player.pos_px.x + ((data->player.pos_px.y - y) / tan(ang));
	data->ray.x = x;
	data->ray.y = y;
}

void first_vertical_intr(t_data *data,int ang)
{
	float x = floor(data->player.pos_px.x / my_cubs_len) * my_cubs_len;
	float y = data->player.pos_px.y + ((data->player.pos_px.x - x) * tan(ang));
	data->ray.x = x;
	data->ray.y = y;
}

int check_wall_ray(t_data *data,float x,float y)
{
	if (x > 2560 || y > 1440)
		return (1);
	if (data->my_map.map_splited[(int)roundf(y/my_cubs_len)][(int)roundf(x/my_cubs_len)] == '1')
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
	data->p_ray.x = ray_x;
	data->p_ray.y = ray_y; 
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
	data->p_ray.x = ray_x;
	data->p_ray.y = ray_y; 
}
