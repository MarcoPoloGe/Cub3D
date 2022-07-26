/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:37:12 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/26 11:12:37 by ktrosset         ###   ########.fr       */
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

typedef struct s_pos {
	float	x;
	float	y;
}				t_pos;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;

	int		*addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_pos	pos;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	char	**map;
	int		c[3];
	int		f[3];
}				t_data;

//leave.c
int		leave(t_data *data, char *errormsg);
void	free_all(t_data *data);

//main.c
void	*check_keycode(int keycode, t_data *data, void *img);
int		main(int ac, char **av);
void	*ft_new_image(char *path, t_img *img, t_data *data);

//parser.c
void	ft_parser(char *file_name, t_data *data);
int		ft_get_map(char **input_tab, t_data *data);
int		ft_check_map(char **map, t_data *data);

//display.c
void	ft_display_map(char **map);
void	ft_display_img(t_img *img);
void	ft_display_data(t_data *data);

//raycasting.c
int	load_texture(t_data *data);

#endif
