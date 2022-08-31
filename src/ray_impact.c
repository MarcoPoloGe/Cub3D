#include "cub3D.h"

t_impact	*ft_check_if_wall_hit(t_data *data, char **map, t_coord coord, int xory)
{
	int			i;
	int			j;
	t_impact	*res;

	res = malloc(sizeof(t_impact));
	i = (int)coord.y;
	j = (int)coord.x;
	if (xory == 0)
	{
		res->wall = &data->assets.no;
		res->wall_x = j % res->wall->width;
	}
	else
	{
		res->wall = &data->assets.so;
		res->wall_x = j % res->wall->width;
	}
	if (xory == 1)
	{
		res->wall = &data->assets.ea;
		res->wall_x = i % res->wall->height;
	}
	else
	{
		res->wall = &data->assets.we;
		res->wall_x = i % res->wall->height;
	}
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (i >= data->map_height)
		i = data->map_height - 1;
	if (j >= data->map_width)
		j = data->map_width - 1;
	if (map[i][j] - 48 == 1)
	{
		res->distance = pow(data->camera.coord.x - coord.x, 2)
						+ pow(data->camera.coord.y - coord.y, 2);
		return (res);
	}
	else
	{
		free(res);
		return (0);
	}
}