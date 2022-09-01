/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:08:58 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 12:10:54 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

void	init_render_line(t_pos start, t_pos end, int *points)
{
	points[0] = abs(end.x - start.x);
	points[1] = -abs(end.y - start.y);
	if (start.x < end.x)
		points[2] = 1;
	else
		points[2] = -1;
	if (start.y < end.y)
		points[3] = 1;
	else
		points[3] = -1;
	points[4] = points[0] + points[1];
}

void	ft_render_line_pos(t_pos start, t_pos end, int color, t_img *frame)
{
	int	points[6];

	init_render_line(start, end, points);
	while (1)
	{
		ft_put_pixel_frame(frame, start.y, start.x, color);
		if (start.y == end.y && start.x == end.x)
			break ;
		points[5] = 2 * points[4];
		if (points[5] >= points[1])
		{
			points[4] += points[1];
			start.x += points[2];
		}
		if (points[5] <= points[0])
		{
			points[4] += points[0];
			start.y += points[3];
		}
	}
}

void	ft_render_line_coord(t_coord start_coord, t_coord end_coord,
		int color, t_img *frame)
{
	t_pos	start_pos;
	t_pos	end_pos;

	start_pos = ft_coord_to_pos(start_coord);
	end_pos = ft_coord_to_pos(end_coord);
	ft_render_line_pos(start_pos, end_pos, color, frame);
}
