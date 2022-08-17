/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:37:12 by ktrosset          #+#    #+#             */
/*   Updated: 2022/08/17 15:22:19 by ktrosset         ###   ########.fr       */
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
# define DIR_VECTOR_LEN 10
# define FOV 90

//Define for FDF_Render
# define FDF_RENDER_SIZE 50
# define COLOR_WALL 0x0000FF00
# define COLOR_GROUD 0x00808080
# define COLOR_SPACE 0x000000FF
# define COLOR_FOV 0x00FF00FF
# define COLOR_PLAYER_DIR 0x00FF0000
# define COLOR_RAY 0x00FFFF00
# define COLOR_COLLISION 0x00FF00FF

typedef struct s_coord
{
	double	x; //je les ais mis en double parce que toutes les fonctions de la lib Math.h utilise des doubles.
	double	y;
}				t_coord;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_img
{
	void	*ptr; // pointer to the image
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
	t_img	*wall; // give the texture of the wall that was hit
	int		wall_x; // x of the wall where the ray hit;
}	t_impact;

typedef struct s_ray
{
	double		angle;
	t_impact	impact;
}	t_ray;

typedef struct s_camera
{
	t_ray	*ray_list;
	t_coord	coord;
	double	dir_angle; // may replace dir coord but not sur yet;
}	t_camera;

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
	t_img		frame;
	void		*mlx;
	void		*win;
	t_assets	assets;
	t_camera	camera;
	char		**map;
}				t_data;

//leave.c
int		leave(t_data *data, char *errormsg);
void	free_all(t_data *data);

//main.c
void	*check_keycode(int keycode, t_data *data);
int		main(int ac, char **av);

//parser.c
void	ft_parser(char *file_name, t_data *data);
int		ft_get_map(char **input_tab, t_data *data);
int		ft_check_map(char **map);

//put_struct.c
void	ft_put_map(char **map);
void	ft_put_img(t_img *img);
void	ft_put_data(t_data *data);
void	ft_put_camera(t_camera camera);

//img.c
int		encode_rgb(int red, int green, int blue);
void	ft_new_image(t_img *img, int width, int height, t_data *data);
void	ft_file_to_image(char *path, t_img *img, t_data *data);

//raycasting.c
int		load_texture(t_data *data);

//render_fdf.c
int		ft_fdf_render(t_data *data);

//display_backgroud.c
void	render_background(t_img *frame, t_assets assets);

//coord_tools.c
double	ft_degrees_to_radian(double degrees);
double	ft_radian_to_degrees(double degrees);
t_coord	ft_rotate_point(t_coord axis, t_coord point, double angle);

//init.c
void	init_data(t_data *data);
t_ray	*init_rays(t_camera *camera);

//move.c
int		keycode_handling(int keycode, t_data *data);

//map_check.c
void	ft_get_player_infos(char **map, t_data *data);
//frame.c
void	ft_put_pixel_frame(t_img *frame, int y, int x, int color);
void ft_push_frame(t_data *data);

#endif
