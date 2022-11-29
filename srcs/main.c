/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:23:13 by akouame           #+#    #+#             */
/*   Updated: 2022/11/29 19:10:46 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_all(char **str)
{
	int	i;
	int	l;

	l = 0;
	while (str[l])
		l++;
	i = 0;
	while (i < l)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 2)
	{
		if (!ft_check(av[1], &data))
		{
			printf("good parsing \n");
			//execution
		}
		else
		{
			ft_er_msg(data.msg);
			system("leaks cub3D");
			return (2);
		}
	}
	else
	{
		ft_putstr_fd("Check ur number of arguments !\n", 2);
	system("leaks cub3D");
		return (1);
	}
									free(data.txtrs.ea);
									free(data.txtrs.no);
									free(data.txtrs.so);
									free(data.txtrs.we);
									free(data.color.c);
									free(data.color.f);
	system("leaks cub3D");
	return 0;
}