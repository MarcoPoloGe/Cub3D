/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:26:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/22 14:18:03 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*check_keycode(int keycode, t_data *data, void *img)
{
	if (keycode == 53)
		leave(data, 0);
	if (keycode == 0)
	{
		data->pos.x -= 0.1;
		img = data->we.img;
	}
	if (keycode == 2)
	{
		data->pos.x += 0.1;
		img = data->ea.img;
	}
	if (keycode == 1)
	{
		data->pos.y += 0.1;
		img = data->no.img;
	}
	if (keycode == 13)
	{
		data->pos.y -= 0.1;
		img = data->so.img;
	}
	return (img);
}

int	move_character(int keycode, t_data *data)
{
	void	*img;
	int		wall;
	int		x;
	int		y;

	x = data->pos.x;
	y = data->pos.y;
	wall = 0;
	img = 0;
	img = check_keycode(keycode, data, img);
	return (1);
}

void	*ft_new_image(char *path, t_img *img, t_data *data)
{
	void	*res;

	res = mlx_xpm_file_to_image(data->mlx, path,
			&(img->width), &(img->height));
	if (res == 0)
		leave(data, "Error: could not load image\n");
	return (res);
}

void	init_img(t_img *img)
{
	img->img = 0;
	img->width = 0;
	img->height = 0;
	img->addr = 0;
	img->bpp = 0;
	img->line_size = 0;
	img->endian = 0;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->map = 0;
	data->pos.x = 0;
	data->pos.y = 0;
	init_img(&(data->no));
	init_img(&(data->so));
	init_img(&(data->we));
	init_img(&(data->ea));
	data->f[0] = -1;
	data->c[0] = -1;
	data->f[1] = -1;
	data->c[1] = -1;
	data->f[2] = -1;
	data->c[2] = -1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		leave(0, "Error: not enough argument\n");
		return (0);
	}
	init_data(&data);
	ft_display_data(&data);
	ft_parser(av[1], &data);
	ft_display_data(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Marco3D");
	load_texture(&data);
	//mlx_loop_hook(data.mlx, &load_texture, &data);
	mlx_hook(data.win, 2, 1L << 0, move_character, &data);
	mlx_hook(data.win, 17, 1L << 0, leave, &data);
	mlx_loop(data.mlx);
}
