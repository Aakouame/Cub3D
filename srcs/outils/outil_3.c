/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:48:48 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 21:10:11 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

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
