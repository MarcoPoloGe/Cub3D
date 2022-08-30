/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:16:04 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/30 16:46:13 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

double ft_get_sideDist(double nb)
{
	double	diff;
	double	sideDist;

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
	t_coord		sidex;
	t_coord		sidey;
	int			i;
	t_impact	*resy;
	double		thisangle;

	if (ray->angle + data->camera.dir_angle > 180)
		thisangle = data->camera.dir_angle + ray->angle;
	else
		thisangle = data->camera.dir_angle + ray->angle;
	if (thisangle >= 360)
		thisangle -= 360;
	if (thisangle < 0)
		thisangle += 360;
	/*else if (thisangle > 90 && thisangle < 180)
		thisangle -= 45;*/
	sidex.y = coord.y;
	printf("dir: %f + ray: %f = angle: %f\n", data->camera.dir_angle, ray->angle, thisangle);
	if (thisangle > 90 || thisangle < 180)
		sidex.x = floor(coord.x);
	else
		sidex.x = ceil(coord.x);

	if (thisangle < 90 || thisangle > 270)
		sidey.y = floor(coord.y);
	else
		sidey.y = ceil(coord.y);
	sidey.x = coord.x;
	//ft_render_one_px(ft_coord_to_pos(sidex), COLOR_WALL, data);
	if (thisangle > 180)
	{
		sidex = ft_find_next_coord_x(coord, ray->angle + 90, sidex);
		sidey = ft_find_next_coord_y(coord, thisangle, sidey);
	}
	else if (thisangle <= 180)
	{
		sidex = ft_find_next_coord_x(coord, ray->angle + 90, sidex);
		sidey = ft_find_next_coord_y(coord, thisangle - 180, sidey);
	}
	i = -1;
	ray->impact = 0;
	resy = 0;
	while (resy == 0)
	{
		if (++i != 0)
		{
			if (thisangle <= 90)
			{
				sidey = ft_find_next_coord_y(sidey, thisangle - 180, ft_coord(sidey.y - 1, sidey.x));
			}
			else if (thisangle <= 180)
			{
				sidey = ft_find_next_coord_y(sidey, thisangle - 180, ft_coord(sidey.y + 1, sidey.x));
			}
			else if (thisangle <= 270)
			{
				sidey = ft_find_next_coord_y(sidey, thisangle, ft_coord(sidey.y + 1, sidey.x));
			}
			else if (thisangle <= 360)
			{
				sidey = ft_find_next_coord_y(sidey, thisangle, ft_coord(sidey.y - 1, sidey.x));
			}
		}
		resy = ft_check_if_wall_hit(data, data->map, sidey, 0);
		if (resy != 0)
			ft_render_one_px(ft_coord_to_pos(sidey), COLOR_FOV, data);
		ft_render_one_px(ft_coord_to_pos(sidey), COLOR_COLLISION, data);
	}
	i = -1;
	/*while (ray->impact == 0)
	{
		if (++i != 0)
		{
			if (ray->angle < 0)
				sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
						ft_coord(sidex.y, sidex.x + 1));
			else
				sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
						ft_coord(sidex.y, sidex.x - 1));
		}
		ray->impact = ft_check_if_wall_hit(data, data->map, sidex, 1);
		if (ray->impact != 0)
		{
			if (resy->distance < ray->impact->distance)
				ray->impact = resy;
			ft_render_one_px(ft_coord_to_pos(sidex), COLOR_COLLISION, data);
		}
		ft_render_one_px(ft_coord_to_pos(sidex), COLOR_COLLISION, data);
	}*/
	free(resy);
}

/*void	ft_calculate_impact_point(t_coord coord, t_ray *ray, t_data *data)
{
	t_coord	sidex;
	t_coord	sidey;
	int		i;

	sidex.y = coord.y;
	if (ray->angle < 0)
		sidex.x = ceil(coord.x);
	else
		sidex.x = floor(coord.x);

	sidey.y = ft_get_sideDist(coord.y);
	sidey.x = coord.x;
	ft_render_one_px(ft_coord_to_pos(sidex), COLOR_WALL, data);
	sidex = ft_find_next_coord_x(coord, ray->angle + 90, sidex, 0);
	sidey = ft_find_next_coord_y(coord, ray->angle, sidey, 0);
	i = -1;
	ray->impact = 0;
	while (ray->impact == 0)
	{
		if (++i != 0)
		{
			//if (ray->angle < 90)
			//{
				if (ray->angle < 0)
					sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
						ft_coord(sidex.y, sidex.x + 1), 0);
				else
					sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
						ft_coord(sidex.y, sidex.x - 1), 0);
				//sidey = ft_find_next_coord_y(sidey, ray->angle,
				//		ft_coord(sidey.y - 1, sidey.x), 0);
			//}
			else if (ray->angle < 180)
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
			}
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
		//ft_render_one_px(ft_coord_to_pos(sidey), COLOR_FOV, data);
	}
	while (ray->impact == 0)
	{
		if (++i != 0)
		{
			if (ray->angle < 0)
				sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
					ft_coord(sidex.y, sidex.x + 1), 0);
			else
				sidex = ft_find_next_coord_x(sidex, ray->angle + 90,
					ft_coord(sidex.y, sidex.x - 1), 0);
		}
		ray->impact = ft_check_if_wall_hit(data, data->map, sidex, 1);
		if (ray->impact != 0)
		{
			if (resy->distance < ray->impact->distance)
				ray->impact = resy;
			ft_render_one_px(ft_coord_to_pos(sidex), COLOR_FOV, data);
		}
		ft_render_one_px(ft_coord_to_pos(sidex), COLOR_FOV, data);
	}
	free(resy);
}*/
