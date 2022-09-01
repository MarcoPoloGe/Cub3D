/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:02:09 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/31 17:02:21 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_file_to_image(char *path, t_img *img, t_data *data)
{
	img->ptr = mlx_xpm_file_to_image(data->mlx, path, &(img->width),
			&(img->height));
	if (img->ptr == 0)
		leave(data, "Error: could not load image\n");
	img->addr = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
}

void	ft_new_image(t_img *img, int width, int height, t_data *data)
{
	img->width = width;
	img->height = height;
	img->ptr = mlx_new_image(data->mlx, img->width, img->height);
	if (!(img->ptr))
		leave(data, "Error: no img\n");
	img->addr = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
}
