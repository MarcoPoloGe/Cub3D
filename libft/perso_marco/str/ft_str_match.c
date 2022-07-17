/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:18:17 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/04/18 14:30:42 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

//Does the needle match the start of hay returns 1 if it does otherwise 0.
int	ft_str_match(char *hay, char *needle)
{
	int	i;

	if (hay == NULL || needle == NULL)
	{
		if (hay == needle)
			return (1);
		else
			return (0);
	}
	i = 0;
	while (hay[i] == needle[i] && hay[i] && needle[i])
	{
		i++;
	}
	if (i == ft_strlen(needle))
		return (1);
	else
		return (0);
}
