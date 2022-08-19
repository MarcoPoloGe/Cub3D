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

t_coord	ft_find_next_coord(t_coord a, double alpha, t_coord c)
{
	double	ab;
	double	ac;
	double	bc;
	t_coord	res;

	ac = c.x - a.x;
	ab = 1 * ac / cos(alpha);
	bc = pow(ab, 2) - pow(ac, 2);
	res.y = c.y - bc;
	res.x = c.x;
	return (res);
}

int	ft_check_if_wall_hit(char **map, t_coord coord, int xory)
{
	int	i;
	int	j;

	if (xory == 0)
		i = (int)coord.y + 0.1;
	else
		i = (int)coord.y - 0.1;
	if (xory == 0)
		j = (int)coord.x + 0.1;
	else
		j = (int)coord.x - 0.1;
	if (map[i][j] > 0)
		return (1);
	else
		return (0);
}
