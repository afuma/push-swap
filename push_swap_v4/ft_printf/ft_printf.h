/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:57:02 by edesaint          #+#    #+#             */
/*   Updated: 2023/01/23 18:57:27 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_convert_hex(size_t nb, int upper);
int		ft_putnbr_len(int n, int int_convert);
void	ft_putnbr_fd(int n, int fd, int int_convert);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

int		ft_convert_chosen(va_list arg, char c);
int		ft_convert_x(va_list arg, int upper);
int		ft_convert_c(va_list arg);
int		ft_convert_s(va_list arg);
int		ft_convert_p(va_list arg);
int		ft_convert_di(va_list arg);
int		ft_convert_u(va_list arg);

#endif