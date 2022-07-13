/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:11:02 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/29 17:52:58 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cb;
	size_t	i;

	cb = (char *)b;
	i = 0;
	while (i < len)
	{
		cb[i] = (char)c;
		i++;
	}
	return (b);
}
