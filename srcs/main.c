/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/11/20 13:33:22 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_check(av[1]))
		{
			printf("good parsing ");
		}
		else
		{
			ft_putstr_fd("Check ur Map !\n", 2);
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
		return (1);
	}
	system("leaks cub3D");
	return 0;
}