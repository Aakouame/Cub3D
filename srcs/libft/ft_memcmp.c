/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:48:56 by akouame           #+#    #+#             */
/*   Updated: 2021/11/07 15:02:04 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
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
	while (a1[i] == a2[i] && i < size - 1)
	{
		i++;
	}
	return (a1[i] - a2[i]);
}
