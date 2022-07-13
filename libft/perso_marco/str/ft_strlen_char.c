/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:18 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:20 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

//retourne la longueur jusqu'au char.
//si le char n'est pas présent ou que la string est null le retour est -1.
int	ft_strlen_char(char *str, char c)
{
	int	len;

	if (str == NULL)
		return (-1);
	len = 0;
	while (str[len])
	{
		if (str[len] == c)
		{
			return (len);
		}
		len++;
	}
	return (-1);
}
