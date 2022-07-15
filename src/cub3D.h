/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:37:12 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/15 15:14:19 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_pos {
	float	x;
	float	y;
}				t_pos;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;

	int		c[3];
	int		f[3];

	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_pos	pos;
	t_img	img;
	char	**map;
}				t_data;

//leave.c
int		leave(t_data *data, char *errormsg);
void	free_all(t_data *data);

//main.c
void	*check_keycode(int keycode, t_data *data, void *img);
int		main(int ac, char **av);

//parser.c
int		ft_get_map(char **input_tab, t_data *data);
void	ft_parser(char *file_name, t_data *data);
int		ft_check_map(char **map);
void	ft_display_img(t_img *img);
void	ft_display_data(t_data *data);

#endif
