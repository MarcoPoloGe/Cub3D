/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:10:57 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 12:12:28 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	int		offset;
	t_pos	fill_pos;

	offset = size / 10;
	fill_pos.x = pos.x + offset;
	fill_pos.y = pos.y + offset;
	ft_render_cube_empty(pos, size, color, frame);
	ft_render_cube_filled(fill_pos, size - offset * 2 + 1, color, frame);
}
