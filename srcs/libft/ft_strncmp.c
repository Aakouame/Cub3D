/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:41:25 by akouame           #+#    #+#             */
/*   Updated: 2021/11/11 23:08:52 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				size;
	int				i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	size = (int)n;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (size < 0)
	{
		while (a1[i] == a2[i] && a1[i])
			i++;
	}
	while (a1[i] == a2[i] && i < size - 1 && a1[i])
	{
		i++;
	}
	return (a1[i] - a2[i]);
}
