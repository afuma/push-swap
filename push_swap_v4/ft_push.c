/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:49:56 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/17 19:44:15 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// originale
// void push_first(stack **stack_1, stack **stack_2)
// {
//     (*stack_2)->begin = (*stack_1)->begin;
//     (*stack_2)->end = (*stack_1)->begin;
//     (*stack_2)->begin->prev = (*stack_2)->begin;
//     (*stack_2)->begin->next = (*stack_2)->begin;
// }

void push_first(stack **stack_1, stack **stack_2)
{
    (*stack_2)->begin = (*stack_1)->begin;
    (*stack_2)->end = NULL;
    (*stack_2)->begin->prev = NULL;
    (*stack_2)->begin->next = NULL;
}

void push_second(stack **stack_1, stack **stack_2)
{
    node *first_node_1;
    node *first_node_2;
    
    first_node_1 = (*stack_1)->begin;
    first_node_2 = (*stack_2)->begin;
    first_node_1->prev = first_node_2->prev;
    first_node_2->prev = first_node_1;
    first_node_1->next = first_node_2;
    if ((*stack_2)->end == NULL)
        (*stack_2)->end = first_node_2;
    (*stack_2)->end->next = first_node_1;
    first_node_2 = first_node_1;
}

void push(stack **stack_1, stack **stack_2, int is_update_index, char *name_instruction)
{
    node *second_node_1;
    
    second_node_1 = (*stack_1)->begin->next;
    if ((*stack_1)->begin != NULL)
    {
        if ((*stack_2)->begin == NULL)
            push_first(stack_1, stack_2);
        else
            push_second(stack_1, stack_2);
        if (second_node_1 == NULL)
            (*stack_1)->begin = NULL;
        else
        {
            (*stack_1)->begin = second_node_1;
            (*stack_1)->begin->prev = (*stack_1)->end;
            (*stack_1)->end->next = second_node_1;
        }
        ft_all_update_indexes(stack_1, stack_2, is_update_index);
        (*stack_2)->count++;
        ft_printf("%s\n", name_instruction);
    }
}

void pb(stack **stack_a, stack **stack_b, int is_update_index)
{
    //Prend le premier élément au sommet de a et le met sur b.
    //Ne fait rien si a est vide.
    push(stack_a, stack_b, is_update_index, "pb");
}

void pa(stack **stack_a, stack **stack_b, int is_update_index)
{
    //Prend le premier élément au sommet de b et le met sur a.
    //Ne fait rien si b est vide.
    push(stack_b, stack_a, is_update_index, "pa");
}

// version pushswap 3 modifier a->1, b->2
// void pb(stack **stack_1, stack **stack_2, int is_update_index)
// {
// //         Prend le premier élément au sommet de a et le met sur b.
// //         Ne fait rien si a est vide.
//     node *second_node_1;
    
//     second_node_1 = (*stack_1)->begin->next;
//     if ((*stack_1)->begin != NULL)
//     {
//         if ((*stack_2)->begin == NULL)
//         {
//             (*stack_2)->begin = (*stack_1)->begin;
//             (*stack_2)->end = (*stack_1)->begin;
//             (*stack_2)->begin->prev = (*stack_2)->begin;
//             (*stack_2)->begin->next = (*stack_2)->begin;
//         }
//         else
//         {
//             (*stack_1)->begin->prev = (*stack_2)->begin->prev;
//             (*stack_2)->begin->prev = (*stack_1)->begin;
//             (*stack_1)->begin->next = (*stack_2)->begin;
//             (*stack_2)->end->next = (*stack_1)->begin;
//             (*stack_2)->begin = (*stack_1)->begin;
//         }
//         (*stack_1)->begin = second_node_1;
//         (*stack_1)->begin->prev = (*stack_1)->end;
//         (*stack_1)->end->next = second_node_1;
//         ft_all_update_indexes(stack_1, stack_2, is_update_index);
//     }
// }

// version pushswap 3
// void pa(stack **stack_a, stack **stack_b, int is_update_index)
// {
// //     Prend le premier élément au sommet de b et le met sur a.
// //     Ne fait rien si b est vide.
//     node *second_node_b;
    
//     second_node_b = (*stack_b)->begin->next;
//     if ((*stack_b)->begin != NULL)
//     {
//         if ((*stack_a)->begin == NULL)
//         {
//             (*stack_a)->begin = (*stack_b)->begin;
//             (*stack_a)->begin->prev = NULL;
//             (*stack_a)->begin->next = NULL;
//         }
//         else
//         {
//             (*stack_b)->begin->prev = (*stack_a)->begin->prev;
//             (*stack_a)->begin->prev = (*stack_b)->begin;
//             (*stack_b)->begin->next = (*stack_a)->begin;
//         }
//         (*stack_b)->begin = second_node_b;
//         ft_all_update_indexes(stack_b, stack_a, is_update_index);
//     }
// }

// version pushswap 3
// void pb(stack **stack_a, stack **stack_b, int is_update_index)
// {
// //         Prend le premier élément au sommet de a et le met sur b.
// //         Ne fait rien si a est vide.
//     node *second_node_a;
    
//     second_node_a = (*stack_a)->begin->next;
//     if ((*stack_a)->begin != NULL)
//     {
//         if ((*stack_b)->begin == NULL)
//         {
//             (*stack_b)->begin = (*stack_a)->begin;
//             (*stack_b)->end = (*stack_a)->begin;
//             (*stack_b)->begin->prev = (*stack_b)->begin;
//             (*stack_b)->begin->next = (*stack_b)->begin;
//         }
//         else
//         {
//             (*stack_a)->begin->prev = (*stack_b)->begin->prev;
//             (*stack_b)->begin->prev = (*stack_a)->begin;
//             (*stack_a)->begin->next = (*stack_b)->begin;
//             (*stack_b)->end->next = (*stack_a)->begin;
//             (*stack_b)->begin = (*stack_a)->begin;
//         }
//         (*stack_a)->begin = second_node_a;
//         (*stack_a)->begin->prev = (*stack_a)->end;
//         (*stack_a)->end->next = second_node_a;
//         ft_all_update_indexes(stack_a, stack_b, is_update_index);
//     }
// }