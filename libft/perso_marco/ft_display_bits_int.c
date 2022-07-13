/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bits_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marco Belarbi <mbelarbi@42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:52:44 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/03/01 10:51:19 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

void	ft_display_bits_int(int nb)
{
	int	bit_index;

	bit_index = 31;
	while (bit_index >= 0)
	{
		if (nb >> bit_index & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		if ((bit_index) % 8 == 0)
			ft_putchar(' ');
		bit_index--;
	}
	ft_putchar('\n');
}
