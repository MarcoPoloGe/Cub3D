/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:16:04 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/26 13:21:57 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	int	*pixel;
	int	i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

//try de dessiner l'image en plus petit
int	render_rect(t_img *img, t_img *color)
{
	int	i;
	int	j;

	i = 0;
	while (i < (img->line_size / 4) / 4)
	{
		j = -1;
		while (j < img->line_size / 4 && (i * img->line_size + j) < (img->line_size / 4 * img->line_size / 4))
		{
			img->addr[i * img->line_size + j - i] = color->addr[i
				* color->line_size + j * (color->bpp / 16)];
				j++;
		}
		++i;
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
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, encode_rgb(f[0], f[1], f[2]));
		++i;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, encode_rgb(c[0], c[1], c[2]));
		++i;
	}
}

int	load_texture(t_data *data)
{
	int		i;
	int		j;
	double	d;
	t_img	tmp;

	i = (int)data->pos.y;
	j = (int)data->pos.x;
	d = 0;
	/*while (i >= 0 && data->map[i][j] && data->map[i][j] != 1)
		i--;
	d = pow((data->pos.x - i), 2) + pow((data->pos.y - j), 2);*/
	/*tmp.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(tmp.img))
		leave(data, "Error: no img\n");
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.bpp,
			&tmp.line_size, &tmp.endian);
	render_background(&tmp, data->f, data->c);*/


	tmp.img = mlx_new_image(data->mlx, 700, 700);
	if (!(tmp.img))
		leave(data, "Error: no img\n");
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.bpp,
			&tmp.line_size, &tmp.endian);
	data->no.addr = (int *)mlx_get_data_addr(data->no.img, &data->no.bpp,
			&data->no.line_size, &data->no.endian);
	render_rect(&tmp, &data->no);
	mlx_put_image_to_window(data->mlx, data->win, tmp.img, 0, 0);
	return (0);
}
