/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:07:26 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/03/07 15:15:00 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

//permet de lire le fichier en entier et de verifier si le fichier est de la
//bonne extension.
//(si la valeur de ext est NULL alors toutes les extensions fonctionnent).
char	*ft_read_file(char *file_name, char *ext)
{
	char	*file;
	char	*line;
	int		fd;

	if (!ft_check_ext(file_name, ext))
	{
		ft_printf("Error: %s: %s\n", file_name, "incompatible extension");
		return (NULL);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s: %s\n", file_name, strerror(errno));
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
