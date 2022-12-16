/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 15:36:18 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_exit(t_data	data)
{	
	(void) data;
	exit(0);
	return (0);
}

int	check_wall_h(t_data *data, int x, int y, t_cord r)
{
	if (r.x == 1 && r.y == -1)
	{
		if (data->my_map.map_splited[y][x - 1] == '1'\
			&& data->my_map.map_splited[y + 1][x] == '1')
			return (1);
	}
	if (r.x == -1 && r.y == -1)
	{
		if (data->my_map.map_splited[y][x + 1] == '1'\
			&& data->my_map.map_splited[y + 1][x] == '1')
			return (1);
	}
	if (r.x == 1 && r.y == 1)
	{
		if (data->my_map.map_splited[y][x - 1] == '1'\
			&& data->my_map.map_splited[y - 1][x] == '1')
			return (1);
	}
	if (r.x == -1 && r.y == 1)
	{
		if (data->my_map.map_splited[y - 1][x] == '1'\
			&& data->my_map.map_splited[y][x + 1] == '1')
			return (1);
	}
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

int	check_walls(t_data *data, char c)
{
	data->j = 0;
	data->i  = 0;
	if (c == 'W')
	{
		data->j  = data->player.pos_px.y + \
				data->player.step_m * sin(data->player.fi);
		data->i  = data->player.pos_px.x + \
					data->player.step_m * cos(data->player.fi);
	}
	else if (c == 'S')
	{
		data->j  = data->player.pos_px.y - \
				data->player.step_m * sin(data->player.fi);
		data->i  = data->player.pos_px.x - \
				data->player.step_m * cos(data->player.fi);
	}
	else if (c == 'D')
	{
		data->i  = data->player.pos_px.x - \
				data->player.step_m * sin(data->player.fi);
		data->j  = data->player.pos_px.y + \
				data->player.step_m * cos(data->player.fi);
	}
	else if (c == 'A')
	{
		data->i  = data->player.pos_px.x + \
				data->player.step_m * sin(data->player.fi);
		data->j = data->player.pos_px.y - \
				data->player.step_m * cos(data->player.fi);
	}
	if (check_wall(data, data->i , data->j ))
		return (1);
	data->i  = data->i  / data->my_cubs_len;
	data->j  = data->j  / data->my_cubs_len;
	if (data->my_map.map_splited[data->j ][data->i ] == '1')
		return (1);
	return (0);
}

int	ft_key_hook(int key_code, t_data *data)
{
	data->key = key_code;
	if (key_code == 53)
		exit(0);
	mlx_clear_window(data->my_map.init, data->my_map.win);
	if (key_code == 124)
	{
		data->player.fi += data->player.step_r;
		normalize_angle(data);
	}
	else if (key_code == 123)
	{
		data->player.fi -= data->player.step_r;
		normalize_angle(data);
	}
	else if (key_code == 13)
	{
		if (!check_walls(data, 'W'))
		{
			data->player.pos_px.y += data->player.step_m * sin(data->player.fi);
			data->player.pos_px.x += data->player.step_m * cos(data->player.fi);
		}
	}
	else if (key_code == 1)
	{
		if (!check_walls(data, 'S'))
		{
		data->player.pos_px.y -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x -= data->player.step_m * cos(data->player.fi);
		}
	}
	else if (key_code == 0)
	{
		if (!check_walls(data, 'A'))
		{
		data->player.pos_px.x += data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y -= data->player.step_m * cos(data->player.fi);
		}
	}
	else if (key_code == 2)
	{
		if (!check_walls(data, 'D'))
		{
		data->player.pos_px.x -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y += data->player.step_m * cos(data->player.fi);
		}
	}
	draw_map(data);
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			if (init_mlx(&data))
			{
		system("leaks cub3D");

				return (1);
			}
			fill_map(&data);
			init_player(&data);
			draw_map(&data);
			mlx_hook(data.my_map.win, 17, 1L << 0, ft_exit, &data);
			mlx_hook(data.my_map.win, 2, 0L, ft_key_hook, &data);
			mlx_loop(data.my_map.init);
		}
		else
		{
			ft_er_msg(data.msg);		
		system("leaks cub3D");
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
		system("leaks cub3D");
		return (1);
	}
			
		system("leaks cub3D");
	return (0);
}
