/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:16:59 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/02/20 11:17:52 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft42/libft42.h"
# include "../perso_marco/perso_marco.h"

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

char	*ft_get_next_line(int fd);

#endif
