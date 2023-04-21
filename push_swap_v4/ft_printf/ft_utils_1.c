/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:15:00 by edesaint          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:30 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n, int int_convert)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (!int_convert && n < 0)
	{
		if (n == INT_MIN)
			return (11);
		len++;
		n *= -1;
	}
	nbr = n;
	if (int_convert && n < 0)
		nbr = (UINT_MAX + 1) + n;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd, int int_convert)
{
	unsigned int	nbr;

	nbr = n;
	if (int_convert)
	{
		if (n < 0)
			nbr = (UINT_MAX + 1) + n;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = -n;
		}
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, int_convert);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
