#include "cub3D.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	render_rectangle(t_img *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img->addr[(y * img->width) + x] = color;
			x++;
		}
		++y;
	}
	return (0);
}

void display_rectangle(t_data *data, int pos_y, int pos_x, int height, int width, int color)
{
	t_img rect;

	ft_new_image(&rect, width, height, data);
	render_rectangle(&rect, color);
	mlx_put_image_to_window(data->mlx, data->win, rect.ptr, pos_x , pos_y);
	mlx_destroy_image(data->mlx,rect.ptr);
}

//dessine le top et bot en couleur
void	render_background(t_data *data)
{
	display_rectangle(data, 0 ,0 , WINDOW_HEIGHT / 2 , WINDOW_WIDTH , 0x00FF0000);
	display_rectangle(data, WINDOW_HEIGHT / 2 , 0 , WINDOW_HEIGHT / 2 ,WINDOW_WIDTH , 0x000000FF);
}
