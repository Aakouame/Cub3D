/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:24:26 by akouame           #+#    #+#             */
/*   Updated: 2021/12/01 15:46:07 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_size(char *t, char c)
{
	size_t	i;

	i = 0;
	while (t[i] != c && t[i] != '\0')
		i++;
	return (i);
}

void	ft_free(char **tp, size_t p)
{
	while (p > 0)
	{
		free (tp[p]);
		p--;
	}
	free (tp);
}

static char	**ft_result(char **t, char *s, char c, size_t i)
{
	size_t	j;
	size_t	p;

	p = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			t[p] = malloc((ft_size((char *)s + i, c) + 1) * sizeof(char));
			if (t[p] == NULL)
			{
				ft_free(t, p);
				return (NULL);
			}
			while (s[i] != c && s[i] != '\0')
				t[p][j++] = (char)s[i++];
			t[p++][j] = '\0';
		}
		else if (s[i] == c && s[i] != '\0')
			while (s[i] == c)
				i++;
	}
	t[p] = (NULL);
	return (t);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (s[0] != c)
		k++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			k++;
		i++;
	}
	if (k == 2)
		t = malloc(k * sizeof(char *));
	else
		t = malloc(((k + 1) * sizeof(char *)));
	if (t == NULL)
		return (NULL);
	i = 0;
	return (ft_result(t, (char *)s, c, i));
}
