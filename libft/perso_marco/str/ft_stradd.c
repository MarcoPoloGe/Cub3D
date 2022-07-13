/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:47:23 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/27 14:47:24 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

void	ft_stradd(char **s1, char *s2)
{
	char	*old_s1;
	int		len;

	if (!s2)
		return ;
	len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	old_s1 = (*s1);
	(*s1) = ft_calloc(len, sizeof(char));
	if ((*s1) == NULL)
		return ;
	ft_strlcpy((*s1), old_s1, len);
	ft_strlcat((*s1), s2, len);
	if (old_s1)
		free(old_s1);
}
