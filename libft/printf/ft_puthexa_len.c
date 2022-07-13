/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:34:48 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/28 16:34:50 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_len(unsigned int nb, int lowercase)
{
	int		len;
	char	*str;

	str = ft_itoa_base_16(nb);
	if (lowercase)
		ft_str_to_lowercase(str);
	len = ft_putstr(str);
	free(str);
	return (len);
}
