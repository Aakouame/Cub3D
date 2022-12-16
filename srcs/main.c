/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 19:19:30 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_exit(t_data	data)
{	
	(void) data;
	exit(0);
	return (0);
}

void	ft_key_hook_h_s(int key_code, t_data *data)
{
	if (key_code == 13)
	{
		if (!check_walls(data, 'W'))
		{
			mlx_clear_window(data->my_map.init, data->my_map.win);
			data->player.pos_px.y += data->player.step_m * sin(data->player.fi);
			data->player.pos_px.x += data->player.step_m * cos(data->player.fi);
			draw_map(data);
		}
	}
	if (key_code == 1)
	{
		if (!check_walls(data, 'S'))
		{
			mlx_clear_window(data->my_map.init, data->my_map.win);
			data->player.pos_px.y -= data->player.step_m * sin(data->player.fi);
			data->player.pos_px.x -= data->player.step_m * cos(data->player.fi);
			draw_map(data);
		}
	}
}

void	ft_key_hook_h_f(int key_code, t_data *data)
{
	if (key_code == 53)
		exit(0);
	if (key_code == 124)
	{
		mlx_clear_window(data->my_map.init, data->my_map.win);
		data->player.fi += data->player.step_r;
		normalize_angle(data);
		draw_map(data);
	}
	if (key_code == 123)
	{
		mlx_clear_window(data->my_map.init, data->my_map.win);
		data->player.fi -= data->player.step_r;
		normalize_angle(data);
		draw_map(data);
	}
}

int	ft_key_hook(int key_code, t_data *data)
{
	data->key = key_code;
	ft_key_hook_h_f(key_code, data);
	ft_key_hook_h_s(key_code, data);
	if (key_code == 0)
	{
		if (!check_walls(data, 'A'))
		{
			mlx_clear_window(data->my_map.init, data->my_map.win);
			data->player.pos_px.x += data->player.step_m * sin(data->player.fi);
			data->player.pos_px.y -= data->player.step_m * cos(data->player.fi);
			draw_map(data);
		}
	}
	if (key_code == 2)
	{
		if (!check_walls(data, 'D'))
		{
			mlx_clear_window(data->my_map.init, data->my_map.win);
			data->player.pos_px.x -= data->player.step_m * sin(data->player.fi);
			data->player.pos_px.y += data->player.step_m * cos(data->player.fi);
			draw_map(data);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			if (init_mlx(&data))
				return (1);
			fill_map(&data);
			init_player(&data);
			draw_map(&data);
			mlx_hook(data.my_map.win, 17, 1L << 0, ft_exit, &data);
			mlx_hook(data.my_map.win, 2, 0L, ft_key_hook, &data);
			mlx_loop(data.my_map.init);
		}
		else
			return (ft_er_msg(data.msg));
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
		return (1);
	}
	return (0);
}
