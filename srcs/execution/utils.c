/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:17:21 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/16 16:06:45 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->my_map.addr + (y * data->my_map.line_length + x * \
			(data->my_map.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

unsigned int	get_pixel(int start, int y, int x, t_data *data)
{
	int	color;
	int	distance_from_y;
	int	x_offset;

	distance_from_y = y + (data->my_txt.wall_height / 2) - (HEIGHT / 2);
	x_offset = (data->x_offset / data->my_cubs_len) * data->my_txt.txt->width;
	y = ((distance_from_y) * (data->my_txt.txt->height / \
				data->my_txt.wall_height));
	color = data->my_txt.txt->arr[(data->my_txt.txt->height * y) + x_offset];
	return ((unsigned int)color);
}

int	init_mlx(t_data *data)
{
	int	l;

	if (HEIGHT >= WIDTH)
		l = HEIGHT;
	else
		l = WIDTH;
	if (data->max.x > data->max.y)
		data->my_cubs_len = l / data->max.x;
	else
		data->my_cubs_len = l / data->max.y;
	data->my_map.init = mlx_init();
	data->my_map.win = mlx_new_window(data->my_map.init, WIDTH, HEIGHT, \
			"cub3d");
	data->my_map.img = mlx_new_image(data->my_map.init, WIDTH, HEIGHT);
	data->my_map.addr = mlx_get_data_addr(data->my_map.img, \
			&data->my_map.bits_per_pixel, &data->my_map.line_length, \
			&data->my_map.endian);
	if (!data->my_map.addr)
		return (1);
	return (0);
}

int	get_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_weight(char	**str)
{
	int	big_len;
	int	i;

	big_len = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > big_len)
			big_len = ft_strlen(str[i]);
		i++;
	}
	return (big_len);
}
