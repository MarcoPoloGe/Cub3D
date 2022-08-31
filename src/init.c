#include "cub3D.h"

void	init_img(t_img *img)
{
	img->ptr = 0;
	img->width = 0;
	img->height = 0;
	img->addr = 0;
	img->bpp = 0;
	img->line_size = 0;
	img->endian = 0;
}

void	init_assets(t_assets *assets)
{
	init_img(&(assets->no));
	init_img(&(assets->so));
	init_img(&(assets->we));
	init_img(&(assets->ea));
	assets->f[0] = -1;
	assets->c[0] = -1;
	assets->f[1] = -1;
	assets->c[1] = -1;
	assets->f[2] = -1;
	assets->c[2] = -1;
}

void	init_camera(t_camera *camera)
{
	camera->ray_list = NULL;
	camera->dir_angle = 0;
	camera->coord.y = 0;
	camera->coord.x = 0;
}

void init_frame(t_frame *frame, t_data *data)
{
	frame->game = ft_calloc(sizeof(t_img), 1);
	ft_new_image(frame->game, WINDOW_WIDTH, WINDOW_HEIGHT, data);
	frame->overlay = NULL;
	frame->minimap = NULL;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	init_frame(&(data->frame), data);
	init_assets(&(data->assets));
	init_camera(&(data->camera));
	init_rays(&(data->camera), data);
	data->map = 0;
	data->map_height = 0;
	data->map_width = 0;
}

t_ray	*init_rays(t_camera *camera, t_data *data) //todo
{
	t_ray	*ray_list;
	double	angle;
	int		i;

	ray_list = malloc(sizeof(t_ray) * (WINDOW_WIDTH));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		(void)data;
		angle = -(FOV / 2) + ((double)FOV / (double)WINDOW_WIDTH * (double)i);
		ray_list[i].angle = angle;
		ray_list[i].impact = 0;
		/*ray_list[i].impact.coord.x = 0;
		ray_list[i].impact.coord.y = 0;
		ray_list[i].impact.wall = &data->assets.no;
		ray_list[i].impact.wall_x = 0;*/
	}
	camera->ray_list = ray_list;
	return (ray_list);
}
