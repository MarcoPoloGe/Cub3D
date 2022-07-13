/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:06 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:08 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

size_t	ft_strcat(char *dst, char *str)
{
	size_t i;
	size_t dstlen;
	size_t strlen;

	dstlen = ft_strlen(dst);
	strlen = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		dst[dstlen + i] = str[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + strlen);
}