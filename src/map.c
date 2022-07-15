/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:38:45 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/03/08 14:49:33 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_map(char **input_tab, t_data *data)
{
	char	**map;

	map = ft_tabdup(input_tab);
	if (ft_check_map(map))
	{
		printf("Error : map invalid");
		ft_free_tab(map);
		return (0);
	}
	else
	{
		data->map = map;
		return (ft_tablen(map));
	}
}
