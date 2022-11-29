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
