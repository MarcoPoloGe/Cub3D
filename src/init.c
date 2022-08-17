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

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	ft_new_image(&(data->frame), WINDOW_WIDTH, WINDOW_HEIGHT, data);
	init_assets(&(data->assets));
	init_camera(&(data->camera));
	//init_rays(&(data->camera));
	data->map = 0;
}

/*t_ray	*init_rays(t_camera *camera) //todo
{
	t_ray	*ray_list;
	double	angle;
	int		i;

	angle = ft_degrees_to_radian(angle);
	ray_list = NULL;
	ray_list = malloc(sizeof(t_ray) * (WINDOW_WIDTH + 1));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		camera->dir.x -= 90;
		camera->dir.y -= 90;
	}
	return (ray_list);

}*/
