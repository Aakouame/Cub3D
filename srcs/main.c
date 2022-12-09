/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/12/09 10:25:59 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_exit(t_data data)
{	
	(void) data;
	exit(0);
	return (0);
}

int	check_wall(t_data *data,int x, int y)
{
	t_cord	r;
	t_cord	p;
	
	p.x = data->player.pos_px.x /data->my_cubs_len;
	p.y = data->player.pos_px.y/ data->my_cubs_len;
	x = (x / data->my_cubs_len);
	r.x = x - p.x;
	y = (y /data->my_cubs_len);
	r.y = y - p.y;
	if(data->my_map.map_splited[y][x] != '0')
		return (1);
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

int check_walls(t_data *data,char c)
{
	int x;
	int y;
	y = 0;
	x = 0;
	if (c == 'W')
	{
			y = data->player.pos_px.y + data->player.step_m * sin(data->player.fi);
			x = data->player.pos_px.x + data->player.step_m * cos(data->player.fi);
			if (check_wall(data, x, y))
				return (1);
	}
	else if (c == 'S')
	{
		y = data->player.pos_px.y - data->player.step_m * sin(data->player.fi);
		x = data->player.pos_px.x - data->player.step_m * cos(data->player.fi);
			if (check_wall(data, x, y))
				return (1);
	}
	else if (c == 'D')
	{
		x = data->player.pos_px.x - data->player.step_m * sin(data->player.fi);
		y = data->player.pos_px.y + data->player.step_m * cos(data->player.fi);
			if (check_wall(data, x, y))
				return (1);
	}
	else if (c == 'A')
	{
		x = data->player.pos_px.x + data->player.step_m * sin(data->player.fi);
		y = data->player.pos_px.y - data->player.step_m * cos(data->player.fi);
			if (check_wall(data, x, y))
				return (1);
	}
	x = x / data->my_cubs_len;
	y = y / data->my_cubs_len;
		printf(" OK : x = %d | y = %d\n",x,y);
		printf(" max OK : x = %d | y = %d\n",data->max.x,data->max.y);
	if (data->my_map.map_splited[y][x] == '1')
		return (1);
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
		printf("right before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		data->player.fi += data->player.step_r;
		normalize_angle(data);
		printf("right after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	else if (key_code == 123) // left key
	{
		printf("left before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		data->player.fi -= data->player.step_r;
		normalize_angle(data);
		printf("left after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	else if (key_code == 13) // w
	{
		printf("W before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		if (!check_walls(data,'W'))
		{
			data->player.pos_px.y += data->player.step_m * sin(data->player.fi);
			data->player.pos_px.x += data->player.step_m * cos(data->player.fi);
		}
		printf("W after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	else if (key_code == 1) // S
	{
		printf("S before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		if (!check_walls(data,'S'))
		{
		data->player.pos_px.y -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x -= data->player.step_m * cos(data->player.fi);
		}
		printf("S after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	else if (key_code == 0) // A
	{
		printf("A before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		if (!check_walls(data,'A'))
		{
		data->player.pos_px.x += data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y -= data->player.step_m * cos(data->player.fi);
		}
		printf("A after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	else if (key_code == 2) //  D
	{
		printf("D before : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
		if (!check_walls(data,'D'))
		{
		data->player.pos_px.x -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.y += data->player.step_m * cos(data->player.fi);
		}
		printf("D after  : x = %f | y = %f\n", data->player.pos_px.x, data->player.pos_px.y);
	}
	draw_map(data);
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
