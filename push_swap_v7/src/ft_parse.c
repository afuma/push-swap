/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:19:06 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 20:36:33 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	ft_error_tab(int *tab)
{
	free(tab);
	ft_error();
}

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

void	ft_parse(int argc, char *argv[])
{
	int	i;
	int	*tab;

	tab = (int *) malloc(sizeof(int) * (argc - 1));
	if (!tab)
		ft_error();
	if (argc < 2)
		ft_error_tab(tab);
	i = 1;
	while (i <= argc - 1)
	{
		if (!is_valid_number(argv[i]))
			ft_error_tab(tab);
		else
		{
			tab[i - 1] = ft_atoi(argv[i]);
			if (ft_is_duplicate(tab, i - 1))
				ft_error_tab(tab);
		}
		i++;
	}
	free(tab);
}
