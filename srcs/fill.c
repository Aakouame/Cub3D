#include "../include/cub.h"

void fill_map(t_data *data)
{
	int i = 6;
	int k = 0;
	int	j;


	while(data->all_splited[i])
		i++;
	data->my_map.map_splited = malloc(sizeof(char *) * i - 5);
	i = 6;
	while(data->all_splited[i])
	{
		j = 0;
		while(data->all_splited[i][j])
		{
			if (!ft_search("WSNE",data->all_splited[i][j]))
			{
				data->all_splited[i][j] = '0';
				data->player.pos.y = i - 6;
 				data->player.pos.x = j;
			}
			j++;
		}
		data->my_map.map_splited[k] = ft_strdup(data->all_splited[i]);
		k++;
		i++;
	}
	data->my_map.map_splited[k] = NULL;
}

