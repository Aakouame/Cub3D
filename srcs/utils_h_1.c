/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_h_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:46:31 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 19:10:39 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_walls_hh(t_data *data, char c)
{
	if (c == 'W')
	{
		data->j = data->player.pos_px.y + \
				data->player.step_m * sin(data->player.fi);
		data->i = data->player.pos_px.x + \
					data->player.step_m * cos(data->player.fi);
	}
	else if (c == 'S')
	{
		data->j = data->player.pos_px.y - \
				data->player.step_m * sin(data->player.fi);
		data->i = data->player.pos_px.x - \
				data->player.step_m * cos(data->player.fi);
	}
	else if (c == 'D')
	{
		data->i = data->player.pos_px.x - \
				data->player.step_m * sin(data->player.fi);
		data->j = data->player.pos_px.y + \
				data->player.step_m * cos(data->player.fi);
	}
}

int	check_walls(t_data *data, char c)
{
	data->j = 0;
	data->i = 0;
	check_walls_hh(data, c);
	if (c == 'A')
	{
		data->i = data->player.pos_px.x + \
				data->player.step_m * sin(data->player.fi);
		data->j = data->player.pos_px.y - \
				data->player.step_m * cos(data->player.fi);
	}
	if (check_wall(data, data->i, data->j))
		return (1);
	data->i = data->i / data->my_cubs_len;
	data->j = data->j / data->my_cubs_len;
	if (data->my_map.map_splited[data->j][data->i] == '1')
		return (1);
	return (0);
}
