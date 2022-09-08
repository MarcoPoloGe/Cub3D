/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:46:07 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/08 11:47:07 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_get_percent(double nb, double total)
{
	double	percent;

	percent = nb * 100 / total;
	return (percent);
}

double	ft_get_nb_from_percent(double percent, double total)
{
	double	nb;

	nb = percent * total / 100;
	return (nb);
}

int	ft_get_wall_color(int wall_y, int wall_x, t_img *wall)
{
	int	color;

	if (wall_x < wall->width && wall_y < wall->height && wall_x >= 0
		&& wall_y >= 0)
		color = wall->addr[(wall_y * wall->width) + wall_x];
	else
		color = COLOR_COLLISION;
	return (color);
}

void	ft_render_wall_line(t_pos pos, t_ray ray, t_impact *impact,
	t_data *data)
{
	int			i;
	double		step_y;
	double		wall_height;

	wall_height = WINDOW_HEIGHT / (impact->distance
			* cos(ft_degrees_to_radian(ray.angle)));
	step_y = impact->wall->height / wall_height;
	pos.y -= (wall_height / 2);
	i = 0;
	if (pos.y < 0)
	{
		i += -(pos.y);
		wall_height -= -(pos.y);
	}
	while (i < wall_height)
	{
		ft_put_pixel_frame(data->frame.game, pos.y + i, pos.x,
			ft_get_wall_color(i * step_y, ft_get_nb_from_percent(impact->wall_x,
					impact->wall->width), impact->wall));
		i++;
	}
}

void	ft_render_walls(t_camera camera, t_data *data)
{
	int		i;
	t_ray	*ray_list;

	ray_list = camera.ray_list;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		if (ray_list[i].impact != 0)
			ft_render_wall_line(ft_pos(WINDOW_HEIGHT / 2, i),
				ray_list[i], ray_list[i].impact, data);
		i++;
	}
}
