/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:19:06 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 22:05:42 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parse(t_stack **stack_a, int argc, char *argv[])
{
	char	**args;
	size_t	nb_words;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		nb_words = ft_nb_words_split(argv[1], ' ');
		ft_parse_2(nb_words, args);
		ft_args_to_list_2(stack_a, args);
		ft_free_split(args, nb_words);
	}
	else
	{
		ft_parse_3(argc, argv);
		ft_args_to_list(stack_a, argc, argv);
	}
}

void	ft_parse_2(int nb_words, char **args)
{
	int	i;
	int	*tab;

	i = 1;
	tab = (int *) malloc(sizeof(int) * (nb_words));
	if (!tab)
		ft_error_split(args, nb_words);
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			ft_error_tab_and_split(tab, args, i);
		else
		{
			tab[i] = ft_atoi(args[i]);
			if (ft_is_duplicate(tab, i))
				ft_error_tab_and_split(tab, args, i);
		}
		i++;
	}
	free(tab);
}

void	ft_parse_3(int argc, char *argv[])
{
	int	i;
	int	*tab;

	tab = (int *) malloc(sizeof(int) * (argc - 1));
	if (!tab)
		ft_error();
	i = 1;
	while (i <= argc - 1)
	{
		if (!*argv[i])
			ft_error_tab(tab);
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
