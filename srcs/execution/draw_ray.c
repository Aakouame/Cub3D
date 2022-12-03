/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:06:06 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/03 18:14:53 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void first_horizontal_intr(t_data *data,int ang)
{
	int y = floor(data->player.pos_px.y/my_cubs_len) * my_cubs_len; 
	int x = data->player.pos_px.x + tan(ang) / (data->player.pos_px.y - y);
	dda(data->player.pos_px.x,data->player.pos_px.y,x,y,data,0xffffff);
}

void first_vertical_intr(t_data *data,int ang)
{
	int x = floor(data->player.pos_px.x / my_cubs_len) * my_cubs_len;
	int y = -(data->player.pos_px.y + tan(ang) * (x - data->player.pos_px.x));
	dda(data->player.pos_px.x,data->player.pos_px.y,x,y,data,0xffffff);
}
