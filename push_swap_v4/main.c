/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/17 20:21:55 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// faire les rotates dans la stack_b directement (en-dessous de la valeur mediane en bas)

// void print_stack_info(stack *the_stack, char choice_stack)
// {
//     printf("stack_%c: %p\n", choice_stack, the_stack);
//     printf("stack_%c->begin: %p\n", choice_stack, the_stack->begin);
//     printf("stack_%c->end: %p\n", choice_stack, the_stack->end);
//     printf("stack_%c->index_max: %d\n", choice_stack, the_stack->index_max);
//     printf("\n\n");
// }

// void print_node_info(stack *the_stack, char choice_stack)
// {
//     node *the_node;
//     node *last_node;
//     int i;

//     i = 1;
//     last_node = the_stack->end;
//     the_node = the_stack->begin;
//     printf("stack_%c:\n", choice_stack);
//     while (i <= the_stack->index_max)
//     {
//         printf("node %d:\n", i);
//         printf("    node_%d->index: %d\n", i, the_node->index);
//         printf("    node_%d->content: %d\n", i, the_node->content);
//         printf("    node_%d->prev: %p\n", i, the_node->prev);
//         printf("    node_%d: %p\n", i, the_node);
//         printf("    node_%d->next: %p\n", i, the_node->next);
//         the_node = the_node->next;
//         i++;
//     }
//     printf("\n\n");
// }

// void print_info(stack *the_stack, char choice_stack)
// {
//     print_stack_info(the_stack, choice_stack);
//     print_node_info(the_stack, choice_stack);
// }

void end_main(stack **stack_a, stack **stack_b)
{
    ft_printf("count: %d\n", (*stack_a)->count + (*stack_b)->count);
    free_all_stack(stack_a, stack_b);
    exit(EXIT_SUCCESS);
}

void particular_case(int argc, stack **stack_a, stack **stack_b)
{
    if (argc == 3)
        sort_two_numbers(stack_a);
    if (argc > 3 && argc <= 6)
        sort_five_numbers(stack_a, stack_b, argc - 1);
    if (argc <= 6)
        end_main(stack_a, stack_b);
}

int main(int argc, char *argv[])
{
    stack *stack_a;
    stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    ft_parse(argc, argv);
    ft_init_stack(&stack_a, &stack_b);
    ft_args_to_list(&stack_a, argc, argv);
    ft_init_index(&stack_a);
    particular_case(argc, &stack_a, &stack_b);
    pre_sort_with_mediane(&stack_a, &stack_b, argc - 1);
    sort_three_numbers(&stack_a);
    ft_init_index(&stack_b);
    ft_main_exec(&stack_a, &stack_b, stack_a->begin, stack_b->begin);
    end_main(&stack_a, &stack_b);
    
    return (0);
}