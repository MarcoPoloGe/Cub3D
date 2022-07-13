/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:49:07 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 15:23:30 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft42.h"

static char	*ft_strndup(char *str, int n)
{
	char	*copy;

	copy = ft_calloc(n + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, (char *)str, n + 1);
	return (copy);
}

static int	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		left;
	int		right;
	char	*r;

	if (!str || !set)
		return (NULL);
	left = 0;
	right = ft_strlen(str);
	while (ft_isset(str[left], (char *)set) && left < right)
		left++;
	while (ft_isset(str[right - 1], (char *)set) && left < right)
		right--;
	r = ft_strndup((char *)str + left, right - left);
	return (r);
}
