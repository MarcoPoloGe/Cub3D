/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:24:28 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/03/01 11:09:57 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

char	*ft_strchr(const char *str, int c)
{
	int	len;
	int	i;

	len = 0;
	if (str != NULL)
		len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
