/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:13:17 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/26 12:47:19 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	charc;
	unsigned char	*ps;
	size_t			i;

	charc = (unsigned char)c;
	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == charc)
			return (ps + i);
		i++;
	}
	return (NULL);
}
