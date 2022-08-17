#include "cub3D.h"

void	ft_put_pixel_frame(t_img *frame, int y, int x, int color)
{
	if(x < frame->width && y < frame->height && x > 0 && y > 0)
		frame->addr[((y) * frame->width) + (x)] = color;
}

void ft_reset_frame(t_img *frame)
{
	int	y;
	int	x;

	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			ft_put_pixel_frame(frame, y, x, 0);
			x++;
		}
		y++;
	}
}

void ft_push_frame(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
	ft_reset_frame(&(data->frame));
}
