/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:05:11 by akouame           #+#    #+#             */
/*   Updated: 2021/11/21 18:33:03 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (d);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
