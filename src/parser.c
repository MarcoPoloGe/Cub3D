/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:09:58 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/15 10:57:56 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	show_struc_map(t_data *data)
{
	printf("%s\n%s\n%s\n%s\nf: %d %d %d\nc: %d %d %d\n", data->img.no, data->img.so,
		data->img.we, data->img.ea, data->img.f[0], data->img.f[1],
		data->img.f[2], data->img.c[0], data->img.c[1], data->img.c[2]);
}

int	ft_skip_empty(char **input_tab)
{
	int	i;

	i = 0;
	while (ft_strlen(input_tab[i]) <= 0)
		i++;
	return (i);
}

int	ft_get_colors(char **input_tab, t_data *data, int i, int j)
{
	char	**fc;

	while (input_tab[i][++j])
		if (ft_isdigit(input_tab[i][j]) != 0 && input_tab[i][j] != ',')
			leave(data, "Error: map\n");
	fc = ft_split(input_tab[i], ',');
	if (ft_strncmp(input_tab[i], "F", 2))
	{
		data->img.f[0] = ft_atoi(fc[0]);
		data->img.f[1] = ft_atoi(fc[1]);
		data->img.f[2] = ft_atoi(fc[2]);
	}
	else if (ft_strncmp(input_tab[i], "C", 2))
	{
		data->img.c[0] = ft_atoi(fc[0]);
		data->img.c[1] = ft_atoi(fc[1]);
		data->img.c[2] = ft_atoi(fc[2]);
	}
	else
		return (0);
	return (1);
}

int	ft_get_textures(char **input_tab, t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (input_tab[++i])
	{
		j = 1;
		if (ft_strncmp(input_tab[i], "NO ", 3))
			data->img.no = &input_tab[i][3];
		else if (ft_strncmp(input_tab[i], "SO ", 3))
			data->img.no = &input_tab[i][3];
		else if (ft_strncmp(input_tab[i], "WE ", 3))
			data->img.no = &input_tab[i][3];
		else if (ft_strncmp(input_tab[i], "EA ", 3))
			data->img.no = &input_tab[i][3];
		else
			return (ft_get_colors(input_tab, data, i, j));
	}
	return (0);
}

t_data	*ft_parser(char *file)
{
	t_data	*data;
	int		i;
	char	**tab;

	data = ft_calloc(sizeof(t_data), 1);
	tab = ft_read_tab(file, ".cub", '\n');
	if (tab == 0)
		return (0);
	i = 0;
	i += ft_skip_empty(tab + i);
	i += ft_get_textures(tab + i, data);
	i += ft_skip_empty(tab + i);
	show_struc_map(data);
	/*i += ft_get_colors(tab + i, data);
	i += ft_skip_empty(tab + i);
	i += ft_get_map(tab + i, data);*/
	return (data);
}
