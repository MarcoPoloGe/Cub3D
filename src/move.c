#include "cub3D.h"

void	ft_rotate_camera(t_camera *camera, double angle)
{
	camera->dir = ft_rotate_point(camera->coord, camera->dir, angle);
	camera->dir_angle += angle;
	if(camera->dir_angle < 0)
		camera->dir_angle += 360;
	if(camera->dir_angle >= 360)
		camera->dir_angle -= 360;
}

void	ft_move_player(double move, t_data *data) // has to calculate where to move both player coord and player dir
{
	t_camera	*camera;
	t_coord		offset;

	camera = &(data->camera);

	offset.y = (camera->coord.y - camera->dir.y) / 100;
	offset.x = (camera->coord.x - camera->dir.x) / 100;

	offset.y *= move;
	offset.x *= move;

	camera->coord.y += offset.y;
	camera->coord.x += offset.x;

	camera->dir.y += offset.y;
	camera->dir.x += offset.x;
}

int	keycode_handling(int keycode, t_data *data)
{
	if (keycode == 53)
		leave(data, 0);
	if (keycode == 0)
		ft_rotate_camera(&(data->camera), -10);
	if (keycode == 2)
		ft_rotate_camera(&(data->camera), 10);
	if (keycode == 1)
		ft_move_player(2, data);
	if (keycode == 13)
		ft_move_player(-2, data); //todo
	return (0);
}
