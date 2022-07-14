/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:26:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/14 14:38:42 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*ft_new_image(char *path, t_data *data)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path,
			&data->img.width, &data->img.height);
	return (img);
}

void	load_img(t_data *data)
{
	data->img.no = ft_new_image("./assets/star1.xpm", data);
	data->img.so = ft_new_image("./assets/star2.xpm", data);
	data->img.we = ft_new_image("./assets/star3.xpm", data);
	data->img.ea = ft_new_image("./assets/star4.xpm", data);
}

int	main(int ac, char **av)
{
	//t_data	data;
	(void)av;

	if (ac != 2)
	{
		leave(0, "Error: not enought argument\n");
		return (0);
	}
	/*data.pos.x = 0;
	data.pos.y = 0;
	data.map.map = ft_calloc(sizeof(char), 1);
	data.mlx = mlx_init();
	load_img(&data);
	//load_map(&data, av[1]);
	data.win = mlx_new_window(data.mlx, data.map.width * 50,
			data.map.height * 50, "Marco3D");
	data.img.img = mlx_new_image(data.mlx, data.map.width * 50,
			data.map.height * 50);
	//is_valid_map(data.map.map, data.map.width, data.map.height);
	//print_map(&data, 0, 0);
	if (!(data.img.img))
		leave(&data, "Error\nno img");
	result += mlx_hook(data.win, 2, 1L << 0, move_character, &data);
	mlx_hook(data.win, 17, 1L << 0, leave, &data);
	mlx_loop(data.mlx);*/
}