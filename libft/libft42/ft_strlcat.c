/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:21:45 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/02/20 12:22:34 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft42.h"

size_t	ft_strlcat(char *dst, const char *str, size_t len)
{
	size_t	i;
	size_t	dstlen;
	size_t	strlen;

	dstlen = ft_strlen(dst);
	strlen = ft_strlen(str);
	if (len <= dstlen)
		return (len + strlen);
	i = 0;
	while ((dstlen + i + 1) < len && str[i])
	{
		dst[dstlen + i] = str[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + strlen);
}
