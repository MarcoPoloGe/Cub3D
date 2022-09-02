/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_impact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:51:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/02 13:59:41 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_ool(int *ij, int map_height, int map_width)
{
	if (ij[0] <= 0)
		ij[0] = 0;
	if (ij[1] <= 0)
		ij[1] = 0;
	if (ij[0] >= map_height)
		ij[0] = map_height - 1;
	if (ij[1] >= map_width)
		ij[1] = map_width - 1;
}

t_impact	*is_wall_hit(t_data *data, t_coord coord, int *ij, t_impact *res)
{
	if ((ij[0] < data->map_height && ij[1] < data->map_width)
		&& data->map[ij[0]][ij[1]] == '1')
	{
		res->coord.x = coord.x;
		res->coord.y = coord.y;
		res->distance = sqrt(pow(data->camera.coord.x - coord.x, 2)
				+ pow(data->camera.coord.y - coord.y, 2));
		return (res);
	}
	else
	{
		free(res);
		return (0);
	}
}

t_impact	*ft_check_if_wall_hit_y(t_data *data, t_coord coord, double angle)
{
	int			ij[2];
	t_impact	*res;

	ij[0] = 0;
	ij[1] = 0;
	res = ft_calloc(sizeof(t_impact), 1);
	if (!res)
		leave(data, "Error: malloc\n");
	if ((angle <= 90 || angle >= 270) && res)
	{
		ij[0] = floor(coord.y) - 1;
		ij[1] = floor(coord.x);
		check_ool(ij, data->map_height, data->map_width);
		res->wall = &data->assets.no;
		res->wall_x = coord.x - ij[1];
	}
	else if (res)
	{
		ij[0] = floor(coord.y);
		ij[1] = floor(coord.x);
		check_ool(ij, data->map_height, data->map_width);
		res->wall = &data->assets.so;
		res->wall_x = coord.x - ij[1];
	}
	return (is_wall_hit(data, coord, ij, res));
}

t_impact	*ft_check_if_wall_hit_x(t_data *data, t_coord coord, double angle)
{
	int			ij[2];
	t_impact	*res;

	ij[0] = 0;
	ij[1] = 0;
	res = ft_calloc(sizeof(t_impact), 1);
	if (!res)
		leave(data, "Error: malloc\n");
	if (angle <= 180 && res)
	{
		ij[0] = floor(coord.y);
		ij[1] = floor(coord.x);
		check_ool(ij, data->map_height, data->map_width);
		res->wall = &data->assets.ea;
		res->wall_x = coord.y - ij[0];
	}
	else if (res)
	{
		ij[0] = floor(coord.y);
		ij[1] = ceil(coord.x) - 1;
		check_ool(ij, data->map_height, data->map_width);
		res->wall = &data->assets.we;
		res->wall_x = coord.y - ij[0];
	}
	return (is_wall_hit(data, coord, ij, res));
}
