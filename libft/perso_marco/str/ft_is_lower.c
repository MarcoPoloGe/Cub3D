/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:26:01 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:26:06 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

int	ft_is_lower(int c)
{
	if (c <= 'z' && c >= 'a' )
		return (1);
	else
		return (0);
}
