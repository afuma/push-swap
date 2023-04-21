/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_trie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:46:28 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/17 19:04:21 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    sort(stack **stack_a, int min, int max)
{
    node    *current;

    current = (*stack_a)->begin;
    if (current->content == min)
    {
        if (current->next->content != max)
            return (0);
        else
            return (rra(stack_a), sa(stack_a), 0);
    }
    else if (current->content == max)
    {
        if (current->next->content != min)
            return (sa(stack_a), rra(stack_a), 0);
        else
            return (ra(stack_a), 0);
    }
    else
    {
        if (current->next->content == min)
            sa(stack_a);
        else
            rra(stack_a);
    }
    return (0);
}

int    sort_three_numbers(stack **stack_a)
{
    int        min;
    int        max;

    min = find_min(stack_a);
    max = find_max(stack_a);
    sort(stack_a, min, max);
    return (0);
}

int    find_position(stack **stack_a, int min)
{
    node    *current;
    int        position;

    position = 0;
    current = (*stack_a)->begin;
    while (current)
    {
        if (current->content == min)
            return (position);
        position++;
        current = current->next;
    }
    return (position);
}

void    push_min(stack **stack_a, stack **stack_b, int min)
{
    int    position;
    node *current;
    
    current = (*stack_a)->begin;
    position = find_position(stack_a, min);
    while (current->content != min)
    {
        if (position < 3)
            ra(stack_a);
        else
            rra(stack_a);
        current = current->next;
    }
    pb(stack_a, stack_b, 0);
}

void    sort_five_numbers(stack **stack_a, stack **stack_b, int limit)
{
    (void)stack_a;
    (void)stack_b;
    if (limit >= 4)
        push_min(stack_a, stack_b, find_min(stack_a));
    if (limit >= 5)
        push_min(stack_a, stack_b, find_min(stack_a));
    sort_three_numbers(stack_a);
    if (limit >= 4)
        pa(stack_a, stack_b, 0);
    if (limit >= 5)
        pa(stack_a, stack_b, 0);
}