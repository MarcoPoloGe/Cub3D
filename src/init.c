/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:04:17 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/07 15:27:58 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_camera(t_camera *camera)
{
	camera->ray_list = 0;
	camera->dir_angle = 0;
	camera->coord.y = 0;
	camera->coord.x = 0;
}

void	init_frame(t_frame *frame, t_data *data)
{
	frame->game = ft_calloc(sizeof(t_img), 1);
	ft_new_image(frame->game, WINDOW_WIDTH, WINDOW_HEIGHT, data);
	frame->overlay = 0;
	frame->minimap = 0;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	init_frame(&(data->frame), data);
	init_assets(&(data->assets));
	init_camera(&(data->camera));
	init_rays(&(data->camera), data);
	data->map = 0;
	data->map_height = 0;
	data->map_width = 0;
}

t_ray	*init_rays(t_camera *camera, t_data *data)
{
	t_ray	*ray_list;
	double	angle;
	int		i;

	ray_list = malloc(sizeof(t_ray) * (WINDOW_WIDTH));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		(void)data;
		angle = -(FOV / 2) + ((double)FOV / (double)WINDOW_WIDTH * (double)i);
		ray_list[i].angle = angle;
		ray_list[i].impact = 0;
	}
	camera->ray_list = ray_list;
	return (camera->ray_list);
}
