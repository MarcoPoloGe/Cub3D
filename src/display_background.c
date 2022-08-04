#include "cub3D.h"

//dessine le top et bot en couleur
void	display_background(t_assets assets, t_data *data)
{
	int		i;
	t_img	img;

	ft_new_image(&img, WINDOW_WIDTH, WINDOW_HEIGHT, data);
	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
		img.addr[i] = encode_rgb(assets.f[0], assets.f[1], assets.f[2]);
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT)
		img.addr[i] = encode_rgb(assets.c[0], assets.c[1], assets.c[2]);
	mlx_put_image_to_window(data->mlx, data->win, img.ptr, 0, 0);
	mlx_destroy_image(data->mlx, img.ptr);
}
