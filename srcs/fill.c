#include "../include/cub.h"

void fill_map(t_data *data)
{
	int i = 6;
	int	j;


	while(data->all_splited[i])
		i++;
	j = 0;
	data->my_map.map_splited = malloc(sizeof(char *) * i - 5);
	i = 6;
	while(data->all_splited[i])
	{
		data->my_map.map_splited[j] = ft_strdup(data->all_splited[i]);
		i++;
		j++;
	}
	data->my_map.map_splited[i] = NULL;
}

void free_data(t_data *data)
{
	int i;

	i = 0;
	while(data->all_split[i])
		free(data->all_split[i++]);
	i = 0;
	while(data->all_splited[i])
		free(data->all_splited[i++]);
	free(data->all);
}

void    free_all(char **str)
{
    int    i;
    int    l;

    l = 0;
    while (str[l])
        l++;
    i = 0;
    while (i < l)
    {
        free(str[i]);
        i++;
    }
    free(str);
}
