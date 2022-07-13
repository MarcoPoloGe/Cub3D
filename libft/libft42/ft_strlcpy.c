/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:13:11 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/29 17:52:28 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

size_t	ft_strlcpy(char *dst, const char *str, size_t len)
{
	size_t	i;
	size_t	strlen;

	strlen = ft_strlen(str);
	if (len <= 0)
		return (strlen);
	i = 0;
	while (i < len - 1 && i < strlen)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (strlen);
}
