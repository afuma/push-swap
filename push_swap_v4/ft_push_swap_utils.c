/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:21:48 by edesaint          #+#    #+#             */
/*   Updated: 2023/03/30 23:38:01 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_update_indexes(stack *the_stack, int sens)
{

    // Update all index (index of each element of the stack)
    // +1 in index when your add an element for each element
    // -1 in index when your pop an element for each element

    //         Parameters:
    //                 the_stack (stack): one of the stack (A or B)
    //                 sens (int): the direction of the stack (+1 if down, -1 if up)
    //                     (graphic representation of a stack, last in first out(LIFO))

    //         Returns:
    //                 cpt (int): the maximum index of the stack (A or B)

    node *the_node;
    node *node_end;

    the_node = the_stack->begin;
    node_end = the_stack->end;
    if (the_node != NULL)
    {
        while (the_node != node_end)
        {
            the_node->index = the_node->index + sens;
            the_node = the_node->next;
        }
    }
}

void ft_all_update_indexes(stack **stack_1, stack **stack_2, int is_update_index)
{
    (*stack_1)->index_max = (*stack_1)->index_max - 1;
    (*stack_2)->index_max = (*stack_2)->index_max + 1;
    if (is_update_index)
    {
        ft_update_indexes(*stack_1, -1);
        ft_update_indexes(*stack_2, 1);
    }
}