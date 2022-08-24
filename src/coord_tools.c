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

t_coord	ft_find_next_coord(t_coord a, double alpha, t_coord c, int negative)
{
	double	ab;
	double	ac;
	double	bc;
	t_coord	res;

	ac = c.x - a.x;
	ab = 1 * ac / cos(alpha);
	bc = pow(ab, 2) - pow(ac, 2);
	if (negative == 0)
		res.y = c.y - bc;
	else
		res.y = c.y + bc;
	res.x = c.x;
	return (res);
}

t_coord	ft_find_next_coord_y(t_coord a, double alpha, t_coord c, int negative)
{
	double	ab;
	double	ac;
	double	bc;
	t_coord	res;

	ac = c.y - a.y;
	ab = 1 * ac / cos(alpha);
	bc = pow(ab, 2) - pow(ac, 2);
	if (negative == 0)
		res.x = c.x - bc;
	else
		res.x = c.x + bc;
	res.y = c.y;
	return (res);
}

t_impact	*ft_check_if_wall_hit(t_data *data, char **map, t_coord coord, int xory)
{
	int			i;
	int			j;
	t_impact	*res;

	res = malloc(sizeof(t_impact));
	i = (int)coord.y;
	j = (int)coord.x;
	if (xory == 0)
	{
		res->wall = &data->assets.no;
		res->wall_x = j % res->wall->width;
	}
	else
	{
		res->wall = &data->assets.so;
		res->wall_x = j % res->wall->width;
	}
	if (xory == 1)
	{
		res->wall = &data->assets.ea;
		res->wall_x = i % res->wall->height;
	}
	else
	{
		res->wall = &data->assets.we;
		res->wall_x = i % res->wall->height;
	}
	printf("i = %d, j = %d\n", i, j);
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (i > 19)
		i = 19;
	if (j > 25)
		j = 25;
	if (map[i][j] - 48 == 1)
	{
		res->distance = pow(data->camera.coord.x, 2) - pow(coord.x, 2)
			+ pow(data->camera.coord.y, 2) - pow(coord.y, 2);
		return (res);
	}
	else
		return (0);
}
