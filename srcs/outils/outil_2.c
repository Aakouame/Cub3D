/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:31 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 16:40:47 by akouame          ###   ########.fr       */
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
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_spc(char **str, t_data *data)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	l = ft_strlen(str[i]);
	while (str[i])
	{
		if (ft_strlen(str[i]) > l)
			l = ft_strlen(str[i]);
		i++;
	}
	data->max.x = l;
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
				str[i] = ft_strjoin(str[i], " ");
				j++;
			}
		}
		i++;
	}
	j = 0;
	while (j < l)
	{
		str[i] = ft_strjoin(str[i], " ");
		j++;
	}
	str[i + 1] = NULL;
}

int	length_tab(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**add_str(char **str, char *s)
{
	int		i;
	char	**tmp;

	if (!s)
		return (str);
	i = length_tab(str);
	tmp = malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			tmp[i] = ft_strdup(str[i]);
			i++;
		}
	}
	tmp[i] = ft_strdup(s);
	tmp[i + 1] = NULL;
	free_all(str);
	return (tmp);
}
