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
		//ft_put_pixel_frame(&(data->frame), start.y - 1, start.x, color);
		//ft_put_pixel_frame(&(data->frame), start.y, start.x - 1, color);
		//ft_put_pixel_frame(&(data->frame), start.y - 1, start.x - 1, color);
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

void	ft_render_one_px(int pos_y, int pos_x, int color, t_data *data)
{
	ft_put_pixel_frame(&(data->frame), pos_y, pos_x, color);
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

	result.x = (int)input.x;
	result.y = (int)input.y;
	return (result);
}

t_pos	ft_coord_to_pos_scaled(t_coord input)
{
	t_pos	result;

	result.x = (int)(input.x * FDF_RENDER_SIZE + (FDF_RENDER_SIZE / 2));
	result.y = (int)(input.y * FDF_RENDER_SIZE + (FDF_RENDER_SIZE / 2));
	return (result);
}

void	ft_render_player(t_data *data)
{
	t_pos		dir;
	t_pos		coord;

	coord = ft_coord_to_pos_scaled(data->camera.coord);
	dir = ft_coord_to_pos_scaled(data->camera.dir);

	ft_render_pixel_line(coord, dir, COLOR_PLAYER_DIR, data);
}

void	ft_render_fov(t_data *data)
{
	t_camera	*camera;
	t_coord		fov_left;
	t_coord		fov_right;

	camera = &(data->camera);

	fov_left = ft_rotate_point(camera->coord, camera->dir, FOV / 2);
	fov_right = ft_rotate_point(camera->coord, camera->dir, -(FOV / 2));

	ft_render_pixel_line(ft_coord_to_pos_scaled(camera->coord), ft_coord_to_pos_scaled(fov_right), COLOR_FOV, data);
	ft_render_pixel_line(ft_coord_to_pos_scaled(camera->coord), ft_coord_to_pos_scaled(fov_left), COLOR_FOV, data);
}

void	ft_render_ray(t_coord coord, t_ray ray, t_data *data) //not tested yet
{
	ft_render_one_px(ray.impact.coord.y, ray.impact.coord.x, COLOR_COLLISION, data);
	ft_render_pixel_line(ft_coord_to_pos_scaled(coord), ft_coord_to_pos_scaled(ray.impact.coord), COLOR_RAY, data);
}

void	ft_render_rays(t_data *data) //not tested yet
{
	int			i;
	t_camera	*camera;
	t_ray		*ray_list;

	camera = &(data->camera);
	ray_list = camera->ray_list;

	i = 0;
	while (ray_list + i)
	{
		ft_render_ray(camera->coord, ray_list[i], data);
		i++;
	}
}

int	ft_fdf_render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);


	ft_render_grid(data->map, FDF_RENDER_SIZE, data);
	ft_render_fov(data);
	ft_render_player(data);
	ft_render_rays(data);

	ft_push_frame(data);
	return (0);
}
