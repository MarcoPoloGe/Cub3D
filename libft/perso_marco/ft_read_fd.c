/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:21:02 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/20 13:21:05 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

//permet de lire le contenu du fd en entier.
char	*ft_read_fd(int fd)
{
	char	*file;
	char	*line;

	if (fd == -1)
	{
		ft_putstr_fd("Error: can't read fd.\n", 2);
		return (NULL);
	}
	file = NULL;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		ft_stradd(&file, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (file);
}
