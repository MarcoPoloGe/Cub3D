/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:04:05 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/09/01 13:53:20 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_player_count_bad(char **map)
{
	int	player_count;
	int	x;
	int	y;

	player_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S')
				player_count++;
			if (map[y][x] == 'E' || map[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count == 1)
		return (0);
	else
		return (1);
}

int	ft_forbiden_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E'
				&& map[y][x] != 'W' && map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != ' ')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_no_wall_space_around(char **map, int y, int x)
{
	if (y > 0 && x < ft_strlen(map[y - 1]))
	{
		if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
			return (1);
	}
	if (x > 0)
	{
		if (map[y][x - 1] != ' ' && map[y][x - 1] != '1')
			return (1);
	}
	if (map[y + 1] && x < ft_strlen(map[y + 1]))
	{
		if (map[y + 1][x] != ' ' && map[y + 1][x] != '1')
			return (1);
	}
	if (map[y][x + 1])
	{
		if (map[y][x + 1] != ' ' && map[y][x + 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_space_no_border(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
			{
				if (ft_no_wall_space_around(map, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_end_no_border(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
			{
				if (y == 0 || x == 0)
					return (1);
				if (y == ft_tablen(map) - 1 || x == ft_strlen(map[y]) - 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
