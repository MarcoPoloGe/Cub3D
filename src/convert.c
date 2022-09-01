/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:23:06 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 11:23:51 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_pos	ft_pos(int y, int x)
{
	t_pos	pos;

	pos.y = y;
	pos.x = x;
	return (pos);
}

t_coord	ft_coord(double y, double x)
{
	t_coord	coord;

	coord.y = y;
	coord.x = x;
	return (coord);
}

t_pos	ft_coord_to_pos(t_coord input)
{
	t_pos	result;

	result.x = (int)(input.x * MINIMAP_RENDER_SIZE);
	result.y = (int)(input.y * MINIMAP_RENDER_SIZE);
	return (result);
}

double	ft_degrees_to_radian(double degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180);
	return (radians);
}

double	ft_radian_to_degrees(double degrees)
{
	double	radians;

	radians = degrees * (M_PI * 180);
	return (radians);
}
