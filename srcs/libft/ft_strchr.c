/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:58:02 by akouame           #+#    #+#             */
/*   Updated: 2021/11/11 22:51:10 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;
	int		j;

	j = 0;
	i = 0;
	t = NULL;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (i == 0 && s[i] != (unsigned char)c)
		return (NULL);
	if (s[i] == (unsigned char)c)
		t = (char *)s + i;
	return (t);
}
