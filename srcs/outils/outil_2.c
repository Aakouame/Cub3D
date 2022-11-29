/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:31 by akouame           #+#    #+#             */
/*   Updated: 2022/11/29 13:43:11 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	h_m_repeated(char	*str, int c)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	is_number(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_spc(char **str)
{
	int i;
	int	l;
	int	j;
	
	i = 0;
	l = ft_strlen(str[i]);
	while (str[i])
	{
		if(ft_strlen(str[i]) > l)
			l = ft_strlen(str[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) < l)
		{
			j = 0;
			while (j < l)
			{
				while (str[i][j])
					j++;
				str[i] = ft_strjoin(str[i], ft_strdup(" "));
				j++;
			}
		}
		i++;
	}
	j = 0;
	while (j < l)
	{
		str[i] = ft_strjoin(str[i], ft_strdup(" "));
		j++;
	}
	str[i+1] = NULL;
}

