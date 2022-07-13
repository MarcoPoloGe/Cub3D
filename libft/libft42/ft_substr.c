/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:34:52 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 18:16:34 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*r;

	if (!str)
		return (NULL);
	if ((unsigned int)ft_strlen(str) <= start)
		sublen = 0;
	else
		sublen = (size_t)ft_strlen((char *)str + start);
	if (len < sublen)
		sublen = len;
	r = ft_calloc(sublen + 1, sizeof(char));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, (char *)str + start, sublen + 1);
	return (r);
}
