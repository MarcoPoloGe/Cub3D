/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:36:07 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:17 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_free_img(t_img *img, t_data *data)
{
	mlx_destroy_image(data->mlx, img->ptr);
	free(img);
}

void	free_all(t_data *data)
{
	int	i;

	if (data->assets.no.ptr)
		free(data->assets.no.ptr);
	if (data->assets.so.ptr)
		free(data->assets.so.ptr);
	if (data->assets.we.ptr)
		free(data->assets.we.ptr);
	if (data->assets.ea.ptr)
		free(data->assets.ea.ptr);
	if (data->map)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
}
