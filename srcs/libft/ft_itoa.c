/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:59:43 by akouame           #+#    #+#             */
/*   Updated: 2021/11/19 17:25:12 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lent(long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(int i)
{
	int	a;

	a = 1;
	while (i > 0)
	{
		a = a * 10;
		i--;
	}
	return (a);
}

static char	*ft_result(int lent, long n, char *t)
{
	int	j;

	j = 0;
	if (n > 0)
	{
		t = malloc (lent + 1);
		if (t == NULL)
			return (NULL);
	}
	else
	{
		t = malloc (lent + 2);
		if (t == NULL)
			return (NULL);
		t[j] = '-';
		j++;
		n = -n;
	}
	while (lent > 0)
	{
		t[j++] = (char)(n / ft_power(lent - 1) + '0');
		n = n % ft_power((lent--) - 1);
	}
	t[j] = '\0';
	return (t);
}

char	*ft_itoa(int n)
{
	int		lent;
	char	*t;
	long	p;

	p = n;
	t = NULL;
	lent = ft_lent(p);
	if (p == 0)
	{
		t = malloc (2);
		if (t == NULL)
			return (NULL);
		t[0] = (char) '0';
		t[1] = '\0';
		return (t);
	}
	t = ft_result(lent, p, t);
	return (t);
}
