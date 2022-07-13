/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:26:07 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/03/03 15:26:28 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

int	ft_check_ext(char *file, char *ext)
{
	int	start;

	if (ext == NULL)
		return (1);
	start = ft_strlen(file) - ft_strlen(ext);
	if (ft_str_same(file + start, ext))
		return (1);
	else
		return (0);
}
