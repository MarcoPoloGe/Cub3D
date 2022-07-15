/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:37:12 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/15 14:23:04 by ktrosset         ###   ########.fr       */
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

typedef struct s_map {
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_pos	pos;
	t_img	img;
	t_map	map;
}				t_data;

//leave.c
int		leave(t_data *data, char *errormsg);
void	free_all(t_data *data);

//main.c
void	*check_keycode(int keycode, t_data *data, void *img);
int		main(int ac, char **av);
t_map	*ft_get_map(char **input_tab, t_data *data);
void	*ft_new_image(char *path, t_data *data);

//parser.c
t_data	*ft_parser(char *file, t_data *data);

#endif
