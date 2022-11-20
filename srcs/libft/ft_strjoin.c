/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:55:27 by akouame           #+#    #+#             */
/*   Updated: 2021/11/21 17:41:54 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	t = NULL;
	t = malloc (((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = ft_strlen(s1);
	while (j < i)
	{
		t[j] = (char)s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
	{
		t[i++] = (char)s2[j];
		j++;
	}
	t[i] = '\0';
	return (t);
}
