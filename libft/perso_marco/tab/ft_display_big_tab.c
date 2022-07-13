/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:20:43 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/02/20 12:35:46 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

void	ft_display_line(char **tab)
{
	int	i;

	if (tab == NULL || (*tab) == NULL)
		return ;
	i = 0;
	while (tab[i])
		ft_printf("< %s > ", tab[i++]);
}

void	ft_display_big_tab(char ***tab)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	ft_putstr("--- Start ---\n");
	while (tab[y])
	{
		ft_display_line(tab[y]);
		ft_putchar('\n');
		y++;
	}
	ft_putstr("--- End ---");
}
