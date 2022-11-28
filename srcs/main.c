/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/11/28 14:15:56 by akouame          ###   ########.fr       */
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
			printf("good parsing \n");
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
	
	// printf("c = %d,%d,%d\n", data.color.tab_c[0],data.color.tab_c[1],data.color.tab_c[2]);
	// printf("f = %d,%d,%d\n", data.color.tab_f[0],data.color.tab_f[1],data.color.tab_f[2]);
	// printf("%s\n%s\n%s\n%s\n", data.txtrs.ea, data.txtrs.no, data.txtrs.so, data.txtrs.we);
	return 0;
}