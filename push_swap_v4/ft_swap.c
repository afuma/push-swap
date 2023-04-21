/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:35 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/14 15:13:34 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(stack **the_stack, char *name_instruction)
{
    node *node_tmp;
    node *the_node;

    the_node = (*the_stack)->begin;
    if (the_node != NULL && the_node->prev == (*the_stack)->end)
    {
        node_tmp = the_node->next;
        the_node->prev = node_tmp;
        the_node->next = node_tmp->next;
        node_tmp->prev = (*the_stack)->end;
        node_tmp->index = the_node->index;
        the_node->index = node_tmp->index;
        (*the_stack)->begin = node_tmp;
        (*the_stack)->count++;
        ft_printf("%s\n", name_instruction);
    }
}

void sa(stack **stack_a)
{
    swap(stack_a, "sa");
}

void sb(stack **stack_b)
{
    swap(stack_b, "sb");
}

void ss(stack **stack_a, stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}