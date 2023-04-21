/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:00 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/12 15:50:37 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void reverse_rotate(stack *the_stack)
// {
// '''
//     Décale dune position vers le bas tous les élements de la pile A ou B.
//     Le dernier élément devient le premier.
// '''
//     stack *last_elem;
//     stack *stack_tmp;

//     stack_tmp = the_stack;
//     last_elem = ft_stack_last(stack_tmp);
//     ft_update_indexes(the_stack, 1);
//     stack_tmp->prev = last_elem;
//     last_elem->prev = NULL;
//     last_elem->next = stack_tmp;
//     last_elem->index = 1;
// }

void reverse_rotate(stack **the_stack, char *name_instruction)
{

    // Décale dune position vers le bas tous les élements de la pile A ou B.
    // Le dernier élément devient le premier.

    (*the_stack)->begin = (*the_stack)->begin->prev;
    (*the_stack)->end = (*the_stack)->end->prev;
    ft_update_indexes(*the_stack, 1);
    (*the_stack)->count++;
    ft_printf("%s\n", name_instruction);
}

void rra(stack **stack_a)
{
    reverse_rotate(stack_a, "rra");
}

void rrb(stack **stack_b)
{
    reverse_rotate(stack_b, "rrb");
}

void rrr(stack **stack_a, stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}