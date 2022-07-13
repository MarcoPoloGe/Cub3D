/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:14:12 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/17 15:35:36 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

int	ft_tabcpy(char **dst, char **tab)
{
	int	i;
	int	tablen;

	tablen = ft_tablen(tab);
	i = 0;
	while (i < tablen)
	{
		dst[i] = ft_strdup(tab[i]);
		i++;
	}
	dst[i] = NULL;
	return (tablen);
}
