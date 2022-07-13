/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:11:52 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/13 13:10:01 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

static int	ft_nbrlen(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_nb_to_string(int nb, char *result, int nb_len)
{
	int	i;

	i = nb_len - 1;
	while (nb)
	{
		result[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}

char	*ft_itoa(int nb)
{
	char	*result;
	int		nb_len;

	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_len = ft_nbrlen(nb);
	result = ft_calloc(nb_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	else if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result = ft_nb_to_string(nb, result, nb_len);
	return (result);
}
