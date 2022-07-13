/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:35:20 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 17:48:59 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*copy;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	copy = ft_calloc(len + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = (*f)(i, str[i]);
		i++;
	}
	return (copy);
}
