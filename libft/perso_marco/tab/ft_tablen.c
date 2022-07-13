/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:18:25 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/02/13 16:18:31 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

int	ft_tablen(char **tab)
{
	int	count;

	if (tab == NULL || *tab == NULL)
		return (0);
	count = 0;
	while (tab[count] != NULL)
		count++;
	return (count);
}
