/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:36:47 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 17:56:22 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = ft_calloc(len, sizeof(char));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, (char *)s1, len);
	ft_strlcat(r, (char *)s2, len);
	return (r);
}
