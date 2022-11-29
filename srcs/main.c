/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/11/29 19:15:56 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			fill_map(&data);
			int i = 0;
			while(data.my_map.map_splited[i])
			{
				printf("%s\n",data.my_map.map_splited[i]);
				i++;
			}
		}
		else
		{
			ft_er_msg(data.msg);
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
		return (1);
	}
	return 0;
}
