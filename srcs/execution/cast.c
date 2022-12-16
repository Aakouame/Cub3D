/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:22:39 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/16 18:15:26 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	cast_all_rays_f_h(t_data	*data)
{
	if (data->player.ray.v_distance > data->player.ray.h_distance)
	{
		data->player.ray.h_distance \
			*= cos(data->player.ray_angle - data->player.fi);
		data->d = data->player.ray.h_distance / data->my_cubs_len;
		data->wall_height = HEIGHT / (data->d);
		data->x_offset = fmod(data->player.ray.h_x, data->my_cubs_len);
	}
	else
	{
		data->player.ray.v_distance \
			*= cos(data->player.ray_angle - data->player.fi);
		data->d = data->player.ray.v_distance / data->my_cubs_len;
		data->wall_height = HEIGHT / (data->d);
		data->x_offset = fmod(data->player.ray.v_y, data->my_cubs_len);
	}
}

void	cast_all_rays_f_s(t_data	*data)
{
	data->start = (HEIGHT / 2) - (data->wall_height / 2);
	data->end = (HEIGHT / 2) + (data->wall_height / 2);
	if (data->start < 0)
		data->start = 0;
	if (data->end > HEIGHT)
		data->end = HEIGHT;
	data->j = 0;
	while (data->j < (HEIGHT / 2))
		my_mlx_pixel_put(data, data->i, data->j++, get_cieling(data));
	data->j = data->start;
}

void	cast_all_rays_h_s(t_data	*data)
{
	if (is_down(data))
	{
		init_texture(&data->b_texture, data, data->wall_height);
		my_mlx_pixel_put(data, data->i, data->j, get_pixel(data->start, \
					data->j, data->i, data));
	}
	else if (is_up(data))
	{
		init_texture(&data->f_texture, data, data->wall_height);
		my_mlx_pixel_put(data, data->i, data->j, get_pixel(data->start, \
					data->j, data->i, data));
	}
}

void	cast_all_rays_s_h(t_data	*data)
{
	if (is_right(data))
	{
		init_texture(&data->r_texture, data, data->wall_height);
		my_mlx_pixel_put(data, data->i, data->j, get_pixel(data->start, \
					data->j, data->i, data));
	}
	else if (is_left(data))
	{
		init_texture(&data->l_texture, data, data->wall_height);
		my_mlx_pixel_put(data, data->i, data->j, get_pixel(data->start, \
					data->j, data->i, data));
	}
}

void	cast_all_rays(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->player.ray_angle = data->player.fi - (M_PI / 6);
	data->ic_ag = (M_PI / 3) / WIDTH;
	while (data->i < WIDTH)
	{
		cast_horz(data);
		cast_ver(data);
		get_distance(data);
		cast_all_rays_f_h(data);
		cast_all_rays_f_s(data);
		while (data->j < data->end)
		{
			if (data->player.ray.v_distance > data->player.ray.h_distance)
				cast_all_rays_h_s(data);
			else
				cast_all_rays_s_h(data);
			data->j++;
		}
		data->j = data->end;
		while (data->j < HEIGHT)
			my_mlx_pixel_put(data, data->i, data->j++, get_floor(data));
		data->player.ray_angle += data->ic_ag;
		data->i++;
	}
}
