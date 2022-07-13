/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:06 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:08 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

int	ft_tabcat(char **dst, char **tab)
{
	int	i;
	int	dstlen;
	int	tablen;

	if (tab == NULL)
		return (0);
	dstlen = ft_tablen(dst);
	tablen = ft_tablen(tab);
	i = 0;
	while (tab[i])
	{
		dst[dstlen + i] = ft_strdup(tab[i]);
		i++;
	}
	dst[dstlen + i] = NULL;
	return (dstlen + tablen);
}
