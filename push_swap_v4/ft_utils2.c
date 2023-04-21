/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:03 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/17 20:18:10 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(stack **the_stack)
{
    node *current;
    int min;
    
    // print_info(*the_stack, 'a');
    current = (*the_stack)->begin;
    min = current->content;
    current = current->next;
    while (current != (*the_stack)->end)
    {
        if (current->content < min)
            min = current->content;
        current = current->next;
    }
    if (current->content < min)
        min = current->content;
    return (min);
}

int find_max(stack **the_stack)
{
    node *current;
    int max;
    
    current = (*the_stack)->begin;
    max = current->content;
    current = current->next;
    while (current != (*the_stack)->end)
    {
        if (current->content > max)
            max = current->content;
        current = current->next;
    }
    if (current->content > max)
        max = current->content;

    return (max);
}

void    sort_two_numbers(stack **stack_a)
{
    node *first_node;

    first_node = (*stack_a)->begin;
    if (first_node->next->content < first_node->content)
        sa(stack_a);
}