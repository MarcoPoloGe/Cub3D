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

void	ft_tabadd_len(char ***tab, char *str, int str_len)
{
	int		tab_len;
	char	**old_tab;

	if (str == NULL || str_len <= 0)
		return ;
	tab_len = ft_tablen((*tab));
	old_tab = *tab;
	*tab = ft_calloc(tab_len + 2, sizeof(char *));
	if (*tab == NULL)
		return ;
	ft_tabcpy(*tab, old_tab);
	(*tab)[tab_len] = ft_strndup(str, str_len);
	if (old_tab)
		ft_free_tab(old_tab);
}
