/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:15:09 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/29 18:01:40 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}
