#include "cub3D.h"

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
