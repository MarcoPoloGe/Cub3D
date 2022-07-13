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

void	ft_stradd_len(char **s1, char *s2, int s2_len)
{
	char	*old_s1;
	int		s1_len;

	if (!s2 || s2_len <= 0)
		return ;
	s1_len = ft_strlen(*s1);
	old_s1 = (*s1);
	(*s1) = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if ((*s1) == NULL)
		return ;
	ft_strcpy((*s1), old_s1);
	ft_strlcat((*s1), s2, s1_len + s2_len + 1);
	if (old_s1)
		free(old_s1);
}
