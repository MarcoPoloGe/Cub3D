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

char	**ft_tabdup(char **tab)
{
	int		tablen;
	char	**tabdup;

	tablen = ft_tablen(tab);
	tabdup = ft_calloc(tablen + 1, sizeof(char *));
	ft_tabcpy(tabdup, tab);
	return (tabdup);
}
