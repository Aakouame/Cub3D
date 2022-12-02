/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/12/02 17:33:33 by yaskour          ###   ########.fr       */
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
	else if (key_code == 124)
	{
		data->player.fi -= data->player.step_r;
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	else if (key_code == 123)
	{
		data->player.fi += data->player.step_r;
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	else if (key_code == 13) // w
	{
		data->player.pos_px.y += data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x += data->player.step_m * cos(data->player.fi);
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	else if (key_code == 1)
	{
		data->player.pos_px.y -= data->player.step_m * sin(data->player.fi);
		data->player.pos_px.x -= data->player.step_m * cos(data->player.fi);
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	else if (key_code == 0)
	{
		data->player.pos_px.x -= data->player.step_m + cos(data->player.fi);
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	else if (key_code == 2)
	{
		data->player.pos_px.x += data->player.step_m + cos(data->player.fi);
		mlx_clear_window(data->my_map.init,data->my_map.win);
		draw_map(data);
	}
	mlx_put_image_to_window(data->my_map.init, data->my_map.win, data->my_map.img, 0, 0);
	printf("%d\n",key_code);
	return (0);
}
int main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			//printf("good parsing\n");
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
			// system("leaks cub3D");
		return (1);
	}
			// system("leaks cub3D");
	return 0;
}
