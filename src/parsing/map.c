/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:38:45 by Marco Belar       #+#    #+#             */
/*   Updated: 2022/08/18 10:27:48 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

void	ft_init_player_info(int y, int x, char dir_char, t_camera *camera)
{
	camera->coord.x = (double)x + 0.5;
	camera->coord.y = (double)y + 0.5;
	if (dir_char == 'N')
	{
		camera->dir_angle = 0;
	}
	else if (dir_char == 'S')
	{
		camera->dir_angle = 180;
	}
	else if (dir_char == 'E')
	{
		camera->dir_angle = 90;
	}
	else if (dir_char == 'W')
	{
		camera->dir_angle = 270;
	}
}

void	ft_get_player_infos(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				ft_init_player_info(y, x, map[y][x], &(data->camera));
			}
			x++;
		}
		y++;
	}
}

char **ft_make_map_rectangular(char **map)
{
	int len;
	int max_len;
	int i;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if(max_len < len)
			max_len = len;
	    i++;
	}
	i = 0;
	while(map[i])
	{
		while (ft_strlen(map[i]) < max_len)
			ft_stradd(map + i, " ");
		i++;
	}
	return (map);
}

int	ft_get_map(char **input_tab, t_data *data)
{
	data->map = ft_tabdup(input_tab);
	data->map = ft_make_map_rectangular(data->map);
	data->map_height = ft_tablen(data->map);
	data->map_width = ft_strlen(data->map[0]);
	if (ft_check_map(data->map))
		leave(data, "Error : map invalid\n");
	return (ft_tablen(data->map));
}
