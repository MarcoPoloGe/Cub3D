/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:36:07 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/08 14:15:49 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_ray_list_impact(t_data *data)
{
	int	i;

	if (data->camera.ray_list)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
			free(data->camera.ray_list[i].impact);
	}
}

int	leave_simple(t_data *data)
{
	leave(data, NULL);
	return (0);
}

int	leave(t_data *data, char *errormsg)
{
	if (data && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (errormsg != 0)
		ft_putstr_fd(errormsg, 2);
	if (data)
		free_all(data);
	exit(0);
}

void	ft_free_img(t_data *data)
{
	if (data->assets.no.ptr)
	{
		mlx_destroy_image(data->mlx, data->assets.no.ptr);
	}
	if (data->assets.so.ptr)
	{
		mlx_destroy_image(data->mlx, data->assets.so.ptr);
	}
	if (data->assets.we.ptr)
	{
		mlx_destroy_image(data->mlx, data->assets.we.ptr);
	}
	if (data->assets.ea.ptr)
	{
		mlx_destroy_image(data->mlx, data->assets.ea.ptr);
	}
}

void	free_all(t_data *data)
{
	int	i;

	ft_free_img(data);
	if (data->map)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	if (data->frame.game)
		free(data->frame.game);
	if (data->frame.overlay)
		free(data->frame.overlay);
	if (data->frame.minimap)
		free(data->frame.minimap);
	ft_free_ray_list_impact(data);
	free(data->camera.ray_list);
}
