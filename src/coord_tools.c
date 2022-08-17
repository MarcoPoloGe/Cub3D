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

double	ft_get_angle(t_coord axis, t_coord a, t_coord b) // in progress not done
{
	double	angle;

	a.x -= axis.x;
	a.y -= axis.y;

	b.x -= axis.x;
	b.y -= axis.y;

	angle = acos((a.x * b.x + a.y * b.y) / sqrt(pow(a.x, 2) + pow(a.y, 2)) * sqrt(pow(b.x, 2) + pow(b.y, 2))); //maybe wrong

	//angle = arccos[(xa * xb + ya * yb) / (√(xa2 + ya2) * √(xb2 + yb2))]   orginal formula
	return (angle);
}
