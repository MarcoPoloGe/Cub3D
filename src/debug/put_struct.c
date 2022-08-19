/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:58:19 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/08/17 16:57:49 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

void	ft_put_map(char **map)
{
	int	x;
	int	y;

	if (map == NULL)
	{
		printf("data.map = NULL;\n");
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

void	ft_put_img(t_img *img)
{
	if (img == NULL)
	{
		printf("img = NULL;\n");
		return ;
	}
	printf("img.ptr = %p\n", img->ptr);
	printf("img.width = %i\n", img->width);
	printf("img.height = %i\n", img->height);
	printf("img.addr = %p\n", img->addr);
	printf("img.bpp = %i\n", img->bpp);
	printf("img.line_size = %i\n", img->line_size);
	printf("img.endian = %i\n", img->endian);
}

void	ft_put_assets(t_assets assets)
{
	printf("c = %i,%i,%i\n", assets.c[0], assets.c[1], assets.c[2]);
	printf("f = %i,%i,%i\n", assets.f[0], assets.f[1], assets.f[2]);
	printf("no.img.ptr = %p\n", assets.no.ptr);
	printf("so.img.ptr = %p\n", assets.so.ptr);
	printf("we.img.ptr = %p\n", assets.we.ptr);
	printf("ea.img.ptr = %p\n", assets.ea.ptr);
}

void	ft_impact(t_impact *impact)
{
	if (impact != 0)
	{
		printf("impact.coord.y: %fl\n", impact->coord.y);
		printf("impact.coord.x: %fl\n", impact->coord.x);
		printf("impact.distance: %fl\n", impact->coord.y);
		printf("impact.wall: %p\n", impact->wall->ptr);
		printf("impact.wall_x: %i\n", impact->wall_x);
	}
}

void	ft_put_ray(t_ray ray)
{
	printf("ray.angle: %fl\n", ray.angle);
	printf("ray.");
	ft_impact(ray.impact);
}

void	ft_put_camera(t_camera camera)
{
//	int	i;

	printf("camera.coord.y: %fl\n", camera.coord.y);
	printf("camera.coord.x: %fl\n", camera.coord.x);
	printf("camera.dir_angle: %fl\n", camera.dir_angle);
	//i = 0;
	//while (i < WINDOW_WIDTH)
//	{
//		ft_put_ray(camera.ray_list[i]);
//		i++;
//	}
}

void	ft_put_data(t_data *data)
{
	if (data == NULL)
		return ;
	printf("--- Start Struct Data ---\n");
	printf("data.mlx = %p\n", data->mlx);
	printf("data.win = %p\n", data->win);
	ft_put_camera(data->camera);
	ft_put_assets(data->assets);

	ft_put_map(data->map);
	printf("--- End Struct Data ---\n");
}
