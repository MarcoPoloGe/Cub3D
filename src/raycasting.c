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

//try de dessiner l'image en plus petit
int	render_rect_old(t_img *img, t_img *color)
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

void render_line(t_img *line, t_img *wall, int line_to_render)
{
	int y;

	y = 0;
	while (y < line->height)
	{
		(void)line_to_render;
		line->addr[y] = wall->addr[1]; //todo here should do calculation to choose which pixel use for the line displayed ex: line height is 64 but original image is 100;
		++y;
	}
}

void display_line(t_data *data, t_img *wall, int line_to_render, int pos_y, int pos_x, int len)
{
	t_img line;

	line.width = 1;
	line.height = len;
	line.img = mlx_new_image(data->mlx, line.width, line.height);
	if (!(line.img))
		leave(data, "Error: no img\n");
	line.addr = (int *)mlx_get_data_addr(line.img, &line.bpp,
										&line.line_size, &line.endian);
	data->no.addr = (int *)mlx_get_data_addr(data->no.img, &data->no.bpp,
											 &data->no.line_size, &data->no.endian);
	render_line(&line, wall, line_to_render);
	mlx_put_image_to_window(data->mlx, data->win, line.img, pos_x , pos_y);
}


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

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

//dessine le top et bot en couleur
void	render_background(t_img *img, int *f, int *c)
{
	int	i;

	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
		img->addr[i] = encode_rgb(f[0], f[1], f[2]);
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT)
		img->addr[i] = encode_rgb(c[0], c[1], c[2]);
}

int	load_texture(t_data *data)
{
	int		i;
	int		j;
	double	d;

	i = (int)data->pos.y;
	j = (int)data->pos.x;
	d = 0;
	/*while (i >= 0 && data->map[i][j] && data->map[i][j] != 1)
		i--;
	d = pow((data->pos.x - i), 2) + pow((data->pos.y - j), 2);*/
	tmp.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(tmp.img))
		leave(data, "Error: no img\n");
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.bpp,
			&tmp.line_size, &tmp.endian);
	render_background(&tmp, data->f, data->c);
	data->no.addr = (int *)mlx_get_data_addr(data->no.img, &data->no.bpp,
			&data->no.line_size, &data->no.endian);

	i = 30;
	while (i < 100)
	{
		display_line(data, &data->no, 0, (100 - (i / 2)), i, i);
		i++;
	}
	//render_image(&tmp, &data->no);
//	mlx_put_image_to_window(data->mlx, data->win, tmp.img, 0, 0);
	return (0);
}
