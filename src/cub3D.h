/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:37:12 by ktrosset          #+#    #+#             */
/*   Updated: 2022/09/01 14:11:14 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define DIR_VECTOR_LEN 30
# define FOV 90
# define MINIMAP_RENDER_SIZE 30
# define MINIMAP_OVERLAY "assets/map_200.xpm"

//Define for FDF_Render

# define COLOR_WALL 0x0000FF00
# define COLOR_GROUND 0x00808080
# define COLOR_SPACE 0x000000FF
# define COLOR_FOV 0x00FF00FF
# define COLOR_PLAYER_DIR 0x00FF0000
# define COLOR_RAY 0x00FFFF00
# define COLOR_COLLISION 0x00FF00FF

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct s_impact
{
	t_coord	coord;
	t_img	*wall;
	int		wall_x;
	double	distance;
}	t_impact;

typedef struct s_ray
{
	double		angle;
	t_impact	*impact;
}	t_ray;

typedef struct s_camera
{
	t_ray	*ray_list;
	t_coord	coord;
	double	dir_angle;
}	t_camera;

typedef struct s_frame
{
	t_img	*game;
	t_img	*overlay;
	t_img	*minimap;
}	t_frame;

typedef struct s_assets
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	int		c[3];
	int		f[3];
}	t_assets;

typedef struct s_data
{
	t_frame		frame;
	void		*mlx;
	void		*win;
	t_assets	assets;
	t_camera	camera;
	char		**map;
	int			map_width;
	int			map_height;
}				t_data;

//leave.c
int			leave(t_data *data, char *errormsg);
void		free_all(t_data *data);
void		ft_free_img(t_img *img, t_data *data);

//main.c
void		*check_keycode(int keycode, t_data *data);
int			main(int ac, char **av);

//parser.c
void		ft_parser(char *file_name, t_data *data);
int			ft_get_map(char **input_tab, t_data *data);
int			ft_check_map(char **map);

//put_struct.c
void		ft_put_map(t_data *data);
void		ft_put_img(t_img *img);
void		ft_put_data(t_data *data);
void		ft_put_camera(t_camera camera);
void		ft_put_impact(t_impact *impact);

//img.c
int			encode_rgb(int red, int green, int blue);
void		ft_new_image(t_img *img, int width, int height, t_data *data);
void		ft_file_to_image(char *path, t_img *img, t_data *data);

//raycasting.c
void		display_line(t_data *data, t_img *wall, int line_to_render,
				int len);
void		ft_calculate_impact_point(t_coord coord, t_ray *ray, t_data *data);

//draw_line.c
void		ft_render_line_coord(t_coord start_coord, t_coord end_coord,
				int color, t_img *frame);
void		ft_render_line_pos(t_pos start, t_pos end, int color, t_img *frame);

//draw_cube.c
void		ft_render_cube_empty(t_pos pos, int size, int color, t_img *frame);
void		ft_render_cube_filled(t_pos pos, int size, int color, t_img *frame);
void		ft_render_cube_wall(t_pos pos, int size, int color, t_img *frame);

//draw_rays
void		ft_render_one_px(t_pos pos, int color, t_img *frame);
void		ft_render_rays(t_data *data);

//render_fdf.c
void		ft_fdf_render(t_data *data);
void		check_side(t_camera *camera);
void		ft_render_grid(t_pos pos, char **map, int size, t_img *frame);
void		ft_render_player_fov(t_pos pos, t_coord coord, t_data *data);

//display_backgroud.c
void		render_background(t_img *frame, t_assets assets);

//display_wall.c
void		render_line(t_img *line, t_img *wall, int line_to_render,
				int distance);

//convert.c
t_pos		ft_pos(int y, int x);
t_coord		ft_coord(double y, double x);
t_pos		ft_coord_to_pos(t_coord input);
double		ft_degrees_to_radian(double degrees);
double		ft_radian_to_degrees(double degrees);

//coord_tools.c
t_coord		ft_rotate_point(t_coord axis, t_coord point, double angle);
t_coord		ft_find_next_coord_x(t_coord a, double alpha, t_coord c);
t_coord		ft_find_next_coord_y(t_coord a, double alpha, t_coord c);

//init.c
void		init_data(t_data *data);
t_ray		*init_rays(t_camera *camera, t_data *data);

//init2.c
void		init_assets(t_assets *assets);
void		init_img(t_img *img);

//move.c
int			keycode_handling(int keycode, t_data *data);

//map.c
void		ft_get_player_infos(char **map, t_data *data);

//map_check.c
int			ft_player_count_bad(char **map);
int			ft_forbiden_char(char **map);
int			ft_no_wall_space_around(char **map, int y, int x);
int			ft_space_no_border(char **map);
int			ft_end_no_border(char **map);

//frame.c
void		ft_put_pixel_frame(t_img *frame, int y, int x, int color);
int			ft_display_game(t_data *data);
void		ft_push_frame(t_pos pos, t_img *frame, t_data *data, int reset);

//ray.c
void		ft_ray_calculate_collision(char **map, t_coord coord, t_ray *ray);

//ray_impact.c
t_impact	*ft_check_if_wall_hit_y(t_data *data, t_coord coord, double angle);
t_impact	*ft_check_if_wall_hit_x(t_data *data, t_coord coord, double angle);

//minimap.c
void		ft_minimap_render(t_img *minimap, t_data *data);

//render_wall.c
void		ft_render_walls(t_camera camera, t_data *data);
#endif
