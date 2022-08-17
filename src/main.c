/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:26:38 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/17 15:25:53 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		leave(0, "Error: not enough argument\n");

	init_data(&data);
	ft_parser(av[1], &data);
	ft_put_data(&data);

	load_texture(&data);
	mlx_loop_hook(data.mlx, ft_fdf_render, &data);

	mlx_hook(data.win, 2, 1L << 1, keycode_handling, &data);
	mlx_hook(data.win, 17, 1L << 0, leave, &data);
	mlx_loop(data.mlx);
}
