/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:46:46 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/08 14:08:01 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel_frame(t_img *frame, int y, int x, int color)
{
	if (x < frame->width && y < frame->height && x > 0 && y > 0)
		frame->addr[((y) * frame->width) + (x)] = color;
}

void	ft_reset_frame(t_img *frame)
{
	int	y;
	int	x;

	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			ft_put_pixel_frame(frame, y, x, 0);
			x++;
		}
		y++;
	}
}

void	ft_push_frame(t_pos pos, t_img *frame, t_data *data, int reset)
{
	mlx_put_image_to_window(data->mlx, data->win, frame->ptr, pos.x, pos.y);
	if (reset)
		ft_reset_frame(frame);
}

void	ft_calculate_rays(t_data *data)
{
	int	i;

	i = -1;
	while (++i < WINDOW_WIDTH)
		ft_calculate_impact_point(data->camera.coord,
			&data->camera.ray_list[i], data);
}

int	ft_display_game(t_data *data)
{
	t_pos	minimap_pos;
	int		minimap_size;
	int		i;

	minimap_pos = ft_pos(590, 1200);
	minimap_size = 200;
	mlx_clear_window(data->mlx, data->win);
	if (data->frame.overlay == 0)
	{
		data->frame.overlay = ft_calloc(sizeof(t_img), 1);
		ft_file_to_image(MINIMAP_OVERLAY, data->frame.overlay, data);
	}
	if (data->frame.minimap == 0)
	{
		data->frame.minimap = ft_calloc(sizeof(t_img), 1);
		ft_new_image(data->frame.minimap, minimap_size, minimap_size, data);
	}
	ft_minimap_render(data->frame.minimap, data);
	render_background(data->frame.game, data->assets);
	if (data->camera.ray_list)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
			free(data->camera.ray_list[i].impact);
	}
	ft_calculate_rays(data);
	ft_render_walls(data->camera, data);
	ft_push_frame(ft_pos(0, 0), data->frame.game, data, 1);
	ft_push_frame(minimap_pos, data->frame.minimap, data, 1);
	ft_push_frame(ft_pos(minimap_pos.y - 120, minimap_pos.x -210),
		data->frame.overlay, data, 0);
	return (0);
}
