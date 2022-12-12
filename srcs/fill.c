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
				data->player.pos_mp.y = i - 6;
 				data->player.pos_mp.x = j;
			}
			j++;
		}
		data->my_map.map_splited[k] = ft_strdup(data->all_splited[i]);
		k++;
		i++;
	}
	data->player.step_m = 3;
	data->l_texture.img = mlx_xpm_file_to_image(data->my_map.init,data->txtrs.we,&data->l_texture.width,&data->l_texture.height);
	if (!data->l_texture.img)
		exit(1);
	data->l_texture.arr = (int *)mlx_get_data_addr(data->l_texture.img,&data->l_texture.bpp,&data->l_texture.line_length,&data->l_texture.endian);
//	data->l_texture.arr = 0;
//	data->r_texture.img = mlx_xpm_file_to_image(data->my_map.init,data->txtrs.ea,&data->r_texture.width,&data->r_texture.height);
//	if (!data->r_texture.img)
//		exit(1);
//	data->r_texture.arr = 0;
//	data->b_texture.img = mlx_xpm_file_to_image(data->my_map.init,data->txtrs.so,&data->b_texture.width,&data->b_texture.height);
//	if (!data->b_texture.img)
//		exit(1);
//	data->b_texture.arr = 0;
//	data->f_texture.img = mlx_xpm_file_to_image(data->my_map.init,data->txtrs.no,&data->f_texture.width,&data->f_texture.height);
//	if (!data->f_texture.img)
//		exit(1);
//	data->f_texture.arr = 0;
	data->player.step_r = M_PI/30;
	data->my_map.map_splited[k] = NULL;
}

