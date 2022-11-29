/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:49:52 by akouame           #+#    #+#             */
/*   Updated: 2022/01/11 23:21:08 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	t = NULL;
	if (start == 0)
		t = malloc(ft_strlen(s) + 1);
	if (start != 0)
		t = malloc(len + 1);
	if (t == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		t[i] = (char)s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_free(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
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
		t[i++] = (char)s2[j++];
	t[i] = '\0';
	free(s1);
	return (t);
}
