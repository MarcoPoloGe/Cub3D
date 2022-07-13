/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:03:45 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/13 13:12:19 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft42.h"

static int	ft_wordcount(char *str, char c)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (str[i] && str[i] != c)
		result ++;
	i++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			result++;
		i++;
	}
	return (result);
}

static int	ft_strlentochar(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*ft_strdupn(char *str, int n)
{
	char	*copy;

	copy = ft_calloc(n + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, (char *)str, n + 1);
	return (copy);
}

static char	**ft_fill_list(char **result, char *str, char c)
{
	int	result_index;
	int	len;
	int	i;

	result_index = 0;
	i = 0;
	if (!str)
		result[0] = NULL;
	else
	{
		while (str[i])
		{
			if (str[i] != c)
			{
				len = ft_strlentochar(str + i, c);
				result[result_index++] = ft_strdupn(str + i, len);
				i += len;
			}
			else
				i++;
		}
	}
	return (result);
}

char	**ft_split(const char *str, char c)
{
	int		wordcount;
	char	**result;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) == 0)
	{
		result = ft_calloc(1, sizeof(char *));
		result[0] = 0;
		return (result);
	}
	wordcount = ft_wordcount((char *)str, c);
	result = ft_calloc((wordcount + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = ft_fill_list(result, (char *)str, c);
	result[wordcount] = NULL;
	return (result);
}
