/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:04:47 by akouame           #+#    #+#             */
/*   Updated: 2021/11/21 17:26:31 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_exist(char *txt, char *find, size_t len)
{
	size_t	i;

	i = 0;
	while (find[i] && len > 0)
	{
		if (find[i] != txt[i])
			return (0);
		i++;
		len--;
		if (find[i] != '\0' && len == 0)
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *txt, const char *find, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(find) == 0)
		return ((char *)txt);
	if (ft_strlen(txt) == 0 || len == 0)
		return (NULL);
	if (len == 1 && txt[0] == find[0])
		return ((char *)txt);
	if (len == ft_strlen(find))
	{
		while (find[i] == txt[i] && find[i])
			i++;
		if (i == ft_strlen(find))
			return ((char *)txt);
		return (NULL);
	}
	i = 0;
	while (txt[i] && (len - i) - 1 > 0)
	{
		if (ft_exist((char *)(txt + i), (char *)find, (len - i)))
			return ((char *)txt + i);
		i++;
	}
	return (NULL);
}
