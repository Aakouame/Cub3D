/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:55:48 by akouame           #+#    #+#             */
/*   Updated: 2022/11/30 11:54:02 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void free_data(t_data *data)
{
	int i;

	i = 0;
	while(data->all_split[i])
		free(data->all_split[i++]);
	i = 0;
	while(data->all_splited[i])
		free(data->all_splited[i++]);
	free(data->all);
}

void    free_all(char **str)
{
    int    i;
    int    l;

    l = length_tab(str);
    i = 0;
    if (!str)
        return ;
    while (i < l)
    {
        free(str[i]);
        i++;
    }
    free(str);
}
