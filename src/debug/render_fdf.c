#include "../src/cub3D.h"

void	ft_render_line_pos(t_pos start, t_pos end, int color, t_img *frame)
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
		ft_put_pixel_frame(frame, start.y, start.x, color);
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

void	ft_render_line_coord(t_coord start_coord, t_coord end_coord, int color, t_img *frame)
{
	t_pos start_pos;
	t_pos end_pos;

	start_pos = ft_coord_to_pos(start_coord);
	end_pos = ft_coord_to_pos(end_coord);

	ft_render_line_pos(start_pos, end_pos, color, frame);
}

void	ft_render_cube_empty(t_pos pos, int size, int color, t_img *frame)
{
	t_pos	up_left;
	t_pos	up_right;
	t_pos	down_left;
	t_pos	down_right;

	up_left.y = pos.y;
	up_left.x = pos.x;

	up_right.y = up_left.y;
	up_right.x = up_left.x + size;

	down_left.y = up_left.y + size;
	down_left.x = up_left.x;

	down_right.y = up_left.y + size;
	down_right.x = up_left.x + size;

	ft_render_line_pos(up_left, up_right, color, frame);
	ft_render_line_pos(up_right, down_right, color, frame);
	ft_render_line_pos(down_left, down_right, color, frame);
	ft_render_line_pos(up_left, down_left, color, frame);
}

void	ft_render_cube_filled(t_pos pos, int size, int color, t_img *frame)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_put_pixel_frame(frame, y + pos.y, x + pos.x, color);
			x++;
		}
		y++;
	}
}

void	ft_render_cube_wall(t_pos pos, int size, int color, t_img *frame)
{
	int offset;
	t_pos	fill_pos;

	offset = size / 10;

	fill_pos.x = pos.x + offset;
	fill_pos.y = pos.y + offset;

	ft_render_cube_empty(pos, size, color, frame);
	ft_render_cube_filled(fill_pos, size - offset * 2 + 1, color, frame);
}

void	ft_render_one_px(t_pos pos, int color, t_img *frame)
{
	ft_put_pixel_frame(frame, pos.y - 1, pos.x - 1, color);
	ft_put_pixel_frame(frame, pos.y - 1, pos.x, color);
	ft_put_pixel_frame(frame, pos.y, pos.x - 1, color);

	ft_put_pixel_frame(frame, pos.y, pos.x, color);

	ft_put_pixel_frame(frame, pos.y + 1, pos.x + 1, color);
	ft_put_pixel_frame(frame, pos.y + 1, pos.x, color);
	ft_put_pixel_frame(frame, pos.y, pos.x + 1, color);

	ft_put_pixel_frame(frame, pos.y + 1, pos.x - 1, color);
	ft_put_pixel_frame(frame, pos.y - 1, pos.x + 1, color);
}

void	ft_render_grid(t_pos pos, char **map, int size, t_img *frame)
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
				ft_render_cube_empty(ft_pos(y * size + pos.y, x * size + pos.x), size, COLOR_GROUND, frame);
			if (map[y][x] == ' ')
				ft_render_cube_empty(ft_pos(y * size + pos.y, x * size + pos.x), size, COLOR_SPACE, frame);
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
				ft_render_cube_wall(ft_pos(y * size + pos.y, x * size + pos.x), size, COLOR_WALL, frame);
			x++;
		}
		y++;
	}
}

void	ft_render_player_fov(t_pos pos, t_coord coord, t_data *data)
{
	t_coord coord_list[3];
	t_pos pos_list[3];
	t_pos camera_pos;

	coord_list[0].y = coord.y - DIR_VECTOR_LEN;
	coord_list[0].x = coord.x;

	coord_list[0] = ft_rotate_point(coord, coord_list[0], data->camera.dir_angle);
	coord_list[1] = ft_rotate_point(coord, coord_list[0], FOV / 2);
	coord_list[2] = ft_rotate_point(coord, coord_list[0], -(FOV / 2));

	camera_pos = ft_coord_to_pos(coord);
	pos_list[0] = ft_coord_to_pos(coord_list[0]);
	pos_list[1] = ft_coord_to_pos(coord_list[1]);
	pos_list[2] = ft_coord_to_pos(coord_list[2]);

	camera_pos.x += pos.x;
	camera_pos.y += pos.y;
	pos_list[0].x += pos.x;
	pos_list[0].y += pos.y;
	pos_list[1].x += pos.x;
	pos_list[1].y += pos.y;
	pos_list[2].x += pos.x;
	pos_list[2].y += pos.y;

	ft_render_line_pos(camera_pos, pos_list[0], COLOR_PLAYER_DIR, data->frame.game);
	ft_render_line_pos(camera_pos, pos_list[1], COLOR_FOV, data->frame.game);
	ft_render_line_pos(camera_pos, pos_list[2], COLOR_FOV, data->frame.game);
}

void	ft_render_ray(t_coord coord, t_ray ray, t_data *data)
{
	t_coord fake_impact;

	if(ray.impact == NULL)
	{
		fake_impact.y = coord.y - DIR_VECTOR_LEN;
		fake_impact.x = coord.x;
		fake_impact = ft_rotate_point(coord, fake_impact, ray.angle + data->camera.dir_angle);
		ft_render_one_px(ft_coord_to_pos(fake_impact), COLOR_COLLISION, data->frame.game);
		ft_render_line_coord(coord, fake_impact, COLOR_RAY, data->frame.game);
	}
	else
	{
		ft_render_one_px(ft_coord_to_pos(ray.impact->coord), COLOR_COLLISION, data->frame.game);
		ft_render_line_coord(coord, ray.impact->coord, COLOR_RAY, data->frame.game);
	}
}

void	ft_render_rays(t_data *data)
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

void	ft_fdf_render(t_data *data)
{
	ft_render_grid(ft_pos(0,0),data->map, MINIMAP_RENDER_SIZE, data->frame.game);
	ft_render_player_fov(ft_pos(0,0), data->camera.coord, data);

	int i = 0;
	while (++i < WINDOW_WIDTH)
		ft_calculate_impact_point(data->camera.coord,
			&data->camera.ray_list[i], data);

	//ft_render_rays(data);
}
