/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrosset <ktrosset@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:17:24 by ktrosset          #+#    #+#             */
/*   Updated: 2022/07/20 11:18:38 by ktrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_keanu.h"

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
	free(s1);
	free(s2);
	return (r);
}
