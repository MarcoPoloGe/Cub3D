/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:09:58 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/22 11:14:56 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3D.h"

int	check_assets_good(t_assets *assets)
{
	if (assets->c[0] < 0 || assets->c[0] > 255)
		return (0);
	if (assets->c[1] < 0 || assets->c[1] > 255)
		return (0);
	if (assets->c[2] < 0 || assets->c[2] > 255)
		return (0);
	if (assets->f[0] < 0 || assets->f[0] > 255)
		return (0);
	if (assets->f[1] < 0 || assets->f[1] > 255)
		return (0);
	if (assets->f[2] < 0 || assets->f[2] > 255)
		return (0);
	if (assets->no.ptr == 0 || assets->so.ptr == 0
		|| assets->we.ptr == 0 || assets->ea.ptr == 0)
		return (0);
	return (1);
}

void	ft_add_color(int *rgb, char *input, t_data *data)
{
	int		i;
	char	**fc;

	i = -1;
	while (input[++i])
		if (!ft_isdigit(input[i]) && input[i] != ',')
			leave(data, "Error 1: asset or color\n");
	fc = ft_split(input, ',');
	if (ft_tablen(fc) != 3)
		leave(data, "Error 2: asset or color\n");
	//if (rgb[0] != -1 || rgb[1] != -1 || rgb[2] != -1)
		//leave(data, "Error 3: asset or color\n");
	if (ft_strlen(fc[0]) > 3 || ft_strlen(fc[1]) > 3 || ft_strlen(fc[2]) > 3)
		leave(data, "Error 5: asset or color\n");
	rgb[0] = ft_atoi(fc[0]);
	rgb[1] = ft_atoi(fc[1]);
	rgb[2] = ft_atoi(fc[2]);
	ft_free_tab(fc);
}

void	ft_add_texture(t_img *img, char *texture_path, t_data *data)
{
	ft_file_to_image(texture_path, img, data);
}

int	ft_get_textures(char **input_tab, t_data *data)
{
	int		i;

	i = -1;
	while (input_tab[++i])
	{
		if (ft_str_match(input_tab[i], "SO "))
			ft_add_texture(&(data->assets.so), input_tab[i] + 3, data);
		else if (ft_str_match(input_tab[i], "NO "))
			ft_add_texture(&(data->assets.no), input_tab[i] + 3, data);
		else if (ft_str_match(input_tab[i], "WE "))
			ft_add_texture(&(data->assets.we), input_tab[i] + 3, data);
		else if (ft_str_match(input_tab[i], "EA "))
			ft_add_texture(&(data->assets.ea), input_tab[i] + 3, data);
		else if (ft_str_match(input_tab[i], "F "))
			ft_add_color(data->assets.f, input_tab[i] + 2, data);
		else if (ft_str_match(input_tab[i], "C "))
			ft_add_color(data->assets.c, input_tab[i] + 2, data);
		else if (ft_strlen(input_tab[i]) > 0)
			break ;
	}
	if (!check_assets_good(&(data->assets)))
		leave(data, "Error 7: asset or color\n");
	return (i);
}

void	ft_parser(char *file_name, t_data *data)
{
	int		i;
	char	**tab;

	tab = ft_read_tab(file_name, ".cub", '\n');
	if (tab == 0)
		leave(NULL, "Error : invalid file\n");
	//printf("--- RAW INPUT START ---\n");
	//ft_display_tab(tab);
	//printf("--- RAW INPUT END ---\n");
	i = 0;
	i += ft_get_textures(tab + i, data);
	ft_get_map(tab + i, data);
	ft_get_player_infos(data->map, data);
	ft_free_tab(tab);
}
