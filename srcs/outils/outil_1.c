/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:11:52 by akouame           #+#    #+#             */
/*   Updated: 2022/11/28 20:34:30 by akouame          ###   ########.fr       */
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

int ft_indix_start(t_data *data)
{
    int     i[5];
    int     r;
    int     j;

    j = 1;
    i[0] = ft_search_indice(data->all_split, "C ", 2);
    i[1] = ft_search_indice(data->all_split, "F ", 2);
    i[2] = ft_search_indice(data->all_split, "EA ", 3);
    i[3] = ft_search_indice(data->all_split, "WE ", 3);
    i[4] = ft_search_indice(data->all_split, "SO ", 3);
    i[5] = ft_search_indice(data->all_split, "NO ", 3);
    r = i[0];
    while (j < 6)
    {
        if (r < i[j])
            r = i[j];
        j++;
    }
    return (r);
}

int ft_search_indice(char  **str, char *s, int size)
{
    int     i;
    char    *tmp;
    int     j;

    j = 0;
    i = 0;
    while (str[i])
    {
        tmp = ft_strtrim(str[i], " ");
        if (!ft_strncmp(str[i], s, size))
            j = i;
        i++;
        free(tmp);
    }
    return (j);
}