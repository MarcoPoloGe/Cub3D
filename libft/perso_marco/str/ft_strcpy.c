/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:14 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:16 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

size_t	ft_strcpy(char *dst, char *str)
{
	size_t	i;
	size_t	strlen;

	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (strlen);
}
