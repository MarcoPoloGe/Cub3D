
#include "cub3D.h"
//dessine une copy de l'image
int	render_image(t_img *img, t_img *color)
{
	int	y;
	int	x;
	int	distance;

	distance = 8;
	y = 0;
	while (y < color->height / distance)
	{
		x = 0;
		while (x < color->width / distance)
		{
			img->addr[(y * img->width) + x]
					= color->addr[((y * distance) * color->width) + (x * distance)];
			x++;
			//printf("%d/%d, %d/%d\n", y, color->height, x, color->width);
		}
		++y;
	}
	return (0);
}

//try de dessiner l'image en plus petit
int	render_rect(t_img *img, t_img *color, int line_to_render, int distance)
{
	int	y;
	int	x;
	int	i;
	int	j;

	//distance /= 2;
	(void) line_to_render;
	x = 0;
	j = (WINDOW_WIDTH / 2) - ((color->width / distance) / 2);
	i = (WINDOW_HEIGHT / 2) - (color->height / distance / 2);
	y = 0;
	while (i < (WINDOW_HEIGHT / 2) + (color->height / distance / 2))
	{
		img->addr[(i * img->width) + j]
				= color->addr[((y * distance) * color->width) + (x * distance)];
		++y;
		++i;
	}
	return (0);
}

void	render_line(t_img *line, t_img *wall, int line_to_render, int distance)
{
	int	y;
	int	x;
	int	i;
	int	j;

	distance *= -1;
	distance /= 24;
	x = 0;
	j = (WINDOW_WIDTH / 2) - ((wall->width / distance) / 2);
	i = (WINDOW_HEIGHT / 2) - (wall->height / distance / 2);
	y = 0;
	while (i < (WINDOW_HEIGHT / 2) + (wall->height / distance / 2))
	{
		line->addr[(i * line->width) + j]
				= wall->addr[((line_to_render * distance) * wall->width) + (x * distance)];
		++y;
		++i;
	}
}
