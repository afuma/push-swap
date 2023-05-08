/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:36:47 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 21:52:40 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	ft_error_split(char **args, int i)
{
	ft_free_split(args, i);
	exit(EXIT_SUCCESS);
}

void	ft_error_tab(int *tab)
{
	free(tab);
	ft_error();
}

void	ft_error_tab_and_split(int *tab, char **args, int i)
{
	ft_free_split(args, i);
	free(tab);
	ft_error();
}
