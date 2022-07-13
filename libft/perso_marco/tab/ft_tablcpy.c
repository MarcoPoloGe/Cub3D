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

int	ft_tablcpy(char **dst, char **tab, int len)
{
	int	i;
	int	tablen;

	tablen = ft_tablen(tab);
	if (len <= 0)
		return (tablen);
	i = 0;
	while (i < len - 1 && i < tablen)
	{
		dst[i] = ft_strdup(tab[i]);
		i++;
	}
	dst[i] = NULL;
	return (tablen);
}
