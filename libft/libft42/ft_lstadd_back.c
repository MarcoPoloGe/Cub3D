/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:18:50 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/16 17:18:52 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft42.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ft_lstlast(*alst)->next = new;
}
