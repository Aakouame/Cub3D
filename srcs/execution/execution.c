/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:20:35 by akouame           #+#    #+#             */
/*   Updated: 2022/12/05 15:03:35 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void    draw_rz(t_data *data, double ang)
{
    t_cord_double    f;
    t_cord_double    s;
    f.y = roundf(data->player.pos_px.y) - 1;
    f.x = data->player.pos_px.x + ((f.y - data->player.pos_px.y) / tan(ang));
    s.y = f.y - 1;
    s.x = f.x + (my_cubs_len / tan(ang));
    dda(data->player.pos_px.x,data->player.pos_px.y,s.x,s.y,data,0xffffff);
}
