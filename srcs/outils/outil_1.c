/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:11:52 by akouame           #+#    #+#             */
/*   Updated: 2022/11/28 15:46:16 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int ft_search(char *str, int c)
{
    int i;

    i = 0;
    if (!str)
        return (1);
    while (str[i])
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

void	ft_er_msg(char *msg)
{
	ft_putstr_fd("Error ✘: ", 2);
    if (msg)
		ft_putendl_fd(msg, 2);
}

