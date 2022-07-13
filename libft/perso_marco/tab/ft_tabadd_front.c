/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:02 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/17 15:35:10 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

void	ft_tabadd_front(char ***tab, char *str)
{
	int		len;
	char	**old_tab;

	if (str == NULL)
		return ;
	len = ft_tablen((*tab));
	old_tab = *tab;
	*tab = ft_calloc(len + 2, sizeof(char *));
	if (*tab == NULL)
		return ;
	(*tab)[0] = ft_strdup(str);
	ft_tabcat(*tab, old_tab);
	if (old_tab)
		ft_free_tab(old_tab);
}
