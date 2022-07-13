/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:45:07 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/11/23 12:47:05 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_null(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(str));
}

int	ft_print_types(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_null(va_arg(ap, void *)));
	else if (c == 'p')
		return (ft_print_pointer_len(va_arg(ap, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa_len(va_arg(ap, unsigned int), 1));
	else if (c == 'X')
		return (ft_puthexa_len(va_arg(ap, unsigned int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		nb;
	int		i;
	va_list	ap;

	va_start(ap, str);
	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			nb += ft_print_types(str[i], ap);
		}
		else
			nb += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (nb);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		nb;
	int		i;
	va_list	ap;
	int		fd_out;

	fd_out = dup(1);
	dup2(fd, 1);
	va_start(ap, str);
	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			nb += ft_print_types(str[i], ap);
		}
		else
			nb += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	dup2(fd_out, 1);
	return (nb);
}
