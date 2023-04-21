/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:02:26 by edesaint          #+#    #+#             */
/*   Updated: 2023/01/23 18:53:10 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_c(va_list arg)
{
	unsigned char	c;

	c = (unsigned char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_convert_s(va_list arg)
{
	char	*s;

	s = (char *) va_arg(arg, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_convert_p(va_list arg)
{
	unsigned long long int	p;
	int						len;

	len = 0;
	p = (unsigned long long int) va_arg(arg, unsigned long long int);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		len += 2;
		len += ft_convert_hex(p, 0);
	}
	return (len);
}

int	ft_convert_di(va_list arg)
{
	int	nb;

	nb = (int) va_arg(arg, int);
	ft_putnbr_fd(nb, 1, 0);
	return (ft_putnbr_len(nb, 0));
}

int	ft_convert_u(va_list arg)
{
	unsigned int	nb;

	nb = (unsigned int) va_arg(arg, unsigned int);
	ft_putnbr_fd(nb, 1, 1);
	return (ft_putnbr_len(nb, 1));
}
