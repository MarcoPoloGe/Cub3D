/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:09:58 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/15 15:12:37 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	show_struc_map(t_data *data)
{
	printf("%s\n%s\n%s\n%s\nf: %d %d %d\nc: %d %d %d\n", data->img.no,
		data->img.so, data->img.we, data->img.ea, data->img.f[0],
		data->img.f[1], data->img.f[2], data->img.c[0],
		data->img.c[1], data->img.c[2]);
}

int	ft_skip_empty(char **input_tab)
{
	int	i;

	i = 0;
	while (ft_strlen(input_tab[i]) <= 0)
		i++;
	return (i);
}

void	ft_get_colors(char **input_tab, t_data *data, int i)
{
	int		j;
	char	**fc;

	j = 1;
	while (input_tab[i][++j])
		if (ft_isdigit(input_tab[i][j]) == 0 && input_tab[i][j] != ',')
			leave(data, "Error: map\n");
	fc = ft_split(&input_tab[i][2], ',');
	if (ft_tablen(fc) != 3)
		leave(data, "Error: map\n");
	if (ft_strncmp(input_tab[i], "F ", 2))
	{
		if (data->img.f[0] != 0)
			leave(data, "Error: map\n");
		data->img.f[0] = ft_atoi(fc[0]);
		data->img.f[1] = ft_atoi(fc[1]);
		data->img.f[2] = ft_atoi(fc[2]);
	}
	else if (ft_strncmp(input_tab[i], "C ", 2))
	{
		if (data->img.c[0] != 0)
			leave(data, "Error: map\n");
		data->img.c[0] = ft_atoi(fc[0]);
		data->img.c[1] = ft_atoi(fc[1]);
		data->img.c[2] = ft_atoi(fc[2]);
	}
	else
		leave(data, "Error: map\n");
	ft_free_tab(fc);
}

int	check_data_good(t_data *data)
{
	if (data->img.f[0] && (data->img.f[0] < 0 || data->img.f[0] > 255
			|| data->img.f[1] < 0 || data->img.f[1] > 255 || data->img.f[2] < 0
			|| data->img.f[2] > 255))
		return (2);
	if (data->img.no != 0 && data->img.so != 0 && data->img.we != 0
		&& data->img.ea != 0 && data->img.f[0] != 0 && data->img.c[0] != 0)
		return (1);
	else
		return (0);
}

int	ft_get_textures(char **input_tab, t_data *data)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (input_tab[++i])
	{
		if (ft_strncmp(input_tab[i], "NO ", 3) == 0)
		{
			if (data->img.no)
				leave(data, "Error: map\n");
			data->img.no = ft_new_image(&input_tab[i][3], data);
		}
		else if (ft_strncmp(input_tab[i], "SO ", 3) == 0)
		{
			if (data->img.so)
				leave(data, "Error: map\n");
			data->img.so = ft_new_image(&input_tab[i][3], data);
		}
		else if (ft_strncmp(input_tab[i], "WE ", 3) == 0)
		{
			if (data->img.we)
				leave(data, "Error: map\n");
			data->img.we = ft_new_image(&input_tab[i][3], data);
		}
		else if (ft_strncmp(input_tab[i], "EA ", 3) == 0)
		{
			if (data->img.ea)
				leave(data, "Error: map\n");
			data->img.ea = ft_new_image(&input_tab[i][3], data);
		}
		else
			ft_get_colors(input_tab, data, i);
		check = check_data_good(data);
		if (check == 1)
			return (0);
		else if (check == 2)
			leave(data, "Error: map\n");
	}
	return (0);
}

t_data	*ft_parser(char *file, t_data *data)
{
	int		i;
	char	**tab;

	tab = ft_read_tab(file, ".cub", '\n');
	if (tab == 0)
		return (0);
	i = 0;
	i += ft_skip_empty(tab + i);
	i += ft_get_textures(tab + i, data);
	i += ft_skip_empty(tab + i);
	show_struc_map(data);
	ft_free_tab(tab);
	return (data);
}
