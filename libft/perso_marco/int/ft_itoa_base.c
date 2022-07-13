/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:26:33 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:26:35 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../perso_marco.h"

static char	*ft_nb_to_string(int nb, char *result, int nb_len, int base)
{
	char	*dico;
	int		i;

	dico = "0123456789ABCDEF";
	i = nb_len - 1;
	while (nb)
	{
		result[i--] = dico[nb % base];
		nb /= base;
	}
	return (result);
}

char	*ft_itoa_base(int nb, int base)
{
	char	*result;
	int		nb_len;

	if (nb == 0)
		return (ft_strdup("0"));
	if (base == 10 && nb == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_len = ft_nbrlen(nb, base);
	result = ft_calloc(nb_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	else if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result = ft_nb_to_string(nb, result, nb_len, base);
	return (result);
}
