/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/13 17:28:06 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_init_stack(stack **stack_a, stack **stack_b)
{
    *stack_a = (stack *) malloc(sizeof(stack));
    *stack_b = (stack *) malloc(sizeof(stack));
    (*stack_a)->begin = NULL;
    (*stack_a)->end = NULL;
    (*stack_b)->begin = NULL;
    (*stack_b)->end = NULL;
    (*stack_a)->index_max = 0;
    (*stack_b)->index_max = 0;
    (*stack_a)->count = 0;
    (*stack_b)->count = 0;

    // printf("1-stack_a: %p\n", *stack_a);
    // printf("stack_b: %p\n", *stack_b);
    // printf("(*stack_a)->begin: %p\n", (*stack_a)->begin);
}

void ft_args_to_list(stack **stack_a, int argc, char *argv[])
{
    node *node_tmp;
    node *new_node;
    int valid_arg;
    int i;

    i = 1;
    node_tmp = NULL;
    while (i <= argc - 1)
    {
        valid_arg = ft_atoi(argv[i]);
        new_node = ft_new_node(valid_arg);
        if (node_tmp == NULL)
        {
            (*stack_a)->begin = new_node;
            (*stack_a)->end = new_node;
        }
        else
        {
            node_tmp->next = new_node;
            new_node->prev = node_tmp;
        }
        node_tmp = new_node;
        i++;
    }
    (*stack_a)->end = node_tmp;
}

void ft_init_index(stack **the_stack)
{
    node *the_node;
    node *last_node;
    int i;
    
    the_node = (*the_stack)->begin;
    last_node = (*the_stack)->end;
    i = 1;
    if (the_node == NULL)
		return ;
	while (the_node != last_node)
    {
        the_node->index = i;
		the_node = the_node->next;
        i++;
    }
	the_node->index = i;
    (*the_stack)->index_max = i;
    (*the_stack)->begin->prev = (*the_stack)->end;
    (*the_stack)->end->next = (*the_stack)->begin;
}

// void ft_init_circular(stack *stack_a, stack *stack_b)
// {
//     node *first_node;
//     node *last_node;

//     first_node = the_stack->begin;
//     last_node = the_stack->end;
//     first_node->prev = last_node->next;
//     //the_stack->begin->prev = the_stack->end->next;
// }