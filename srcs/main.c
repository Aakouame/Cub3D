/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/12/02 20:12:08 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_exit(t_data data)
{	
	(void) data;
	exit(0);
	return (0);
}

int	ft_key_hook(int key_code, t_data *data)
{
	data->key = key_code;
	if (key_code == 53)
		exit(0);
	mlx_clear_window(data->my_map.init,data->my_map.win);
	if (key_code == 124) // right key
	{
		data->player.fi += data->player.step_r;
		data->player.fi = fmod(data->player.fi,2 * M_PI);
		if (data->player.fi < 0)
			data->player.fi += 2 * M_PI;
	}
	else if (key_code == 123) // left key
	{
		data->player.fi -= data->player.step_r;
		data->player.fi = fmod(data->player.fi,2 * M_PI);
		if (data->player.fi < 0)
			data->player.fi += 2 * M_PI;
	}
	else if (key_code == 13) // w
	{
		data->player.pos_px.y += data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x += data->player.step_m * cos(data->player.fi);
	}
	else if (key_code == 1) // S
	{
		data->player.pos_px.y -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x -= data->player.step_m * cos(data->player.fi);
	}
	else if (key_code == 0) // A
	{
		data->player.pos_px.x += data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y -= data->player.step_m * cos(data->player.fi);
	}
	else if (key_code == 2) //  D
	{
		data->player.pos_px.x -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y += data->player.step_m * cos(data->player.fi);
	}
	draw_map(data);
	mlx_put_image_to_window(data->my_map.init, data->my_map.win, data->my_map.img, 0, 0);
	return (0);
}
int main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			fill_map(&data);
			init_mlx(&data);
			init_player(&data);
			draw_map(&data);
			mlx_put_image_to_window(data.my_map.init, data.my_map.win, data.my_map.img, 0, 0);
			mlx_hook(data.my_map.win, 17, 1L << 0, ft_exit, &data);
			mlx_hook(data.my_map.win, 2, 0L, ft_key_hook, &data);
			mlx_loop(data.my_map.init);
			// system("leaks cub3D");
		}
		else
		{
			ft_er_msg(data.msg);
			// system("leaks cub3D");
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
		return (1);
	}
			// system("leaks cub3D");
	return 0;
}
