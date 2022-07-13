/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marco Belarbi <mbelarbi@42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:52:37 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/03/01 10:51:58 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

int	ft_int_too_big(char *str)
{
	long	nb;

	if (ft_strlen(str) > 11)
		return (1);
	nb = ft_atoi_big(str);
	if (nb > INT32_MAX || nb < INT32_MIN)
		return (1);
	return (0);
}
