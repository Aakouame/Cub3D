/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:07:53 by yaskour           #+#    #+#             */
/*   Updated: 2022/12/15 21:53:17 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	load_textures(t_data *data)
{
	int		i;
	t_text	*txt[4];
	char	*ar[4];

	txt[0] = &data->r_texture;
	txt[1] = &data->l_texture;
	txt[2] = &data->b_texture;
	txt[3] = &data->f_texture;
	ar[0] = data->txtrs.we;
	ar[1] = data->txtrs.ea;
	ar[2] = data->txtrs.so;
	ar[3] = data->txtrs.no;
	i = 0;
	while (i < 4)
	{
		txt[i]->img = mlx_xpm_file_to_image(data->my_map.init, \
				ar[i], &txt[i]->width, &txt[i]->height);
		if (!txt[i]->img)
			exit(1);
		txt[i]->arr = (int *)mlx_get_data_addr(txt[i]->img, \
				&txt[i]->bpp, &txt[i]->line_length, &txt[i]->endian);
		i++;
	}
}

void	fill_map_helper(t_data *data, int *k)
{
	int	i;
	int	j;

	i = 6;
	while (data->all_splited[i])
	{
		j = 0;
		while (data->all_splited[i][j])
		{
			if (!ft_search("WSNE", data->all_splited[i][j]))
			{
				data->all_splited[i][j] = '0';
				data->player.pos_mp.y = i - 6;
				data->player.pos_mp.x = j;
			}
			j++;
		}
		data->my_map.map_splited[*k] = ft_strdup(data->all_splited[i]);
		*k += 1;
		i++;
	}
}

void	fill_map(t_data *data)
{
	int	i;
	int	k;

	i = 6;
	k = 0;
	while (data->all_splited[i])
		i++;
	data->my_map.map_splited = malloc(sizeof(char *) * i - 5);
	fill_map_helper(data, &k);
	load_textures(data);
	data->player.step_m = 3;
	data->player.step_r = M_PI / 80;
	data->my_map.map_splited[k] = NULL;
}
