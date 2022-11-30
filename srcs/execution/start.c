/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:58:20 by akouame           #+#    #+#             */
/*   Updated: 2022/11/30 16:44:44 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"
int my_cubs_len = 50;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->my_map.addr + (y * data->my_map.line_length + x * (data->my_map.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  init_mlx(t_data *data)
{
	data->my_map.init = mlx_init();
	data->my_map.win = mlx_new_window ( data->my_map.init, 700, 700, "cub3d");
	data->my_map.img = mlx_new_image(data->my_map.init,700,700);
	data->my_map.addr = mlx_get_data_addr(data->my_map.img, &data->my_map.bits_per_pixel, &data->my_map.line_length,&data->my_map.endian);
}


void dda(int X0, int Y0, int X1, int Y1,t_data *data)
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
        my_mlx_pixel_put(data,round(X), round(Y),0xff00ff); // put pixel at (X,Y)
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

void draw2d(t_data *data)
{
	int y;
	int x; 

	data->max.y = get_height(data->my_map.map_splited);
	data->max.x = get_weight(data->my_map.map_splited);
	y = 0;
	//printf("y %d  x %d\n",data->max.y,data->max.x);
	while(y < data->max.y)
	{
		x = 0;
		while(x < data->max.x)
		{
			if (x != data->max.x)
				dda(x,x + 1,y,y,data);
			if (y != data->max.y)
				dda(x,x,y,y +1,data);
			x++;
		}
		printf("\n");
		y++;
	}
}

