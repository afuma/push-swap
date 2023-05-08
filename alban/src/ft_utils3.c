/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:15:52 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 19:37:03 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_duplicate(int *tab, int last_index)
{
	int	i;
	int	last_value;

	i = last_index;
	last_value = tab[i];
	i--;
	while (i >= 0)
	{
		if (tab[i] == last_value)
			return (1);
		i--;
	}
	return (0);
}

int	is_valid_number(char *argv)
{
	long int	nb;
	int			index;
	int			i;

	index = 0;
	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	index = i;
	while (argv[i])
	{
		if (i > 10 + index || !(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	nb = ft_atol(argv);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}
