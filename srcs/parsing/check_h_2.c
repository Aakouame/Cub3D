/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:13:30 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 15:58:24 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map_h(char **t, t_cord *indx, t_data *data)
{
	indx->x = 0;
	while (t[indx->y][indx->x])
	{
		if (!ft_search("0NSEW", t[data->max.y - 1][indx->x]))
			return (1);
		if (!ft_search("0NSEW", t[indx->y][indx->x]))
		{
			if ((indx->x < data->max.x) && (indx->x >= 0))
				if (ft_search("01NSEW", t[indx->y][indx->x + 1]) || \
					ft_search("01NSEW", t[indx->y][indx->x - 1]))
					return (1);
			if (((indx->y + 1) < data->max.y) && (indx->y >= 0))
				if (ft_search("01NSEW", t[indx->y + 1][indx->x]) || \
					ft_search("01NSEW", t[indx->y - 1][indx->x]))
					return (1);
		}
		indx->x++;
	}
	if (check_empty_line(t[indx->y]))
		return (1);
	return (0);
}

int	ft_check_map(t_data *data)
{
	t_cord	indx;
	char	**t;

	ft_add_spc(data->all_split, data);
	t = data->all_split;
	indx.y = ft_indix_start(data) + 1;
	data->max.y = length_tab(t);
	data->my_map.indx.y = ft_indix_start(data)+ 1;
	while (check_empty_line(t[indx.y]))
		indx.y++;
	while (t[indx.y])
	{
		if (ft_check_map_h(t, &indx, data))
			return (1);
		indx.y++;
	}
	return (0);
}
