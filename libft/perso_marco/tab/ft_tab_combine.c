/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:47:23 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/27 14:47:24 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

void	ft_tab_combine(char ***t1, char **t2)
{
	char	**old_t1;
	int		len;

	if (!t2)
		return ;
	len = ft_tablen(*t1) + ft_tablen(t2) + 1;
	old_t1 = (*t1);
	(*t1) = ft_calloc(len, sizeof(char *));
	if ((*t1) == NULL)
		return ;
	ft_tabcpy((*t1), old_t1);
	ft_tabcat((*t1), t2);
	if (old_t1 != NULL)
		ft_free_tab(old_t1);
	ft_free_tab(t2);
}
