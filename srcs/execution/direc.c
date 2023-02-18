/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:52 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/15 19:14:35 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_down(t_data	*data)
{
	if (data->player.ray_angle > 0 && data->player.ray_angle < M_PI)
		return (1);
	return (0);
}

int	is_up(t_data	*data)
{
	if (!is_down(data))
		return (1);
	return (0);
}

int	is_right(t_data	*data)
{
	if (data->player.ray_angle < (0.5 * M_PI) \
			|| data->player.ray_angle > (1.5 * M_PI))
		return (1);
	return (0);
}

int	is_left(t_data	*data)
{
	if (!is_right(data))
		return (1);
	return (0);
}

int	is_wall(t_data *data, double y, double x)
{
	int	x_map;
	int	y_map;

	x_map = floor(x / data->my_cubs_len);
	if (x_map < 0)
		x_map = 0;
	y_map = floor(y / data->my_cubs_len);
	if (y_map < 0)
		y_map = 0;
	if (y_map > data->max.y)
		y_map = data->max.y;
	if (x_map > data->max.x)
		x_map = data->max.x;
	if (y >= (data->max.y * data->my_cubs_len))
		return (1);
	if (data->my_map.map_splited[y_map][x_map] == '1')
		return (1);
	return (0);
}
