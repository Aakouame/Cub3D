/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:59:42 by akouame           #+#    #+#             */
/*   Updated: 2022/11/29 18:59:22 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	check_range_color(char *color, int *tb)
{
	int		i;
	char	**clr_splited;
	int		j;
	
	j = 0;
	if (!color)
		return (1);
	if (h_m_repeated(color, ',') != 2)
		return (1);
	clr_splited = ft_split(color, ',');
	if (!clr_splited)
		return (1);
	i = 0;
	while (clr_splited[i])
		i++;
	if (i != 3)
	{
		free_all(clr_splited);
		return (1);
	}
	i = 0;
	while (clr_splited[i])
	{
		tb[i] = ft_atoi(clr_splited[i]);
		if (is_number(clr_splited[i]))
			j = 1;
		if (tb[i] > 255 || tb[i] < 0)
			j = 1;	
		i++;
	}
	free_all(clr_splited);
	return (j);
}

int check_color(char **splited, t_data *data)
{
	int i;

	data->check.c = 0;
	data->check.f = 0;
	i = 0;
	if (!splited)
		return (1);
	while (splited[i])
	{
		if (!ft_check_exist(splited[i], "F ", &data->color.c, 2))
			data->check.f++;
		else if (!ft_check_exist(splited[i], "C ", &data->color.f, 2))
			data->check.c++;
		i++;
	}
	if (data->check.c != 1 || data->check.f != 1)
		return (1);
	if (check_range_color(data->color.c, data->color.tab_c))
		return (1);
	if (check_range_color(data->color.f, data->color.tab_f))
		return (1);
	return 0;
}

int	check_exist_map(char **splited, t_data *data)
{
	int	i;
	int	j;
	
	i = 6;
	data->my_map.fr_space = 0;
	data->my_map.wall = 0;
	data->my_map.p = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == '1')
				data->my_map.wall++;
			else if (splited[i][j] == 'N' || splited[i][j] == 'S'\
					|| splited[i][j] == 'W' || splited[i][j] == 'E')
				data->my_map.p++;
			j++;
		}	
		i++;
	}
	if ((data->my_map.wall > 0) && (data->my_map.p == 1))
		return (0);
	return (1);
}

int	check_map(char **splited, t_data *data)
{
	int	i;
	int	j;
	
	if (check_exist_map(splited, data))
		return (1);
	i = 6;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (ft_search("01NSEW \n", splited[i][j]))
				return (1);
			j++;
		}	
		i++;
	}
	if (ft_check_map(data))
		return (1);
	return (0);
}
