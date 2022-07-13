/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:51:21 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/02/20 12:23:16 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next_read(int fd)
{
	int		len_read;
	char	*str;

	str = ft_calloc(100 + 1, sizeof(char));
	if (!str)
		return (NULL);
	len_read = read(fd, str, 100);
	if (len_read <= 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static char	*ft_save_rest(char *next_read)
{
	char	*rest;

	rest = ft_strchr(next_read, '\n');
	if (rest != NULL)
	{
		rest++;
		return (ft_strndup(rest, ft_strlen(rest)));
	}
	return (NULL);
}

static char	*ft_join_and_free(char *doc, char *next_read)
{
	char	*temp;

	temp = NULL;
	if (doc == NULL)
		return (ft_strndup(next_read, ft_strlen(next_read)));
	else
	{
		temp = ft_strjoin(doc, next_read);
		free(doc);
		return (temp);
	}
}

char	*ft_get_next_line(int fd)
{
	static char	*doc[1024];
	char		*line;
	char		*next_read;

	if (doc[fd] == NULL)
		doc[fd] = ft_join_and_free(doc[fd], next_read = ft_next_read(fd));
	else
		next_read = ft_strndup(doc[fd], ft_strlen(doc[fd]));
	while (next_read != NULL && !ft_strchr(next_read, '\n'))
	{
		free(next_read);
		next_read = ft_next_read(fd);
		doc[fd] = ft_join_and_free(doc[fd], next_read);
	}
	line = ft_strndup(doc[fd], (ft_strlen(doc[fd])
				- ft_strlen(ft_strchr(doc[fd], '\n'))) + 1);
	free(doc[fd]);
	doc[fd] = ft_save_rest(next_read);
	free(next_read);
	if (ft_strlen(line) <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
