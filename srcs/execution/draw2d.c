/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:58:20 by akouame           #+#    #+#             */
/*   Updated: 2022/12/02 16:34:26 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"
int my_cubs_len = 32;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->my_map.addr + (y * data->my_map.line_length + x * (data->my_map.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  init_mlx(t_data *data)
{
	data->my_map.init = mlx_init();
	data->my_map.win = mlx_new_window ( data->my_map.init, 2560, 1440, "cub3d");
	data->my_map.img = mlx_new_image(data->my_map.init,2560,1440);
	data->my_map.addr = mlx_get_data_addr(data->my_map.img, &data->my_map.bits_per_pixel, &data->my_map.line_length,&data->my_map.endian);
}


void dda(int X0, int Y0, int X1, int Y1,t_data *data,int color)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put(data,round(X), round(Y),color); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

int get_height(char **str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int get_weight(char **str)
{
	int big_len;
	int i;

	big_len = 0;
	i = 0;
	while(str[i])
	{
		if (ft_strlen(str[i]) > big_len)
			big_len = ft_strlen(str[i]);
		i++;
	}
	return (big_len);
}

void drawcub(t_data *data , int x , int y,unsigned int color)
{
	int x0 = x * my_cubs_len;
	int x1 = (x + 1) * my_cubs_len;
	int y0 = y * my_cubs_len;
	int y1 = (y + 1) * my_cubs_len;
	while(y0 < y1)
	{
		dda(x0,y0,x1,y0,data,color);
		y0++;
	}
}

void init_player(t_data *data)
{
	if (data->player.p == 'E')
		data->player.fi = 0;
	if (data->player.p == 'S')
		data->player.fi = (3 * M_PI) / 2;
	if (data->player.p == 'W')
		data->player.fi = M_PI;
	if (data->player.p == 'N')
		data->player.fi =  M_PI / 2;
	data->player.pos_px.x = (data->player.pos_mp.x * my_cubs_len) + my_cubs_len/2;
	data->player.pos_px.y = (data->player.pos_mp.y * my_cubs_len) + my_cubs_len/2;

	my_mlx_pixel_put(data, roundf(data->player.pos_px.x), roundf(data->player.pos_px.y),0xffffff);
}

void draw_map(t_data *data)
{
	int y;
	int x;

	data->max.y = get_height(data->my_map.map_splited);
	data->max.x = get_weight(data->my_map.map_splited);
	y = 0;
	while(y < data->max.y)
	{
		x = 0;
		while(x < data->max.x)
		{
			if (data->my_map.map_splited[y][x] == ' ')
				drawcub(data,x,y,0x000000);
			else if (data->my_map.map_splited[y][x] == '1')
				drawcub(data,x,y,0x124A2A);
			else if (data->my_map.map_splited[y][x] == '0')
				drawcub(data,x,y,0x475E6B);
			x++;
		}
		y++;
	}
}
