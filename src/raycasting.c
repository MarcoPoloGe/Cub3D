/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:16:04 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/26 15:32:33 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
//dessine une copy de l'image
int	render_image(t_img *img, t_img *color)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img->addr[(y * img->width) + x] = color->addr[((y * color->width)) + x];
			x++;
		}
		++y;
	}
	return (0);
}

//try de dessiner l'image en plus petit
int	render_rect(t_img *img, t_img *color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->line_size / 4)
	{
		j = -1;
		while (j < img->line_size / 4 && (i * img->line_size / 4 + j) < (img->line_size / 4 * img->line_size / 4))
		{
			img->addr[i * img->line_size / 4 + j] = color->addr[i
				* color->line_size + j * (img->bpp / 8)];
				j++;
		}
		i++;
	}
	return (0);
}

void	render_line(t_img *line, t_img *wall, int line_to_render)
{
	int	y;

	y = 0;
	while (y < line->height)
	{
		(void)line_to_render;
		line->addr[y] = wall->addr[1]; //todo here should do calculation to choose which pixel use for the line displayed ex: line height is 64 but original image is 100;
		++y;
	}
}

void	display_line(t_data *data, t_img *wall, int line_to_render, int pos_y, int pos_x, int len) //should be called display_wall_vertical_line()
{
	t_img	line;

	ft_new_image(&line, 1, len, data);
	render_line(&line, wall, line_to_render);
	mlx_put_image_to_window(data->mlx, data->win, line.ptr, pos_x, pos_y);
	mlx_destroy_image(data->mlx, line.ptr);
}

int	load_texture(t_data *data)
{
	int		i;

	render_background(&(data->frame), data->assets);
	i = 30;
	while (i < 100)
	{
		display_line(data, &data->assets.no, 0, (100 - (i / 2)), i, i);
		i++;
	}
	return (0);
}
