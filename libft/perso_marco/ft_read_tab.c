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

//permet de lire le fichier en entier et de le retourner sous forme de tableau.
//(si la valeur de "ext" est NULL alors toutes les extensions fonctionnent).
char	**ft_read_tab(char *file_name, char *ext, char sep)
{
	char	*file;
	char	**tab;

	file = ft_read_file(file_name, ext);
	if (file == NULL)
		return (NULL);
	tab = ft_split(file, sep);
	free(file);
	return (tab);
}
