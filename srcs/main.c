/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/11/30 14:22:37 by akouame          ###   ########.fr       */
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
			printf("good parsing\n");
			fill_map(&data);
			// execution(&data)
			// system("leaks cub3D");
		}
		else
		{
			ft_er_msg(data.msg);
			// system("leaks cub3D");
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
			// system("leaks cub3D");
		return (1);
	}
			// system("leaks cub3D");
	return 0;
}
