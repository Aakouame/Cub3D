/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:04:35 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 18:40:27 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_init(t_data *data)
{
	data->check.ea = 0;
	data->check.no = 0;
	data->check.so = 0;
	data->check.we = 0;
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
	int		fd;
	char	*mok;

	tmp = ft_strtrim(line, " \t");
	if (!strncmp(tmp, find, size))
	{
		mok = tmp + size;
		free(tmp);
		tmp = ft_strtrim(mok, " ");
		*txtr = ft_strdup(tmp);
		fd = open(*txtr, O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error : Textures files doesn't exist", 2);
			free(tmp);
			exit(2);
		}
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

void	ft_read_h(char *line, int fd, t_data *data, char *mok)
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
