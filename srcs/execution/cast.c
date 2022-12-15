/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:22:39 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/15 21:58:06 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_texture(t_text *txt, t_data *data, float wall_height)
{
	data->my_txt.wall_height = wall_height;
	data->my_txt.txt = txt;
}

void	cast_all_rays(t_data	*data)
{
	double	wall_height;
	double	test;
	double	start;
	double	end;
	double	inc_ang;
	int		i;
	int		j;

	i = 0;
	data->player.ray_angle = data->player.fi - (M_PI / 6);
	inc_ang = (M_PI / 3) / WIDTH;
	while (i < WIDTH)
	{
		cast_horz(data);
		cast_ver(data);
		get_distance(data);
		if (data->player.ray.v_distance > data->player.ray.h_distance)
		{
			data->player.ray.h_distance \
				*= cos(data->player.ray_angle - data->player.fi);
			test = data->player.ray.h_distance / data->my_cubs_len;
			wall_height = HEIGHT / (test);
			data->x_offset = fmod(data->player.ray.h_x, data->my_cubs_len);
		}
		else
		{
			data->player.ray.v_distance \
				*= cos(data->player.ray_angle - data->player.fi);
			test = data->player.ray.v_distance / data->my_cubs_len;
			wall_height = HEIGHT / (test);
			data->x_offset = fmod(data->player.ray.v_y, data->my_cubs_len);
		}
		start = (HEIGHT / 2) - (wall_height / 2);
		end = (HEIGHT / 2) + (wall_height / 2);
		if (start < 0)
			start = 0;
		if (end > HEIGHT)
			end = HEIGHT - 1;
		j = 0;
		while (j < (HEIGHT / 2))
			my_mlx_pixel_put(data, i, j++, get_cieling(data));
		j = start;
		while (j < end)
		{
			if (data->player.ray.v_distance > data->player.ray.h_distance)
			{
				if (is_down(data))
				{
					init_texture(&data->b_texture, data, wall_height);
					my_mlx_pixel_put(data, i, j, get_pixel(start, \
								j, i, data));
				}
				else if (is_up(data))
				{
					init_texture(&data->f_texture, data, wall_height);
					my_mlx_pixel_put(data, i, j, get_pixel(start, \
								j, i, data));
				}
			}
			else
			{
				if (is_right(data))
				{
					init_texture(&data->r_texture, data, wall_height);
					my_mlx_pixel_put(data, i, j, get_pixel(start, \
								j, i, data));
				}
				else if (is_left(data))
				{
					init_texture(&data->l_texture, data, wall_height);
					my_mlx_pixel_put(data, i, j, get_pixel(start, \
								j, i, data));
				}
			}
			j++;
		}
		j = end;
		while (j < HEIGHT - 1)
			my_mlx_pixel_put(data, i, j++, get_floor(data));
		data->player.ray_angle += inc_ang;
		i++;
	}
}
