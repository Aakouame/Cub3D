/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:44:03 by akouame           #+#    #+#             */
/*   Updated: 2021/11/11 22:57:32 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] != (unsigned char)c)
		return (NULL);
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (s[i] != (unsigned char)c)
		i--;
	t = (char *)s + i;
	return (t);
}
