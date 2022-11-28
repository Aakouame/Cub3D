/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:13:30 by akouame           #+#    #+#             */
/*   Updated: 2022/11/28 21:22:29 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_check_map(t_data *data)
{
	int		i;
	t_cord	indx;
	
	indx.y = ft_indix_start(data);
	data->map.indx.y = ft_indix_start(data);
	while (data->all_split[indx.y])
	{
		data->map.indx.x = 0;
		while (data->all_split[data->map.indx.y][data->map.indx.x])
	}
	
}