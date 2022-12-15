/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:24:55 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 18:36:09 by akouame          ###   ########.fr       */
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

void	ft_read_h(char *line , int fd, t_data *data, char *mok)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mok = ft_substr(line, 0, (ft_strlen(line) - 1));
		data->all_split = add_str(data->all_split, mok);
		free (mok);
		data->all = ft_strjoin(data->all, line);
		free(line);
	}
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

int	ft_check_exist(char *line, char *find, char **txtr, int size)
{
	char	*tmp;
	char	*mok;

	tmp = ft_strtrim(line, " \t");
	if (!strncmp(tmp, find, size))
	{
			mok = tmp + size;
			free(tmp);
			tmp = ft_strtrim(mok, " ");
			*txtr = ft_strdup(tmp);
			free(tmp);
			return (0);
	}
	free(tmp);
	return (1);
}

int	ft_check_exist_textures(char *line, char *find, char **txtr, int size)
{
	char	*tmp;
	int fd;
	char	*mok;
	
	tmp = ft_strtrim(line, " \t");
	if (!strncmp(tmp, find, size))
	{
			mok = tmp + size;
			free(tmp);
			tmp = ft_strtrim(mok, " ");
			*txtr = ft_strdup(tmp);
			fd = open(*txtr,O_RDONLY);
			if (fd < 0)
			{
				ft_putstr_fd("Error : Textures files doesn't exist",2);
				free(tmp);
				exit(2);
			}
			free(tmp);
			return (0);
	}
	free(tmp);
	return (1);
}

int check_textures(char **splited, t_data *data)
{
	int		i;
	
	i = 0;
	data->check.ea = 0;
	data->check.no = 0;
	data->check.so = 0;
	data->check.we = 0;
	if (!splited)
		return (1);
	while (splited[i])
	{
		if (!ft_check_exist_textures(splited[i], "NO ", &data->txtrs.no, 3))
			data->check.no++;
		else if (!ft_check_exist_textures(splited[i], "SO ", &data->txtrs.so, 3))
			data->check.so++;
		else if (!ft_check_exist_textures(splited[i], "WE ", &data->txtrs.we, 3))
			data->check.we++;
		else if (!ft_check_exist_textures(splited[i], "EA ", &data->txtrs.ea, 3))
			data->check.ea++;
		i++;
	}
	if (data->check.no != 1 || data->check.so != 1 || data->check.we != 1\
			|| data->check.ea != 1)
		return (1);
	return (0);
}

int	ft_check(char *file, t_data *data)
{
	int		i;

	i = 0;
	if (check_file(file))
	{
		data->msg = "Check ur file name !";
		return (1);
	}
	data->all = ft_read(file, data); // read all the file 
	if (!data->all)
	{
		data->msg = "Empty File !";
		return (1);
	}
	data->all_splited = ft_split(data->all, '\n'); // leaks !
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
