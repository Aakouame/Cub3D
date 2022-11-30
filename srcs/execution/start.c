/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:58:20 by akouame           #+#    #+#             */
/*   Updated: 2022/11/30 15:24:45 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"


void  draw2d(t_data *data)
{
	int i;

	i = 0;
	data->my_map.init = mlx_init();
	data->my_map.win = mlx_new_window ( data->my_map.init, 1800, 1800, "cub3d");
	mlx_loop(data->my_map.init);
}
