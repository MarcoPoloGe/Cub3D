/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:16:04 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/24 16:54:44 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

double ft_get_sideDist(double nb)
{
	double diff;
	double sideDist;

	diff = 1 - (nb - (int) nb);
	sideDist = nb + diff;

	return (sideDist);
}

t_coord ft_coord(double y, double x)
{
	t_coord coord;

	coord.y = y;
	coord.x = x;
	return (coord);
}

void	ft_calculate_impact_point(t_coord coord, t_ray *ray, t_data *data)
{
	t_coord	sidex;
	t_coord	sidey;
	int		i;

	sidex.y = coord.y;
	sidex.x = ft_get_sideDist(coord.x);
	sidey.y = ft_get_sideDist(coord.y) - 1;
	sidey.x = coord.x;
	ft_render_one_px(ft_coord_to_pos(sidex), COLOR_WALL, data);
	sidex = ft_find_next_coord_x(coord, ray->angle, sidex, 0);
	sidey = ft_find_next_coord_y(coord, ray->angle, sidey, 0);
	i = -1;
	ray->impact = 0;
	printf("angle: %f\n", ray->angle);
	while (ray->impact == 0)
	{
		if (++i != 0)
		{
			if (ray->angle < 90)
			{
				/*sidex = ft_find_next_coord_x(sidex, ray->angle,
						ft_coord(sidex.y, sidex.x + 1), 0);*/
				sidey = ft_find_next_coord_y(sidey, ray->angle,
											 ft_coord(sidey.y - 1, sidey.x), 0);
			}
			/*else if (ray->angle < 180)
			{
				sidex = ft_find_next_coord_x(sidex, ray->angle,
						ft_coord(sidex.y, sidex.x + 1), 1);
				sidey = ft_find_next_coord_y(sidey, ray->angle,
						ft_coord(sidey.y + 1, sidey.x), 1);
			}
			else if (ray->angle < 270)
			{
				sidex = ft_find_next_coord_x(sidex, ray->angle,
						ft_coord(sidex.y, sidex.x - 1), 1);
				sidey = ft_find_next_coord_y(sidey, ray->angle,
						ft_coord(sidey.y + 1, sidey.x), 0);
			}
			else if (ray->angle < 360)
			{
				sidex = ft_find_next_coord_x(sidex, ray->angle,
						ft_coord(sidex.y, sidex.x - 1), 0);
				sidey = ft_find_next_coord_y(sidey, ray->angle,
						ft_coord(sidey.y - 1, sidey.x), 1);
			}*/
		}
		ray->impact = ft_check_if_wall_hit(data, data->map, sidex, 1);
		if (ray->impact != 0)
			ft_render_one_px(ft_coord_to_pos(sidex), COLOR_COLLISION, data);
		else
		{
			ray->impact = ft_check_if_wall_hit(data, data->map, sidey, 0);
			if (ray->impact != 0)
				ft_render_one_px(ft_coord_to_pos(sidey), COLOR_FOV, data);
		}
		ft_render_one_px(ft_coord_to_pos(sidex), COLOR_COLLISION, data);
		ft_render_one_px(ft_coord_to_pos(sidey), COLOR_FOV, data);
	}
}