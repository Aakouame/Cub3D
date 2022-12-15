/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:24:55 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 18:44:46 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	check_file(char *name)
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

char	*ft_read(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	char	*mok;

	i = 0;
	fd = open(file, O_RDONLY);
	mok = NULL;
	if (fd < 0)
	{
		ft_putstr_fd("Error: open file !", 2);
		exit(2);
	}
	data->all = NULL;
	data->all_split = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	data->all = ft_strdup(line);
	data->all_split = add_str(data->all_split, line);
	free(line);
	ft_read_h(line, fd, data, mok);
	return (data->all);
}

int	check_textures(char **splited, t_data *data)
{
	int		i;

	i = 0;
	if (!splited)
		return (1);
	while (splited[i])
	{
		if (!ft_check_exist_textures(splited[i], "NO ", &data->txtrs.no, 3))
			data->check.no++;
		else if (!ft_check_exist_textures(splited[i], "SO ", \
				&data->txtrs.so, 3))
			data->check.so++;
		else if (!ft_check_exist_textures(splited[i], "WE ", \
			&data->txtrs.we, 3))
			data->check.we++;
		else if (!ft_check_exist_textures(splited[i], "EA ", \
			&data->txtrs.ea, 3))
			data->check.ea++;
		i++;
	}
	if (data->check.no != 1 || data->check.so != 1 || data->check.we != 1 \
			|| data->check.ea != 1)
		return (1);
	return (0);
}

int	ft_check_file(char *file, t_data *data)
{
	if (check_file(file))
	{
		data->msg = "Check ur file name !";
		return (1);
	}
	data->all = ft_read(file, data);
	if (!data->all)
	{
		data->msg = "Empty File !";
		return (1);
	}
	return (0);
}

int	ft_check(char *file, t_data *data)
{
	ft_init(data);
	if (ft_check_file(file, data))
		return (1);
	data->all_splited = ft_split(data->all, '\n');
	if (check_textures(data->all_splited, data))
	{
		data->msg = "Check Textures !";
		return (1);
	}
	if (check_color(data->all_splited, data))
	{
		data->msg = "Check Colors !";
		return (1);
	}
	if (check_map(data->all_splited, data))
	{
		data->msg = "Check Map !";
		return (1);
	}
	return (0);
}
