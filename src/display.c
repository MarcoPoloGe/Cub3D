/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:58:19 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/22 11:32:35 by ktrosset         ###   ########.fr       */
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
	printf("img.addr = %p\n", img->addr);
	printf("img.bpp = %i\n", img->bpp);
	printf("img.line_size = %i\n", img->line_size);
	printf("img.endian = %i\n", img->endian);
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
	printf("c = %i,%i,%i;\n", data->c[0], data->c[1], data->c[2]);
	printf("f = %i,%i,%i;\n", data->f[0], data->f[1], data->f[2]);
	printf("no.img: \n");
	ft_display_img(&(data->no));
	printf("so.img: \n");
	ft_display_img(&(data->so));
	printf("we.img: \n");
	ft_display_img(&(data->we));
	printf("ea.img: \n");
	ft_display_img(&(data->ea));
	ft_display_map(data->map);
	printf("--- End Struct Data ---\n");
}
