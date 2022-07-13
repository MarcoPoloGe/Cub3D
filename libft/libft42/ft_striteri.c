/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:10:24 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/28 18:55:52 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		i = 0;
		while (i < len)
		{
			(*f)(i, str + i);
			i++;
		}
	}
}
