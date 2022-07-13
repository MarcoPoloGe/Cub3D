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

char	**ft_tabndup(char **tab, int len)
{
	char	**tabdup;

	tabdup = ft_calloc(len + 1, sizeof(char *));
	if (tabdup == NULL)
		return (NULL);
	ft_tablcpy(tabdup, tab, len + 1);
	return (tabdup);
}
