/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:48:06 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 13:51:00 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_render_player_arrow(t_pos pos, double dir_angle, t_img *frame)
{
	t_coord	temp;
	t_pos	dir;
	t_pos	side;

	temp = ft_rotate_point(ft_coord(pos.y, pos.x),
			ft_coord(pos.y - (DIR_VECTOR_LEN / 2), pos.x), dir_angle);
	dir.x = temp.x;
	dir.y = temp.y;
	temp = ft_rotate_point(ft_coord(pos.y, pos.x),
			ft_coord(pos.y - (DIR_VECTOR_LEN / 3), pos.x), dir_angle + 135);
	side.x = temp.x;
	side.y = temp.y;
	ft_render_line_pos(pos, side, COLOR_PLAYER_DIR, frame);
	ft_render_line_pos(dir, side, COLOR_PLAYER_DIR, frame);
	temp = ft_rotate_point(ft_coord(pos.y, pos.x),
			ft_coord(side.y, side.x), 90);
	side.x = temp.x;
	side.y = temp.y;
	ft_render_line_pos(pos, side, COLOR_PLAYER_DIR, frame);
	ft_render_line_pos(dir, side, COLOR_PLAYER_DIR, frame);
}

void	ft_minimap_render(t_img *minimap, t_data *data)
{
	t_pos	cam_pos;
	t_pos	pos_map;
	t_pos	pos_player;

	cam_pos = ft_coord_to_pos(data->camera.coord);
	pos_map = ft_pos(0, 0);
	pos_map.y -= cam_pos.y;
	pos_map.x -= cam_pos.x;
	pos_map.y += minimap->height / 2;
	pos_map.x += minimap->height / 2;
	pos_player = ft_pos(0, 0);
	pos_player.y += minimap->height / 2;
	pos_player.x += minimap->height / 2;
	ft_render_grid(pos_map, data->map, MINIMAP_RENDER_SIZE, minimap);
	ft_render_player_arrow(pos_player, data->camera.dir_angle, minimap);
}
