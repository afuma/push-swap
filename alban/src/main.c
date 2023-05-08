/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 20:46:32 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_sorted(t_stack *stack_a)
{
	int	min;
	int	max;

	min = ft_find_min(stack_a)->nbr;
	max = ft_find_max(stack_a)->nbr;
	while (stack_a->next)
	{
		if (stack_a->nbr == max)
		{
			if (stack_a->next->nbr != min)
				return (false);
		}
		else if (stack_a->nbr > stack_a->next->nbr)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	ft_make_all(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_last(*stack_b)->index;
	while (i >= 0)
	{
		ft_make_best_combo(stack_a, stack_b);
		i--;
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_last(*stack_a)->index;
	if (!ft_is_sorted(*stack_a))
	{
		while (i > 2)
		{
			ft_push(stack_a, stack_b);
			write(1, "pb\n", 3);
			i--;
		}
		if (!ft_is_sorted(*stack_a))
		{
			ft_swap(stack_a);
			write(1, "sa\n", 3);
		}
		if (*stack_b)
			ft_make_all(stack_a, stack_b);
	}
	ft_make_order(stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!*argv[1])
		return (0);
	ft_parse(&stack_a, argc, argv);
	ft_set_index(stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_make_order(&stack_a);
	ft_stackclear(&stack_a);
	return (0);
}
