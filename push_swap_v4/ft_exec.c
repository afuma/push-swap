/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/12 16:55:11 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// les fonctions de couts pour trouver la solution la plus optimise
// u: up et d: down

// FONCTIONS D'EXECUTION
// Objectif: trouver le cout minimum en fonction de la pile A et de la pile B
void ft_main_exec(stack **stack_a, stack **stack_b, node *node_a, node *node_b)
{
    node *tmp_node_b;
    int cost_stack_b; // variable local
    int tmp_cost; // variable local
    int index_elem[2]; // index_elem_a et index_elem_b
    int dispatch_cost_stack_b;

    tmp_node_b = node_b;
    index_elem[0] = node_a->index;
    index_elem[1] = node_b->index;
    cost_stack_b = ft_cost(*stack_a, *stack_b, node_a, tmp_node_b);
    dispatch_cost_stack_b = ft_cost_index(*stack_a, *stack_b, node_a, tmp_node_b);
    while (tmp_node_b->next != (*stack_b)->end)
    {
        tmp_cost = ft_cost(*stack_a, *stack_b, node_a, tmp_node_b);
        if (tmp_cost < cost_stack_b)
        {
            dispatch_cost_stack_b = ft_cost_index(*stack_a, *stack_b, node_a, tmp_node_b);
            cost_stack_b = tmp_cost;
            index_elem[0] = node_a->index;
            index_elem[1] = tmp_node_b->index;
        }
        tmp_node_b = tmp_node_b->next;
    }
    ft_dispatch(stack_a, stack_b, dispatch_cost_stack_b, index_elem);
    pb(stack_a, stack_b, 1);
}

void ft_exec_uu(stack **stack_a, stack **stack_b, int index_elem[2])
{
    int tmp_index_a;
    int tmp_index_b;

    tmp_index_a = index_elem[0];
    tmp_index_b = index_elem[1];
    while (tmp_index_a != 0 && tmp_index_b != 0)
    {
        rr(stack_a, stack_b);
        tmp_index_a--;
        tmp_index_b--;
    }
    while (tmp_index_a != 0)
    {
        ra(stack_a);
        tmp_index_a--;
    }
    while (tmp_index_b != 0)
    {
        rb(stack_b);
        tmp_index_b--;
    }
}

void ft_exec_dd(stack **stack_a, stack **stack_b, int index_elem[2])
{
    int tmp_index_a;
    int tmp_index_b;

    tmp_index_a = index_elem[0];
    tmp_index_b = index_elem[1];
    while (tmp_index_a != 0 && tmp_index_b != 0)
    {
        rrr(stack_a, stack_b);
        tmp_index_a--;
        tmp_index_b--;
    }
    while (tmp_index_a != 0)
    {
        rra(stack_a);
        tmp_index_a--;
    }
    while (tmp_index_b != 0)
    {
        rrb(stack_b);
        tmp_index_b--;
    }
}

void ft_exec_ud(stack **stack_a, stack **stack_b, int index_elem[2])
{
    int tmp_index_a;
    int tmp_index_b;

    tmp_index_a = index_elem[0];
    tmp_index_b = index_elem[1];
    while (tmp_index_a != 0)
    {
        ra(stack_a);
        tmp_index_a--;
    }
    while (tmp_index_b != 0)
    {
        rrb(stack_b);
        tmp_index_b--;
    }
}

void ft_exec_du(stack **stack_a, stack **stack_b, int index_elem[2])
{
    int tmp_index_a;
    int tmp_index_b;

    tmp_index_a = index_elem[0];
    tmp_index_b = index_elem[1];
    while (tmp_index_a != 0)
    {
        rra(stack_a);
        tmp_index_a--;
    }
    while (tmp_index_b != 0)
    {
        rb(stack_b);
        tmp_index_b--;
    }
}

// 2
// 4 3 // 2 couts pour placer 3 correctement
// 5 9 // 

// 6
// 9 8 // 2 couts pour placer 8 correctement
// 10 2 // 2 couts pour placer 2 correctement 