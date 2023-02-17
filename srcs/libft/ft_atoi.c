/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:19:32 by akouame           #+#    #+#             */
/*   Updated: 2021/11/16 12:08:32 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\f' || c == '\v' || c == '\r');
}

static long int	ft_result(const char	*str, int i)
{
	long int	r;

	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	int			k;

	i = 0;
	s = 1;
	k = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
		k++;
	}
	if (k > 1)
		return (0);
	return (ft_result(str, i) * s);
}
