/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:54:03 by akouame           #+#    #+#             */
/*   Updated: 2021/11/27 11:42:52 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	i;
	size_t	ls1;
	size_t	k;

	k = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	ls1 = ft_strlen(s1);
	while (ft_verif(s1[i], set) && s1[i])
		i++;
	if (i == ls1)
		return (ft_strdup(""));
	while (ft_verif(s1[ls1 - 1], set) && s1[ls1 - 1])
		ls1--;
	cpy = malloc(ft_strlen(s1)-(ft_strlen(s1) - ls1) - i + 1);
	if (cpy == NULL)
		return (NULL);
	k = 0;
	while (i < ls1)
		cpy[k++] = s1[i++];
	cpy[k] = '\0';
	return (cpy);
}
