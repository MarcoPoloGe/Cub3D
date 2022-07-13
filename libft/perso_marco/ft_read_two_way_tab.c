/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marco Belarbi <mbelarbi@42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:52:42 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/02/19 11:52:42 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

char	***ft_make_two_way_tab(char **simple_tab, char sep)
{
	int		i;
	int		tab_len;
	char	***two_way_tab;

	tab_len = ft_tablen(simple_tab);
	two_way_tab = ft_calloc(tab_len + 1, sizeof(char **));
	if (two_way_tab == NULL)
		return (NULL);
	i = 0;
	while (i < tab_len)
	{
		two_way_tab[i] = ft_split(simple_tab[i], sep);
		i++;
	}
	ft_free_tab(simple_tab);
	return (two_way_tab);
}

//crée un tableau a deux dimention a partir d'un fichier.
//param : nom du fichier, extention du fichier, séparateur entre deux éléments.
char	***ft_read_two_way_tab(char *config_file, char *ext, char sep)
{
	char	*read;
	char	**simple_tab;

	read = ft_read_file(config_file, ext);
	if (read == NULL)
		return (NULL);
	simple_tab = ft_split(read, '\n');
	free(read);
	return (ft_make_two_way_tab(simple_tab, sep));
}
