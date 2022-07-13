/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:22 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:23 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

char	*ft_strndup(char *str, int n)
{
	char	*copy;

	copy = ft_calloc(n + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcat(copy, (char *)str, n + 1);
	return (copy);
}
