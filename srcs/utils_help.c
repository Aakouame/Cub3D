/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:16:49 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 18:37:59 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_wall_h(t_data *data, int x, int y, t_cord r)
{
	if (r.x == 1 && r.y == -1)
		if (data->my_map.map_splited[y][x - 1] == '1'\
			&& data->my_map.map_splited[y + 1][x] == '1')
			return (1);
	if (r.x == -1 && r.y == -1)
		if (data->my_map.map_splited[y][x + 1] == '1'\
			&& data->my_map.map_splited[y + 1][x] == '1')
			return (1);
	if (r.x == 1 && r.y == 1)
		if (data->my_map.map_splited[y][x - 1] == '1'\
			&& data->my_map.map_splited[y - 1][x] == '1')
			return (1);
	if (r.x == -1 && r.y == 1)
		if (data->my_map.map_splited[y - 1][x] == '1'\
			&& data->my_map.map_splited[y][x + 1] == '1')
			return (1);
	return (0);
}

int	check_wall(t_data *data, int x, int y)
{
	t_cord	r;
	t_cord	p;

	p.x = data->player.pos_px.x / data->my_cubs_len;
	p.y = data->player.pos_px.y / data->my_cubs_len;
	x = (x / data->my_cubs_len);
	r.x = x - p.x;
	y = (y / data->my_cubs_len);
	r.y = y - p.y;
	if (data->my_map.map_splited[y][x] != '0')
		return (1);
	if (check_wall_h(data, x, y, r))
		return (1);
	return (0);
}

unsigned long	creatergb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

unsigned long	get_cieling(t_data *data)
{
	unsigned long	number;

	number = creatergb(data->color.tab_c[0], \
			data->color.tab_c[1], data->color.tab_c[2]);
	return (number);
}

unsigned long	get_floor(t_data *data)
{
	unsigned long	number;

	number = creatergb(data->color.tab_f[0], \
			data->color.tab_f[1], data->color.tab_f[2]);
	return (number);
}
