/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:24:55 by akouame           #+#    #+#             */
/*   Updated: 2022/11/22 15:24:36 by akouame          ###   ########.fr       */
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

int	ft_check_exist(char *line, char *find, char **txtr)
{
	char	*tmp;
	
	tmp = ft_strtrim(line, " \t");
	if (!strncmp(tmp, find, 3))
	{
			tmp = tmp + 3;
			tmp = ft_strtrim(line, " \t");
			*txtr = ft_strdup(tmp);
			free(tmp);
			return (0);
	}
	free(tmp);
	return (1);
}

int ft_check_textures(char **splited, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!splited)
		return (1);
	while (splited[i])
	{
		if (!ft_check_exist(splited[i], "NO ", &data->txtrs.no))
			j++;
		else if (!ft_check_exist(splited[i], "SO ", &data->txtrs.so))
			j++;
		else if (!ft_check_exist(splited[i], "WE ", &data->txtrs.we))
			j++;
		else if (!ft_check_exist(splited[i], "EA ", &data->txtrs.ea))
			j++;
		i++;
	}
	if (j == 4)
		return (0);
	return (1);
}

int	ft_check(char *file, t_data *data)
{
	int		i;
	char	*all;
	char	**all_splited;
	
	i = 0;
	if (ft_check_file(file))
		return (1);
	all = ft_read(file); // read all the file 
	all_splited = ft_split(all, '\n');  // leaks !
	if (ft_check_textures(all_splited, data))
	{
		free(all);
		return (1);
	}

		free(all);
	return (0);
}
