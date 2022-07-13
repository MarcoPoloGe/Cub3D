/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:22:29 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/07 15:22:31 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

//supprime l'element du tableau a l'index donné (ne realloc pas).
void	ft_tabdel(char **tab, int index)
{
	int	i;
	int	shift_flag;

	shift_flag = 0;
	i = 0;
	if (index >= ft_tablen(tab))
		return ;
	while (tab[i])
	{
		if (i == index)
		{
			if (tab[i])
				free(tab[i]);
			shift_flag = 1;
		}
		if (shift_flag == 1)
		{
			tab[i] = tab[i + 1];
		}
		i++;
	}
	tab[i] = NULL;
}
