/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:36:07 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/14 15:06:59 by ktrosset         ###   ########.fr       */
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

void	free_all(t_data *data)
{
	int	i;

	if (data->img.no)
		free(data->img.no);
	if (data->img.so)
		free(data->img.so);
	if (data->img.we)
		free(data->img.we);
	if (data->img.ea)
		free(data->img.ea);
	if (data->map)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
}
