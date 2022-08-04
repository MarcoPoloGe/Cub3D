#include "../src/cub3D.h"

int	render_rectangle(t_img *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img->addr[(y * img->width) + x] = color;
			x++;
		}
		++y;
	}
	return (0);
}

void display_rectangle(t_data *data, int pos_y, int pos_x, int height, int width, int color)
{
	t_img rect;

	ft_new_image(&rect, width, height, data);
	render_rectangle(&rect, color);
	mlx_put_image_to_window(data->mlx, data->win, rect.ptr, pos_x , pos_y);
	mlx_destroy_image(data->mlx,rect.ptr);
}

void     ft_display_pixel_line(t_pos start, t_pos end, int color, t_data *data)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(end.x - start.x);
	dy = -abs(end.y - start.y);
	sx = start.x < end.x ? 1 : -1;
	sy = start.y < end.y ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, start.x, start.y, color);
		mlx_pixel_put(data->mlx, data->win, start.x - 1, start.y, color);
		mlx_pixel_put(data->mlx, data->win, start.x, start.y - 1, color);
		mlx_pixel_put(data->mlx, data->win, start.x - 1, start.y - 1, color);
		if (start.y == end.y && start.x == end.x)
			break;
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

void	ft_display_horizontal_line(t_pos start, t_pos end, int color, t_data *data)
{
	int		i;
	t_img	line;

	line.width = end.x - start.x;
	line.height = end.y - start.y;
	if (line.height < 0)
		line.height *= -1;
	if (line.width < 0)
		line.width *= -1;
	line.width += 1;
	line.height += 1;
	ft_new_image(&line, line.width, line.height, data);
	i = 0;
	while (i < line.width * line.height)
	{
		line.addr[i] = color;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, line.ptr, (int)start.x , (int)start.y);
	mlx_destroy_image(data->mlx, line.ptr);
}

void	ft_display_cube_empty(int y, int x, int size, int color, t_data *data)
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

	ft_display_horizontal_line(up_left, up_right, color ,data);
	ft_display_horizontal_line(up_right, down_right, color ,data);
	ft_display_horizontal_line(down_left, down_right, color ,data);
	ft_display_horizontal_line(up_left, down_left, color ,data);
}

void ft_add_cube_render(t_img img, int pos_y, int pos_x, int size, int color)
{
	int	y;
	int	x;


	(void)pos_y;
			(void)pos_x;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			img.addr[((y) * size) + (x)] = color;
			x++;
		}
		y++;
	}
}

void	ft_display_cube_filled(int pos_y, int pos_x, int size, int color, t_data *data)
{
	t_img img;

	ft_new_image(&img, size, size, data);

	ft_add_cube_render(img, 0, 0, size, color);
	mlx_put_image_to_window(data->mlx, data->win, img.ptr, pos_x, pos_y);
	mlx_destroy_image(data->mlx, img.ptr);
}

void	ft_display_cube_wall(int pos_y, int pos_x, int size, int color, t_data *data)
{
	int offset;

	offset = 6;
	ft_display_cube_empty(pos_y, pos_x, size, color, data);
	ft_display_cube_filled(pos_y + offset, pos_x + offset, size - offset * 2 + 1, color, data);
}

void	ft_display_one_px(int pos_y, int pos_x, int color, t_data *data)
{
	t_img img;

	ft_new_image(&img, 1, 1, data);

	img.addr[0] = color;
	mlx_put_image_to_window(data->mlx, data->win, img.ptr, pos_x, pos_y);
	mlx_destroy_image(data->mlx, img.ptr);
}

void	ft_display_grid(char **map, int size, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(map[y][x] == '0')
				ft_display_cube_empty(y * size, x * size, size, COLOR_GROUD, data);
			if(map[y][x] == ' ')
				ft_display_cube_empty(y * size, x * size, size, COLOR_SPACE, data);
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
			if(map[y][x] == '1')
				ft_display_cube_wall(y * size, x * size, size, COLOR_WALL, data);
			x++;
		}
		y++;
	}

}

t_pos ft_coord_to_pos_from_origin(t_coord origin, t_coord input)
{
	t_pos result;

	result.x -= (int)(origin.x - input.x);
	result.y -= (int)(origin.y - input.y);

	return (result);
}

t_pos ft_coord_to_pos(t_coord input)
{
	t_pos result;
	result.x = (int)input.x;
	result.y = (int)input.y;
	return (result);
}


t_pos ft_coord_to_pos_scaled(t_coord input)
{
	t_pos result;
	result.x = (int)(input.x * FDF_RENDER_SIZE + (FDF_RENDER_SIZE/2));
	result.y = (int)(input.y * FDF_RENDER_SIZE + (FDF_RENDER_SIZE/2));
	return (result);
}

void	ft_display_player(t_data *data)
{
	t_pos		dir;
	t_pos		coord;

	coord = ft_coord_to_pos_scaled(data->camera.coord);
	dir = ft_coord_to_pos_scaled(data->camera.dir);

	ft_display_pixel_line(coord, dir, COLOR_PLAYER_DIR , data);
}

void ft_display_FOV(t_data *data)
{
	t_camera	*camera;
	t_coord 	fov_left;
	t_coord 	fov_right;

	camera = &(data->camera);

	fov_left =	ft_rotate_point(camera->coord, camera->dir, FOV / 2);
	fov_right =	ft_rotate_point(camera->coord, camera->dir, -(FOV / 2));

	ft_display_pixel_line(ft_coord_to_pos_scaled(camera->coord), ft_coord_to_pos_scaled(fov_right), COLOR_FOV , data);
	ft_display_pixel_line(ft_coord_to_pos_scaled(camera->coord), ft_coord_to_pos_scaled(fov_left), COLOR_FOV , data);
}

void ft_display_ray(t_coord coord, t_ray ray, t_data *data) //not tested yet
{
	ft_display_one_px(ray.impact.coord.y, ray.impact.coord.x, COLOR_COLLISION, data);
	ft_display_pixel_line(ft_coord_to_pos_scaled(coord), ft_coord_to_pos_scaled(ray.impact.coord), COLOR_RAY , data);
}

void ft_display_rays(t_data *data) //not tested yet
{
	int i;
	t_camera	*camera;
	t_ray		*ray_list;

	camera = &(data->camera);
	ray_list = camera->ray_list;

	i = 0;
	while (ray_list + i)
	{
		ft_display_ray(camera->coord, ray_list[i], data);
	    i++;
	}
}

int ft_fdf_render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);

	ft_display_grid(data->map, FDF_RENDER_SIZE, data);
	ft_display_FOV(data);
	ft_display_player(data);
	ft_display_rays(data);
	return (0);
}
