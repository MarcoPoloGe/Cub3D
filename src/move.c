/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:25:41 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:04 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_camera(t_camera *camera, double angle)
{
	camera->dir_angle += angle;
	if (camera->dir_angle < 0)
		camera->dir_angle += 360;
	if (camera->dir_angle >= 360)
		camera->dir_angle -= 360;
}

void	ft_move_player(double move, t_camera *camera)
{
	t_coord	next_coord;
	t_coord	coord;

	coord = camera->coord;
	next_coord.y = coord.y + move;
	next_coord.x = coord.x;
	next_coord = ft_rotate_point(coord, next_coord, camera->dir_angle);
	camera->coord = next_coord;
}

int	keycode_handling(int keycode, t_data *data)
{
	t_camera	*camera;
	int			i;

	camera = &(data->camera);
	if (keycode == 53)
		leave(data, 0);
	if (keycode == 0)
		ft_rotate_camera(camera, -10);
	if (keycode == 2)
		ft_rotate_camera(camera, 10);
	if (keycode == 1)
		ft_move_player(0.5, camera);
	if (keycode == 13)
		ft_move_player(-0.5, camera);
	i = -1;
	return (0);
}
