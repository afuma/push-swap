/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:04:55 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 21:09:28 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exec_uu(t_stack **stack_a, t_stack **stack_b, int ind_a, int ind_b)
{
	while (ind_a > 0 && ind_b > 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		write(1, "rr\n", 3);
		ind_a--;
		ind_b--;
	}
	while (ind_a > 0)
	{
		ft_rotate(stack_a);
		write(1, "ra\n", 3);
		ind_a--;
	}
	while (ind_b > 0)
	{
		ft_rotate(stack_b);
		write(1, "rb\n", 3);
		ind_b--;
	}
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_exec_dd(t_stack **stack_a, t_stack **stack_b, int ind_a, int ind_b)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_last(*stack_a)->index;
	size_stack_b = ft_last(*stack_b)->index;
	while (ind_a <= size_stack_a && ind_b <= size_stack_b)
	{
		ft_r_rotate(stack_a);
		ft_r_rotate(stack_b);
		write(1, "rrr\n", 4);
		ind_a++;
		ind_b++;
	}
	ft_add_exex_dd(stack_a, ind_a, size_stack_a, "rra\n");
	ft_add_exex_dd(stack_b, ind_b, size_stack_b, "rrb\n");
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_exec_ud(t_stack **stack_a, t_stack **stack_b, int ind_a, int ind_b)
{
	int	size_stack_b;

	size_stack_b = ft_last(*stack_b)->index;
	while (ind_a > 0)
	{
		ft_rotate(stack_a);
		write(1, "ra\n", 3);
		ind_a--;
	}
	while (ind_b <= size_stack_b)
	{
		ft_r_rotate(stack_b);
		write(1, "rrb\n", 4);
		ind_b++;
	}
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_exec_du(t_stack **stack_a, t_stack **stack_b, int ind_a, int ind_b)
{
	int	size_stack_a;

	size_stack_a = ft_last(*stack_a)->index;
	while (ind_a <= size_stack_a)
	{
		ft_r_rotate(stack_a);
		write(1, "rra\n", 4);
		ind_a++;
	}
	while (ind_b > 0)
	{
		ft_rotate(stack_b);
		write(1, "rb\n", 3);
		ind_b--;
	}
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_add_exex_dd(t_stack **stack, int ind, int size_stack, char *inst)
{
	while (ind <= size_stack)
	{
		ft_r_rotate(stack);
		write(1, inst, 4);
		ind++;
	}
}
