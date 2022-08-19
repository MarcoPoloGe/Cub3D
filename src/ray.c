#include "cub3D.h"

/*void	ft_ray_calculate_collision(char **map, t_coord coord, t_ray *ray) //has to calculate the collison point of the ray.
{

	t_coord dir;
	int		i;
	int		j;
	double	distance;

	dir = coord;
	dir.y -= 100;

	ft_rotate_point(co)

	printf("x: %f, y: %f, angle: %f\n", coord.x, coord.y, ray->angle);
	i = -1;
	j = -1;
	distance = pow(coord.x - j) + pow(coord.y - i);
	if (ray->angle + FOV < 0)
	{
		stepX = -1;
		sideDistX = (coord.x - i) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (i + 1.0 - coord.x) * deltaDistX;
	}
	if (ray->angle + FOV < 0)
	{
		stepY = -1;
		sideDistY = (coord.y - j) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (j + 1.0 - coord.y) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			i += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			j += stepY;
			side = 1;
		}
		if (map[i][j] > 0)
			hit = 1;
	}
	while (map[++i])
	{
		while (map[++j])
		{
			if (pow(coord.x - j) + pow(coord.y - i) < distance)
				distance = pow(coord.x - j) + pow(coord.y - i);
		}
	}
	ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(ray->angle), , data);
}*/
