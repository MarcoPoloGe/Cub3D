/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:20:43 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/02/20 12:35:46 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

void	ft_display_tab(char **tab)
{
	int	i;

	if (tab == NULL || (*tab) == NULL)
		return ;
	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
}
