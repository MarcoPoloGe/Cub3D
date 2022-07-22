/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:38:45 by Marco Belar       #+#    #+#             */
/*   Updated: 2022/07/19 14:09:10 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_map(char **input_tab, t_data *data)
{
	/*printf("--- MAP INPUT START ---\n");
	ft_display_tab(input_tab);
	printf("--- MAP INPUT END ---\n");*/
	if (ft_check_map(input_tab, data))
	{
		leave(data, "Error : map invalid\n");
		ft_free_tab(input_tab);
		return (0);
	}
	else
	{
		data->map = ft_tabdup(input_tab);
		return (ft_tablen(data->map));
	}
}
