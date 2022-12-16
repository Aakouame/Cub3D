/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:31 by akouame           #+#    #+#             */
/*   Updated: 2022/12/16 17:07:49 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	h_m_repeated(char	*str, int c)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_spc_h(char **str, t_data *data, int l)
{
	while (str[data->i])
	{
		if (ft_strlen(str[data->i]) < l)
		{
			data->j = ft_strlen(str[data->i]);
			while (data->j != l)
			{
				// while (str[data->i][data->j])
				// 	data->j++;
				str[data->i] = ft_strjoin(str[data->i], " ");
				data->j++;
			}
		}
		data->i++;
	}
	data->j = 0;
	// while (data->j < l)
	// {
	// 	str[data->i] = ft_strjoin(str[data->i], " ");
	// 	data->j++;
	// }
	// str[data->i + 1] = NULL;
}

void	ft_add_spc(char **str, t_data *data)
{
	int	l;

	data->i = 0;
	data->j = 0;
	l = ft_strlen(str[data->i]);
	while (str[data->i])
	{
		if (ft_strlen(str[data->i]) > l)
			l = ft_strlen(str[data->i]);
		data->i++;
	}
	data->max.x = l;
	data->i = 0;
	ft_add_spc_h(str, data, l);
}
