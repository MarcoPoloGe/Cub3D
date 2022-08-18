#include "cub3D.h"

void	ft_rotate_camera(t_camera *camera, double angle)
{
	camera->dir_angle += angle;
	if(camera->dir_angle < 0)
		camera->dir_angle += 360;
	if(camera->dir_angle >= 360)
		camera->dir_angle -= 360;
	//printf("angle: %f\n", camera->dir_angle);
}

void	ft_move_player(double move, t_camera *camera) // has to calculate where to move both player coord and player dir
{
	t_coord	next_coord;
	t_coord		coord;

	coord = camera->coord;
	next_coord.y = coord.y + move;
	next_coord.x = coord.x;
	next_coord = ft_rotate_point(coord, next_coord, camera->dir_angle);
	camera->coord = next_coord;
}

int	keycode_handling(int keycode, t_data *data)
{
	t_camera	*camera;
	int			i;

	camera = &(data->camera);
	if (keycode == 53)
		leave(data, 0);
	if (keycode == 0)
		ft_rotate_camera(camera, -10);
	if (keycode == 2)
		ft_rotate_camera(camera, 10);
	if (keycode == 1)
		ft_move_player(0.5, camera);
	if (keycode == 13)
		ft_move_player(-0.5, camera);
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		ft_ray_calculate_collision(data->map, data->camera.coord,
			&data->camera.ray_list[i]);
		/*ft_put_pixel_frame(&(data->frame), data->camera.coord.y,
			data->camera.coord.x, 0x009933CC);*/
	}
	return (0);
}
