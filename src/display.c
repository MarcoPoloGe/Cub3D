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
	printf("Img.img = %p;\n", img->img);
	printf("Img.width = %i;\n", img->width);
	printf("Img.height = %i\n", img->height);
	printf("Img.c = %i,%i,%i;\n", img->c[0], img->c[1], img->c[2]);
	printf("Img.f = %i,%i,%i;\n", img->f[0], img->f[1], img->f[2]);
	printf("Img.no = %s;\n", img->no);
	printf("Img.so = %s;\n", img->so);
	printf("Img.we = %s;\n", img->we);
	printf("Img.ea = %s;\n", img->ea);
}

void	ft_display_data(t_data *data)
{
	printf("--- Struct Data ---\n");
	printf("data.mlx = %p;\n", data->mlx);
	printf("data.win = %p;\n", data->win);
	printf("Struct pos : y = %fl, x = %fl;\n", data->pos.y, data->pos.x);
	ft_display_img(&(data->img));
	ft_display_map(data->map);
}
