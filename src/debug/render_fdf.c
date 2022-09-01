/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:41:24 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 12:15:02 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

void	ft_render_grid_empty(t_pos pos, char **map, int size, t_img *frame)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0')
				ft_render_cube_empty(ft_pos(y * size + pos.y,
						x * size + pos.x), size, COLOR_GROUND, frame);
			if (map[y][x] == ' ')
				ft_render_cube_empty(ft_pos(y * size + pos.y,
						x * size + pos.x), size, COLOR_SPACE, frame);
		}
	}
}

void	ft_render_grid(t_pos pos, char **map, int size, t_img *frame)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '1')
				ft_render_cube_wall(ft_pos(y * size + pos.y,
						x * size + pos.x), size, COLOR_WALL, frame);
	}
}

void	ft_render_player_fov(t_pos pos, t_coord coord, t_data *data)
{
	t_coord	coord_list[3];
	t_pos	pos_list[3];
	t_pos	camera_pos;

	coord_list[0].y = coord.y - DIR_VECTOR_LEN;
	coord_list[0].x = coord.x;
	coord_list[0] = ft_rotate_point(coord, coord_list[0],
			data->camera.dir_angle);
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
	ft_render_line_pos(camera_pos, pos_list[0], COLOR_PLAYER_DIR,
		data->frame.game);
	ft_render_line_pos(camera_pos, pos_list[1], COLOR_FOV, data->frame.game);
	ft_render_line_pos(camera_pos, pos_list[2], COLOR_FOV, data->frame.game);
}

void	ft_fdf_render(t_data *data)
{
	int	i;

	ft_render_grid_empty(ft_pos(0, 0), data->map, MINIMAP_RENDER_SIZE,
		data->frame.game);
	ft_render_grid(ft_pos(0, 0), data->map, MINIMAP_RENDER_SIZE,
		data->frame.game);
	ft_render_player_fov(ft_pos(0, 0), data->camera.coord, data);
	i = -1;
	while (++i < WINDOW_WIDTH)
		ft_calculate_impact_point(data->camera.coord,
			&data->camera.ray_list[i], data);
}
