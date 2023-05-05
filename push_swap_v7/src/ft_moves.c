/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:35 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 20:50:23 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	val;

	if ((*stack)->next)
	{
		val = (*stack)->nbr;
		(*stack)->nbr = (*stack)->next->nbr;
		(*stack)->next->nbr = val;
	}
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		ft_addback(&tmp, *stack);
		*stack = tmp;
		ft_set_index(*stack);
	}
}

void	ft_r_rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*stack)->next)
	{
		tmp1 = ft_last(*stack);
		tmp2 = *stack;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		ft_addfront(stack, tmp1);
		ft_set_index(*stack);
	}
}

void	ft_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_addfront(stack_dst, tmp);
	ft_set_index(*stack_src);
	ft_set_index(*stack_dst);
}
