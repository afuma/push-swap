/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 20:54:39 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_suiv_a(t_stack *stack_a, t_stack *node_b)
{
	t_stack	*node_a;
	int		sup_a;
	int		val_b;

	node_a = stack_a;
	sup_a = ft_find_max(stack_a)->nbr;
	val_b = node_b->nbr;
	if (val_b > sup_a)
		return (ft_find_min(stack_a));
	while (stack_a)
	{
		if (stack_a->nbr > val_b && stack_a->nbr <= sup_a)
		{
			sup_a = stack_a->nbr;
			node_a = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (node_a);
}

t_stack	*ft_find_best_elem(t_stack *stack_a, t_stack *stack_b)
{
	int		ind_a;
	int		cost_stack_b;
	int		tmp_cost;
	t_stack	*elem;

	cost_stack_b = INT_MAX;
	elem = stack_b;
	while (stack_b)
	{
		ind_a = ft_suiv_a(stack_a, stack_b)->index;
		tmp_cost = ft_cost(stack_a, stack_b, ind_a, stack_b->index);
		if (tmp_cost < cost_stack_b)
		{
			elem = stack_b;
			cost_stack_b = tmp_cost;
		}
		stack_b = stack_b->next;
	}
	return (elem);
}

void	ft_make_best_combo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_elem;
	int		ind_a;
	int		best_combo;

	best_elem = ft_find_best_elem(*stack_a, *stack_b);
	ind_a = ft_suiv_a(*stack_a, best_elem)->index;
	best_combo = ft_cost_index(*stack_a, *stack_b, ind_a, best_elem->index);
	if (best_combo == 0)
		ft_exec_uu(stack_a, stack_b, ind_a, best_elem->index);
	else if (best_combo == 1)
		ft_exec_dd(stack_a, stack_b, ind_a, best_elem->index);
	else if (best_combo == 2)
		ft_exec_ud(stack_a, stack_b, ind_a, best_elem->index);
	else if (best_combo == 3)
		ft_exec_du(stack_a, stack_b, ind_a, best_elem->index);
	else
		ft_error();
}
