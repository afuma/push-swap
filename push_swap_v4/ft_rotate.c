/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:07:32 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/13 14:16:46 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void rotate(stack *the_stack)
// {
// '''
//     Décale dune position vers le haut tous les élements de la pile a.
//     Le premier élément devient le dernier.
// '''
//     stack *first_elem;
//     stack *stack_tmp;

//     stack_tmp = the_stack;
//     first_elem = the_stack;
//     the_stack = the_stack->next;
//     ft_update_indexes(the_stack, -1);
//     stack_tmp = ft_stack_last(stack_tmp);
//     stack_tmp->next = first_elem;
//     first_elem->prev = stack_tmp;
//     first_elem->next = NULL;
//     first_elem->index = first_elem->max_index;
// }

void rotate(stack **the_stack, char *name_instruction)
{

    // Décale dune position vers le haut tous les élements de la pile a.
    // Le premier élément devient le dernier.

    if ((*the_stack)->begin != NULL && (*the_stack)->begin->next != (*the_stack)->end)
    {
        (*the_stack)->end = (*the_stack)->begin;
        (*the_stack)->begin = (*the_stack)->begin->next;
        ft_update_indexes(*the_stack, -1);
        (*the_stack)->count++;
        ft_printf("%s\n", name_instruction);
    }
}

void ra(stack **stack_a)
{
    rotate(stack_a, "ra");
}

void rb(stack **stack_b) //a changer les a en b
{
    rotate(stack_b, "rb");
}

void rr(stack **stack_a, stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}