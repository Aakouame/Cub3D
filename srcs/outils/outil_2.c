/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:31 by akouame           #+#    #+#             */
/*   Updated: 2022/11/28 15:57:53 by akouame          ###   ########.fr       */
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

int	ft_indix_map(char	**splited)
{
	int		i;
	char	*tmp;
	
	i = 0;
	while (splited[i])
	{
		tmp = ft_strtrim(splited[i], " ");
		if (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "WE ", 3))
			i++;
		else if (!ft_strncmp(tmp, "SO ", 3) || !ft_strncmp(tmp, "EA ", 3))
			i++;
		else if (!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "C ", 2))
			i++;
		free(tmp);
	}
	return (i);
}