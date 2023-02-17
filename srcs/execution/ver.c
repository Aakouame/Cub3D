/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:10:23 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/15 19:36:57 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_ver_inter(t_data *data, double *y, double *x)
{
	data->player.ray.found_v = 0;
	*x = floor(data->player.pos_px.x \
			/ data->my_cubs_len) * data->my_cubs_len;
	if (is_right(data))
		*x += data->my_cubs_len;
	*y = data->player.pos_px.y + ((*x \
				- data->player.pos_px.x) * tan(data->player.ray_angle));
}

void	init_ver_steps(t_data *data, double *y, double *x)
{
	*x = data->my_cubs_len;
	if (is_left(data))
		*x *= -1;
	*y = data->my_cubs_len * tan(data->player.ray_angle);
	if (is_up(data) && *y > 0)
		*y *= -1;
	if (is_down(data) && *y < 0)
		*y *= -1;
}

void	fill_ver_inter(t_data *data, double *y, double *x)
{
	data->player.ray.v_x = *x;
	data->player.ray.v_y = *y;
	data->player.ray.found_v = 1;
	return ;
}

void	cast_ver(t_data	*data)
{
	double	first_x_inter;
	double	first_y_inter;
	double	y_step;
	double	x_step;
	double	check[2];

	normalize_rayangle(data);
	init_ver_inter(data, &first_y_inter, &first_x_inter);
	init_ver_steps(data, &y_step, &x_step);
	check[0] = first_y_inter;
	check[1] = first_x_inter;
	if (is_left(data))
		check[1]--;
	while (((check[1] >= 0 && check[1] <= ((data->max.x * data->my_cubs_len) + \
1) && (check[0] >= 0 && check[0] <= (data->max.y * data->my_cubs_len) + 1))))
	{
		if (is_wall(data, check[0], check[1]))
			return (fill_ver_inter(data, &first_y_inter, &first_x_inter));
		check[0] += y_step;
		check[1] += x_step;
		first_x_inter += x_step;
		first_y_inter += y_step;
	}
}
