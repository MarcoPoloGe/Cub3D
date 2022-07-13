/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:18:59 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/16 17:20:02 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft42.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
