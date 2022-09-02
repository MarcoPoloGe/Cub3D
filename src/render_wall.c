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

void	render_line(t_img *line, t_img *wall, int line_to_render, int distance)
{
	int y;
	int x;
	int i;
	int j;

	if (distance < 0)
		distance *= -1;
	distance /= 24;
	x = 0;
	j = (WINDOW_WIDTH / 2) - (wall->width / distance / 2);
	i = (WINDOW_HEIGHT / 2) - (wall->height / distance / 2);
	y = 0;
	while (i < (WINDOW_HEIGHT / 2) + (wall->height / distance / 2))
	{
		line->addr[(i * line->width) + j] = wall->addr[
				((line_to_render * distance) * wall->width) + (x * distance)];
		++y;
		++i;
	}
}


double ft_invert_percent(double percent)
{
	double invert;

	invert = 100 - percent;

	return (invert);
}

double ft_get_percent(double nb, double total)
{
	double percent;

	percent = nb * 100 / total;

	return (percent);
}

double ft_get_nb_from_percent(double percent, double total)
{
	double nb;

	nb = percent * total / 100;

	return (nb);
}

int ft_get_wall_color(int wall_y, int wall_x, t_img *wall)
{
	int color;
	(void)wall_x;
	(void)wall_y;
	(void)wall;

	if (wall_x < wall->width && wall_y < wall->height && wall_x > 0 && wall_y > 0)
		color = wall->addr[(wall_y * wall->width) + wall_x];
	else
		color = COLOR_COLLISION;
	return (color);
}

void	ft_render_wall_line(t_pos pos, t_ray ray, t_data *data)
{
	t_impact *impact;
	t_img *frame;
	int i;
//	double percent_y;
	double step_y;
	double wall_height;
	double correct_distance;

	frame = data->frame.game;
	impact = ray.impact;

	correct_distance = impact->distance; // * cos(ft_degrees_to_radian(ray.angle));

	wall_height = WINDOW_HEIGHT / (correct_distance);

/*	printf("%lf, correct : %fl , distance : %fl\n", ray.angle, correct_distance, impact->distance);
	percent_y = ft_get_percent(correct_distance, 30);
	percent_y = ft_invert_percent(percent_y); //20%
	wall_height = ft_get_nb_from_percent(percent_y, WINDOW_HEIGHT);*/

	step_y = impact->wall->height / wall_height;

	//printf("percent_y = %f\n", percent_y);

	pos.y -= (wall_height / 2);
	i = 0;
	while (i < wall_height)
	{
		ft_put_pixel_frame(frame, pos.y + i, pos.x, ft_get_wall_color(i * step_y, impact->wall_x, impact->wall));
		printf("wall_x: %f\n", impact->wall_x);
		i++;
	}
}

void	ft_render_walls(t_camera camera, t_data *data)
{
	int i;
	t_ray *ray_list;

	ray_list = camera.ray_list;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		if(ray_list[i].impact != NULL)
			ft_render_wall_line(ft_pos(WINDOW_HEIGHT / 2, i), ray_list[i], data);
		i++;
	}
}

