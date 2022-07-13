/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:26:50 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:26:54 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

int	ft_putstr(char *str)
{
	int len;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
