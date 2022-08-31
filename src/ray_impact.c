/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_impact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:51:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/31 16:51:39 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_impact	*ft_check_if_wall_hit_y(t_data *data, char **map, t_coord coord, double angle)
{
	int			i;
	int			j;
	t_impact	*res;

	res = malloc(sizeof(t_impact));
	i = 0;
	j = 0;
	if (angle <= 90 || angle >= 270)
	{
		i = floor(coord.y) - 1;
		j = floor(coord.x);
		res->wall = &data->assets.no;
		res->wall_x = j % res->wall->width;
	}
	else
	{
		i = floor(coord.y);
		j = floor(coord.x);
		res->wall = &data->assets.so;
		res->wall_x = j % res->wall->width;
	}
	if (i <= 0)
		i = 0;
	if (j <= 0)
		j = 0;
	if (i >= data->map_height - 1)
		i = data->map_height - 1;
	if (j >= data->map_width - 1)
		j = data->map_width - 1;
	if (map[i][j] - 48 == 1)
	{
		res->distance = sqrt(pow(data->camera.coord.x - coord.x, 2)
					+ pow(data->camera.coord.y - coord.y, 2));
		ft_render_one_px(ft_coord_to_pos(coord), COLOR_COLLISION, data->frame.game);
		return (res);
	}
	else
	{
		free(res);
		return (0);
	}
}

t_impact	*ft_check_if_wall_hit_x(t_data *data, char **map, t_coord coord, double angle)
{
	int			i;
	int			j;
	t_impact	*res;

	res = malloc(sizeof(t_impact));
	i = 0;
	j = 0;
	if (angle <= 180)
	{
		i = floor(coord.y);
		j = floor(coord.x);
		res->wall = &data->assets.ea;
		res->wall_x = i % res->wall->height;
	}
	else
	{
		i = floor(coord.y);
		j = ceil(coord.x) - 1;
		res->wall = &data->assets.we;
		res->wall_x = i % res->wall->height;
	}
	if (i <= 0)
		i = 0;
	if (j <= 0)
		j = 0;
	if (i >= data->map_height)
		i = data->map_height - 1;
	if (j >= data->map_width)
		j = data->map_width - 1;
	if (map[i][j] - 48 == 1)
	{
		res->distance = sqrt(pow(data->camera.coord.x - coord.x, 2)
				+ pow(data->camera.coord.y - coord.y, 2));
		ft_render_one_px(ft_coord_to_pos(coord), COLOR_COLLISION, data->frame.game);
		return (res);
	}
	else
	{
		free(res);
		return (0);
	}
}
