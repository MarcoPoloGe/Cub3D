/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:11:52 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/23 13:11:35 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_nbrlen_unsigned(unsigned long nbr)
{
	int	i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static char	*ft_nb_to_string(unsigned long nb, char *result, int nb_len)
{
	char	*dico;
	int		i;

	dico = "0123456789ABCDEF";
	i = nb_len - 1;
	while (nb)
	{
		result[i--] = dico[nb % 16];
		nb /= 16;
	}
	return (result);
}

char	*ft_itoa_base_16(unsigned long nb)
{
	char	*result;
	int		nb_len;

	if (nb == 0)
		return (ft_strdup("0"));
	nb_len = ft_nbrlen_unsigned(nb);
	result = ft_calloc(nb_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_nb_to_string(nb, result, nb_len);
	return (result);
}
