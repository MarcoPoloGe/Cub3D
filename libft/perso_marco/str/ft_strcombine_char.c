/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:11 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:12 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

char	*ft_strcombine_char(char *s1, char c)
{
	char *old_s1;
	int len;

	len = ft_strlen(s1);
	old_s1 = s1;
	s1 = ft_calloc(len + 2, sizeof(char));
	if (s1 == NULL)
		return (NULL);
	ft_strlcpy(s1, old_s1, len + 1);
	s1[len] = c;
	if (old_s1)
		free(old_s1);
	return (s1);
}