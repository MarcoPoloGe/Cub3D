/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:13:29 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 12:14:48 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_render_ray(t_coord coord, t_ray ray, t_data *data)
{
	t_coord	fake_impact;

	if (ray.impact == 0)
	{
		fake_impact.y = coord.y - DIR_VECTOR_LEN;
		fake_impact.x = coord.x;
		fake_impact = ft_rotate_point(coord, fake_impact,
				ray.angle + data->camera.dir_angle);
		ft_render_one_px(ft_coord_to_pos(fake_impact),
			COLOR_COLLISION, data->frame.game);
		ft_render_line_coord(coord, fake_impact, COLOR_RAY, data->frame.game);
	}
	else
	{
		ft_render_one_px(ft_coord_to_pos(ray.impact->coord),
			COLOR_COLLISION, data->frame.game);
		ft_render_line_coord(coord, ray.impact->coord,
			COLOR_RAY, data->frame.game);
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
