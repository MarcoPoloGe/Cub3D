/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:00:26 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 11:23:58 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_coord	ft_rotate_point(t_coord axis, t_coord point, double angle)
{
	double	c;
	double	s;
	t_coord	prime;

	angle = ft_degrees_to_radian(angle);
	c = cos(angle);
	s = sin(angle);
	point.x -= axis.x;
	point.y -= axis.y;
	prime.x = point.x * c - point.y * s;
	prime.y = point.x * s + point.y * c;
	prime.x = point.x * c - point.y * s;
	prime.y = point.x * s + point.y * c;
	prime.x += axis.x;
	prime.y += axis.y;
	return (prime);
}

t_coord	ft_find_next_coord_x(t_coord a, double alpha, t_coord c)
{
	double	ab;
	double	ac;
	double	bc;
	t_coord	res;

	if (alpha < 180)
		ac = c.x - a.x;
	else
		ac = a.x - c.x;
	ab = 1 * ac / cos(ft_degrees_to_radian(alpha));
	bc = sqrt(pow(ab, 2) - pow(ac, 2));
	if (alpha < 180 || alpha > 360)
		res.y = c.y - bc;
	else
		res.y = c.y + bc;
	res.x = c.x;
	return (res);
}

t_coord	ft_find_next_coord_y(t_coord a, double alpha, t_coord c)
{
	double	ab;
	double	ac;
	double	bc;
	t_coord	res;

	if (alpha > 90 && alpha < 270)
		ac = c.y - a.y;
	else
		ac = a.y - c.y;
	ab = 1 * ac / cos(ft_degrees_to_radian(alpha));
	bc = sqrt(pow(ab, 2) - pow(ac, 2));
	if (alpha > 180)
		res.x = c.x - bc;
	else
		res.x = c.x + bc;
	res.y = c.y;
	return (res);
}
