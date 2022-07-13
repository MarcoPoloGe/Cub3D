/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:11:46 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/23 13:18:11 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_len(void *p)
{
	int			result_len;
	char		*str_adress;
	char		*result;
	uintptr_t	adress;

	adress = (uintptr_t)p;
	str_adress = ft_itoa_base_16(adress);
	str_adress = ft_str_to_lowercase(str_adress);
	result = ft_strjoin("0x", str_adress);
	free(str_adress);
	result_len = ft_putstr(result);
	free(result);
	return (result_len);
}
