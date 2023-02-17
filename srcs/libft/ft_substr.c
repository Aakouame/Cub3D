/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:24:27 by akouame           #+#    #+#             */
/*   Updated: 2021/11/27 11:47:04 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
