/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:03 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 20:51:48 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	ft_make_order(t_stack **stack)
{
	int	ind_min;
	int	size;

	ind_min = ft_find_min(*stack)->index;
	size = ft_last(*stack)->index;
	if (ind_min <= size / 2)
	{
		while (ind_min > 0)
			(write(1, "ra\n", 3), ft_rotate(stack), ind_min--);
	}
	else
	{
		while (ind_min <= size)
			(write(1, "rra\n", 4), ft_r_rotate(stack), ind_min++);
	}
}

bool	ft_is_completed_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
