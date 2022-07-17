/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:26:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/15 11:58:30 by ktrosset         ###   ########.fr       */
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
		img = data->img.we;
	}
	if (keycode == 2)
	{
		data->pos.x += 0.1;
		img = data->img.ea;
	}
	if (keycode == 1)
	{
		data->pos.y += 0.1;
		img = data->img.no;
	}
	if (keycode == 13)
	{
		data->pos.y -= 0.1;
		img = data->img.so;
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

/*
void	*ft_new_image(char *path, t_data *data)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path,
			&data->img.width, &data->img.height);
	if (img == NULL)
		leave(data, "Error: could not load image\n");
	return (img);
}
*/

void	*ft_new_image(char *path, t_data *data)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path,
			&(data->img.width), &(data->img.height));
	if (img == NULL)
		leave(data, "Error: could not load image\n");
	return (img);
}

void	init_img(t_img *img)
{
	img->img = NULL;
	img->height = 0;
	img->width = 0;
	img->no = 0;
	img->so = 0;
	img->we = 0;
	img->ea = 0;
	//j'ai décider de les mettre a -1 pour signifier qu'il n'ont pas encore été assigné (comme str = NULL)->
	//Vu que des valeurs correctes serait de 0 à 256;
	img->f[0] = -1;
	img->c[0] = -1;
	img->f[1] = -1;
	img->c[1] = -1;
	img->f[2] = -1;
	img->c[2] = -1;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->map = 0;
	data->pos.x = 0;
	data->pos.y = 0;
	init_img(&(data->img));
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
	//load_map(&data, av[1]);

	//data.win = mlx_new_window(data.mlx, 1600, 1200, "Marco3D");


		/*data.img.img = mlx_new_image(data.mlx, data.map.width * 50,
			data.map.height * 50);*/
		//is_valid_map(data.map.map, data.map.width, data.map.height);
		//print_map(&data, 0, 0);
		/*if (!(data.img.img))
			leave(&data, "Error\nno img");*/

		//mlx_hook(data.win, 2, 1L << 0, move_character, &data);
		//mlx_hook(data.win, 17, 1L << 0, leave, &data);
		//mlx_loop(data.mlx);
}
