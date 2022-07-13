/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:00:43 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/25 17:06:34 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

static int	ft_islower(int c)
{
	if (c <= 'z' && c >= 'a' )
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
