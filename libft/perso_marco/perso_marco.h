/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:20:21 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/18 14:33:59 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_MARCO_H
# define PERSO_MARCO_H
# include "../libft42/libft42.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>

int		ft_is_lower(int c);
int		ft_is_upper(int c);
char	*ft_itoa_base(int nb, int base);
int		ft_nbrlen(int nbr, int base);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_str_to_lowercase(char *str);
char	*ft_str_to_uppercase(char *str);
size_t	ft_strcat(char *dst, char *str);
char	*ft_strcombine(char *s1, char *s2);
size_t	ft_strcpy(char *dst, char *str);
int		ft_strlen_char(char *str, char c);
char	*ft_strndup(char *str, int n);
char	*ft_strrev(char *str);
int		ft_power(int nb, int power);
int		ft_putnbr(long n);
void	ft_putendl(char *str);
char	*ft_strcombine_char(char *s1, char c);
int		ft_str_is_num(char *str);
void	ft_stradd(char **s1, char *s2);
long	ft_atoi_big(char *str);
int		ft_tablen(char **tab);
int		ft_str_same(char *s1, char *s2);
void	ft_free_tab(char **tab);
void	ft_display_tab(char **tab);
int		ft_int_too_big(char *str);
void	ft_display_bits_int(int nb);
int		ft_check_ext(char *file, char *ext);
char	*ft_read_file(char *file_name, char *ext);
int		ft_str_match(char *hay, char *needle);
int		ft_tabcpy(char **dst, char **tab);
void	ft_tabadd(char ***tab, char *str);
int		ft_isspace(char c);
void	ft_stradd_len(char **s1, char *s2, int s2_len);
void	ft_tabadd_len(char ***tab, char *str, int str_len);
int		ft_skip_spaces(char *str, int i);
char	***ft_read_two_way_tab(char *config_file, char *ext, char sep);
char	**ft_tabdup(char **tab);
int		ft_tabcat(char **dst, char **tab);
void	ft_tabadd_front(char ***tab, char *str);
int		ft_tablcpy(char **dst, char **tab, int len);
char	**ft_tabndup(char **tab, int len);
void	ft_tab_combine(char ***s1, char **s2);
void	ft_tabdel(char **tab, int index);
char	**ft_tablast(char **tab);
void	ft_free_big_tab(char ***tab);
int		ft_big_tablen(char ***tab);
void	ft_display_big_tab(char ***tab);
char	*ft_read_fd(int fd);
int		ft_strlen_char_end(char *str, char c);
void	ft_free_tab_int(int **tab);
#endif
