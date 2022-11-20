/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:35:54 by akouame           #+#    #+#             */
/*   Updated: 2021/11/06 17:47:35 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (i >= dstsize)
		j = j + dstsize;
	else
		j = i + j;
	if (dstsize == 0)
		return (j);
	while (src[k] && i < (dstsize - 1))
	{
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (j);
}
