/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:32:31 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/28 16:32:33 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft42/libft42.h"
# include "../perso_marco/perso_marco.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_print_pointer_len(void *p);
char	*ft_itoa_base_16(unsigned long nb);
int		ft_puthexa_len(unsigned int nb, int lowercase);
int		ft_print_types(char c, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);
#endif
