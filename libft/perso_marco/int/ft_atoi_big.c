/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:15:39 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/30 17:55:54 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../perso_marco.h"

long	ft_atoi_big(char *str)
{
	long	result;
	long	i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{		
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
