/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:19:10 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/16 17:19:12 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft42.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && (*lst))
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		(*lst) = temp;
	}
}
