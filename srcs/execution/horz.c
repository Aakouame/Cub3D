/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:07:29 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/15 19:32:57 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	fill_horz_inter(t_data *data, double *x, double *y)
{
	data->player.ray.h_x = *x;
	data->player.ray.h_y = *y;
	data->player.ray.found_h = 1;
}

void	init_horz_inter(t_data *data, double *y, double *x)
{
	data->player.ray.found_h = 0;
	*y = floor(data->player.pos_px.y / \
			data->my_cubs_len) * data->my_cubs_len;
	if (is_down(data))
		*y += data->my_cubs_len;
	*x = data->player.pos_px.x + ((*y - \
				data->player.pos_px.y) / tan(data->player.ray_angle));
}

void	init_horz_steps(t_data *data, double *y, double *x)
{
	*y = data->my_cubs_len;
	if (is_up(data))
		*y *= -1;
	*x = data->my_cubs_len / tan(data->player.ray_angle);
	if (is_left(data) && *x > 0)
		*x *= -1;
	if (is_right(data) && *x < 0)
		*x *= -1;
}

void	cast_horz(t_data	*data)
{
	double	first_x_inter;
	double	first_y_inter;
	double	y_step;
	double	x_step;
	double	check[2];

	normalize_rayangle(data);
	init_horz_inter(data, &first_y_inter, &first_x_inter);
	init_horz_steps(data, &y_step, &x_step);
	check[0] = first_y_inter;
	check[1] = first_x_inter;
	if (is_up(data))
		check[0]--;
	while (((check[1] >= 0 && check[1] < ((data->max.x * data->my_cubs_len)) \
		&& (check[0] >= 0 && check[0] < (data->max.y * data->my_cubs_len)))))
	{
		if (is_wall(data, check[0], check[1]))
			return (fill_horz_inter(data, &first_x_inter, &first_y_inter));
		check[0] += y_step;
		check[1] += x_step;
		first_x_inter += x_step;
		first_y_inter += y_step;
	}
}
