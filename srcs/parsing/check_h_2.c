/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:13:30 by akouame           #+#    #+#             */
/*   Updated: 2022/11/29 13:03:49 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_check_map(t_data *data)
{
	t_cord	indx;
	char	**t;
	
	t = data->all_split;
	indx.y = ft_indix_start(data) + 1;
	data->map.indx.y = ft_indix_start(data)+ 1;
	while (t[indx.y])
	{
		indx.x = 0;
		while (t[indx.y][indx.x])
		{
			if (!ft_search("0NSEW", t[indx.y][indx.x]))
			{
				if (ft_search("01NSEW",t[indx.y][indx.x + 1]) ||\
					ft_search("01NSEW",t[indx.y][indx.x - 1]))
					return (1);
				if (ft_search("01NSEW",t[indx.y + 1][indx.x]) ||\
					ft_search("01NSEW",t[indx.y - 1][indx.x]))
					return (1);
			}
			indx.x++;
		}
			indx.y++;
	}
	return (0);	
}