#include "../src/cub3D.h"

void	ft_render_pixel_line(t_pos start, t_pos end, int color, t_data *data)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(end.x - start.x);
	dy = -abs(end.y - start.y);
	sx = start.x < end.x ? 1 : -1;
	sy = start.y < end.y ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		ft_put_pixel_frame(&(data->frame), start.y, start.x, color);
		if (start.y == end.y && start.x == end.x)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			start.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			start.y += sy;
		}
	}
}

void	ft_render_cube_empty(int y, int x, int size, int color, t_data *data)
{
	t_pos	up_left;
	t_pos	up_right;
	t_pos	down_left;
	t_pos	down_right;

	up_left.y = y;
	up_left.x = x;

	up_right.y = up_left.y;
	up_right.x = up_left.x + size;

	down_left.y = up_left.y + size;
	down_left.x = up_left.x;

	down_right.y = up_left.y + size;
	down_right.x = up_left.x + size;

	ft_render_pixel_line(up_left, up_right, color, data);
	ft_render_pixel_line(up_right, down_right, color, data);
	ft_render_pixel_line(down_left, down_right, color, data);
	ft_render_pixel_line(up_left, down_left, color, data);
}

void	ft_render_cube_filled(int pos_y, int pos_x, int size, int color, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_put_pixel_frame(&(data->frame), y + pos_y, x + pos_x, color);
			x++;
		}
		y++;
	}
}

void	ft_render_cube_wall(int pos_y, int pos_x, int size, int color, t_data *data)
{
	int	offset;

	offset = 6;
	ft_render_cube_empty(pos_y, pos_x, size, color, data);
	ft_render_cube_filled(pos_y + offset, pos_x + offset, size - offset * 2 + 1, color, data);
}

void	ft_render_one_px(t_pos pos, int color, t_data *data)
{
	ft_put_pixel_frame(&(data->frame), pos.y - 1, pos.x - 1, color);
	ft_put_pixel_frame(&(data->frame), pos.y - 1, pos.x, color);
	ft_put_pixel_frame(&(data->frame), pos.y, pos.x - 1, color);

	ft_put_pixel_frame(&(data->frame), pos.y, pos.x, color);

	ft_put_pixel_frame(&(data->frame), pos.y + 1, pos.x + 1, color);
	ft_put_pixel_frame(&(data->frame), pos.y + 1, pos.x, color);
	ft_put_pixel_frame(&(data->frame), pos.y, pos.x + 1, color);

	ft_put_pixel_frame(&(data->frame), pos.y + 1, pos.x - 1, color);
	ft_put_pixel_frame(&(data->frame), pos.y - 1, pos.x + 1, color);
}

void	ft_render_grid(char **map, int size, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				ft_render_cube_empty(y * size, x * size, size, COLOR_GROUD, data);
			if (map[y][x] == ' ')
				ft_render_cube_empty(y * size, x * size, size, COLOR_SPACE, data);
			x++;
		}
		y++;
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_render_cube_wall(y * size, x * size, size, COLOR_WALL, data);
			x++;
		}
		y++;
	}
}

t_pos	ft_coord_to_pos(t_coord input)
{
	t_pos	result;

	result.x = (int)(input.x * FDF_RENDER_SIZE);
	result.y = (int)(input.y * FDF_RENDER_SIZE);
	return (result);
}

void	ft_render_player_fov(t_data *data)
{
	t_coord dir;
	t_coord coord;
	t_coord		fov_left;
	t_coord		fov_right;

	coord = data->camera.coord;
	dir.y = coord.y - DIR_VECTOR_LEN;
	dir.x = coord.x;

	dir = ft_rotate_point(coord, dir, data->camera.dir_angle);
	ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(dir), COLOR_PLAYER_DIR, data);

	fov_left = ft_rotate_point(coord, dir, FOV / 2);
	fov_right = ft_rotate_point(coord, dir, -(FOV / 2));
	ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(fov_right), COLOR_FOV, data);
	ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(fov_left), COLOR_FOV, data);
}

void	ft_render_ray(t_coord coord, t_ray ray, t_data *data)
{
	t_coord fake_impact;

	if(ray.impact == NULL)
	{
		fake_impact.y = coord.y - DIR_VECTOR_LEN;
		fake_impact.x = coord.x;
		fake_impact = ft_rotate_point(coord, fake_impact, ray.angle + data->camera.dir_angle);
		ft_render_one_px(ft_coord_to_pos(fake_impact), COLOR_COLLISION, data);
		ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(fake_impact), COLOR_RAY, data);
	}
	else
	{
		ft_render_one_px(ft_coord_to_pos(ray.impact->coord), COLOR_COLLISION, data);
		ft_render_pixel_line(ft_coord_to_pos(coord), ft_coord_to_pos(ray.impact->coord), COLOR_RAY, data);
	}
}

void	ft_render_rays(t_data *data) //not tested yet
{
	int			i;
	t_camera	*camera;
	t_ray		*ray_list;

	camera = &(data->camera);
	ray_list = camera->ray_list;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ft_render_ray(camera->coord, ray_list[i], data);
		i++;
	}
}

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

int	ft_fdf_render(t_data *data)
{

	mlx_clear_window(data->mlx, data->win);
	ft_render_grid(data->map, FDF_RENDER_SIZE, data);
	ft_render_player_fov(data);
/*	ft_printf("map_y: %i map_x: %i", (int)data->camera.coord.y , (int)data->camera.coord.x);


	//ft_render_rays(data);
	ft_putstr("\n");
	ft_put_camera(data->camera);*/

	ft_push_frame(data);
	return (0);

}
