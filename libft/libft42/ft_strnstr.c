/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:08:27 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/29 18:02:40 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + len_needle <= len)
	{	
		if (ft_strncmp(haystack + i, needle, len_needle) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
