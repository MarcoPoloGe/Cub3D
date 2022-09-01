/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:16:04 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 15:19:21 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

void	init_this_angle(t_data *data, t_ray *ray, double *thisangle)
{
	if (ray->angle + data->camera.dir_angle > 180)
		*thisangle = data->camera.dir_angle + ray->angle;
	else
		*thisangle = data->camera.dir_angle + ray->angle;
	if (*thisangle >= 360)
		*thisangle -= 360;
	if (*thisangle < 0)
		*thisangle += 360;
}

void	init_sidexy(t_coord coord, t_coord *sidex, t_coord *sidey,
	double thisangle)
{
	sidex->y = coord.y;
	if (thisangle < 180)
		sidex->x = ceil(coord.x);
	else
		sidex->x = floor(coord.x);
	if (thisangle < 90 || thisangle > 270)
		sidey->y = floor(coord.y);
	else
		sidey->y = ceil(coord.y);
	sidey->x = coord.x;
	if (thisangle > 180)
		*sidey = ft_find_next_coord_y(coord, thisangle, *sidey);
	else if (thisangle <= 180)
		*sidey = ft_find_next_coord_y(coord, thisangle - 180, *sidey);
	*sidex = ft_find_next_coord_x(coord, thisangle + 90, *sidex);
}

t_impact	*calulate_impact_for_y(t_data *data, t_coord *sidey,
	double thisangle)
{
	t_impact	*resy;
	int			i;

	resy = 0;
	i = -1;
	while (resy == 0 && ++i < data->map_width + data->map_height)
	{
		if (i != 0)
		{
			if (thisangle <= 90)
				*sidey = ft_find_next_coord_y(*sidey, thisangle - 180,
						ft_coord(sidey->y - 1, sidey->x));
			else if (thisangle <= 180)
				*sidey = ft_find_next_coord_y(*sidey, thisangle - 180,
						ft_coord(sidey->y + 1, sidey->x));
			else if (thisangle <= 270)
				*sidey = ft_find_next_coord_y(*sidey, thisangle,
						ft_coord(sidey->y + 1, sidey->x));
			else if (thisangle <= 360)
				*sidey = ft_find_next_coord_y(*sidey, thisangle,
						ft_coord(sidey->y - 1, sidey->x));
		}
		resy = ft_check_if_wall_hit_y(data, *sidey, thisangle);
	}
	return (resy);
}

void	calulate_impact_for_x(t_data *data, t_ray *ray, t_coord *sidex,
	double thisangle)
{
	int	i;

	i = -1;
	while (ray->impact == 0 && ++i < data->map_width + data->map_height)
	{
		if (i != 0)
		{
			if (thisangle <= 90)
				*sidex = ft_find_next_coord_x(*sidex, thisangle + 90,
						ft_coord(sidex->y, sidex->x + 1));
			else if (thisangle <= 180)
				*sidex = ft_find_next_coord_x(*sidex, thisangle + 90,
						ft_coord(sidex->y, sidex->x + 1));
			else if (thisangle <= 270)
				*sidex = ft_find_next_coord_x(*sidex, thisangle + 90,
						ft_coord(sidex->y, sidex->x - 1));
			else if (thisangle <= 360)
				*sidex = ft_find_next_coord_x(*sidex, thisangle + 90,
						ft_coord(sidex->y, sidex->x - 1));
		}
		ray->impact = ft_check_if_wall_hit_x(data, *sidex, thisangle);
	}
}

void	ft_calculate_impact_point(t_coord coord, t_ray *ray, t_data *data)
{
	t_coord		sidex;
	t_coord		sidey;
	t_impact	*resy;
	double		thisangle;

	resy = 0;
	ray->impact = 0;
	init_this_angle(data, ray, &thisangle);
	init_sidexy(coord, &sidex, &sidey, thisangle);
	resy = calulate_impact_for_y(data, &sidey, thisangle);
	calulate_impact_for_x(data, ray, &sidex, thisangle);
	if (resy && ray->impact && resy->distance < ray->impact->distance)
	{
		ray->impact = resy;
		ft_render_one_px(ft_coord_to_pos(sidey), COLOR_COLLISION,
			data->frame.game);
	}
	else
	{
		free(resy);
		ft_render_one_px(ft_coord_to_pos(sidex), COLOR_COLLISION,
			data->frame.game);
	}
}
