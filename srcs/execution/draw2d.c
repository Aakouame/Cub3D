/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:58:20 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 19:23:00 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_player(t_data	*data)
{
	if (data->player.p == 'E')
		data->player.fi = 0;
	if (data->player.p == 'S')
		data->player.fi = (3 * M_PI) / 2;
	if (data->player.p == 'W')
		data->player.fi = M_PI;
	if (data->player.p == 'N')
		data->player.fi = M_PI / 2;
	data->player.pos_px.x = (data->player.pos_mp.x * \
			data->my_cubs_len) + data->my_cubs_len / 2;
	data->player.pos_px.y = (data->player.pos_mp.y * \
			data->my_cubs_len) + data->my_cubs_len / 2;
}

void	draw_map(t_data	*data)
{
	data->max.y = get_height(data->my_map.map_splited);
	data->max.x = get_weight(data->my_map.map_splited);
	cast_all_rays(data);
	mlx_put_image_to_window(data->my_map.init, \
			data->my_map.win, data->my_map.img, 0, 0);
}

void	normalize_angle(t_data	*data)
{
	data->player.fi = fmod(data->player.fi, 2 * M_PI);
	if (data->player.fi < 0)
		data->player.fi += 2 * M_PI;
}

void	normalize_rayangle(t_data *data)
{
	data->player.ray_angle = fmod(data->player.ray_angle, 2 * M_PI);
	if (data->player.ray_angle < 0)
		data->player.ray_angle += 2 * M_PI;
}

void	get_distance(t_data	*data)
{
	if (data->player.ray.found_h)
		data->player.ray.h_distance = sqrt(((data->player.ray.h_x - \
						data->player.pos_px.x) * \
					(data->player.ray.h_x - data->player.pos_px.x)) + \
				((data->player.ray.h_y - data->player.pos_px.y) * \
				(data->player.ray.h_y - data->player.pos_px.y)));
	else
		data->player.ray.h_distance = INT_MAX;
	if (data->player.ray.found_v)
		data->player.ray.v_distance = sqrt(((data->player.ray.v_x - \
						data->player.pos_px.x) * \
					(data->player.ray.v_x - data->player.pos_px.x)) + \
				((data->player.ray.v_y - data->player.pos_px.y) * \
				(data->player.ray.v_y - data->player.pos_px.y)));
	else
		data->player.ray.v_distance = INT_MAX;
}
