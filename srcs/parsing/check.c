/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:24:55 by akouame           #+#    #+#             */
/*   Updated: 2022/11/20 13:34:58 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_check_file(char *name)
{
	int	i;

	i = 0;
	if (!name)
		return (1);
	while (name[i])
		i++;
	i -= 4;
	if (ft_strncmp(name + i, ".cub", 3))
		return (1);
	return (0);
}

char	*ft_read(char *file)
{
	int		fd;
	char	*all;
	char	*line;
	
	fd = open(file, O_RDONLY);
	all = NULL;
	if (fd < 0)
	{
		ft_putstr_fd("Error: open file !", 2);
		exit(2);
	}
	line = get_next_line(fd);
	free(line);
	all = ft_strdup(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		all = ft_strjoin(all, line);
		free(line);
	}
	return (all);
}

int	ft_check(char *file)
{
	int		i;
	char	*all;
	
	i = 0;
	if (ft_check_file(file))
		return (1);
	all = ft_read(file);
	free(all);
	return (0);
}
