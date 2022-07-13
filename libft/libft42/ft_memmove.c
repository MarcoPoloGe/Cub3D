/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:12:37 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/30 12:57:53 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	size_t			i;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (psrc == pdst)
		return (dst);
	if (psrc < pdst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			pdst[i] = psrc[i];
		}
		return (dst);
	}
	i = 0;
	while (i < n)
	{		
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
