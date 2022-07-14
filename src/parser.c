/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:09:58 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/07/14 14:10:00 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_skip_empty(char **input_tab)
{
	int i;

	i = 0;
	while (ft_strlen(input_tab[i]) <= 0)
	    i++;
	return (i);
}

t_data *ft_parser(char *file)
{
	t_data *data;
	int i;
	char **tab;

	data = ft_calloc(sizeof(t_data), 1);
	tab = ft_read_tab(file, ".cub", '\n');
	if (tab == NULL)
		return NULL;
	i = 0;
	i += ft_skip_empty(tab + i);
	i += ft_get_textures(tab + i, data);
	i += ft_skip_empty(tab + i);
	i += ft_get_colors(tab + i, data);
	i += ft_skip_empty(tab + i);
	i += ft_get_map(tab + i, data);
	return (data);
}