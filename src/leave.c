/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:36:07 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/22 14:16:49 by ktrosset         ###   ########.fr       */
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

	if (data->no.img)
		free(data->no.img);
	if (data->so.img)
		free(data->so.img);
	if (data->we.img)
		free(data->we.img);
	if (data->ea.img)
		free(data->ea.img);
	if (data->map)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
}
