/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:25:41 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/02 11:56:49 by ktrosset         ###   ########.fr       */
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

void	ft_move_player(t_data *data, double move, t_camera *camera)
{
	t_coord	next_coord;
	t_coord	coord;
	(void)data;
	coord = camera->coord;
	//if (coord.y + move)
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
	if (keycode == 0 || keycode == 123)
		ft_rotate_camera(camera, -10);
	if (keycode == 2 || keycode == 124)
		ft_rotate_camera(camera, 10);
	if (keycode == 1 || keycode == 125)
		ft_move_player(data, 0.5, camera);
	if (keycode == 13 || keycode == 126)
		ft_move_player(data, -0.5, camera);
	i = -1;
	return (0);
}
