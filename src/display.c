/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:58:19 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/15 14:58:20 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_display_map(char **map)
{
	int	x;
	int	y;

	if (map == NULL)
	{
		printf("map = NULL;\n");
		return ;
	}
	y = 0;
	printf("-- start map --\n");
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("-- end map --\n");
}

void	ft_display_img(t_img *img)
{
	if (img == NULL)
	{
		printf("img = NULL;\n");
		return ;
	}
	printf("img.img = %p;\n", img->img);
	printf("img.width = %i;\n", img->width);
	printf("img.height = %i\n", img->height);
	printf("img.c = %i,%i,%i;\n", img->c[0], img->c[1], img->c[2]);
	printf("img.f = %i,%i,%i;\n", img->f[0], img->f[1], img->f[2]);
	printf("img.no = %p;\n", img->no);
	printf("img.so = %p;\n", img->so);
	printf("img.we = %p;\n", img->we);
	printf("img.ea = %p;\n", img->ea);
}

void	ft_display_data(t_data *data)
{
	if (data == NULL)
		return ;
	printf("--- Start Struct Data ---\n");
	printf("data.mlx = %p;\n", data->mlx);
	printf("data.win = %p;\n", data->win);
	printf("pos.y = %fl;\n", data->pos.y);
	printf("pos.x = %fl;\n", data->pos.x);
	ft_display_img(&(data->img));
	ft_display_map(data->map);
	printf("--- End Struct Data ---\n");
}
