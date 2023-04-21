/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:26:25 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/13 15:50:49 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void pre_sort_with_mediane(stack **stack_a, stack **stack_b, int index_max)
{
    int mediane_value;
    int mediane;
    int i;
    
    i = index_max;
    mediane_value = index_max / 2 + 1;
    mediane = ft_mediane((*stack_a)->begin, mediane_value);
    while (i > 3)
    {
        pb(stack_a, stack_b, 0);
        if ((*stack_b)->begin->content <= mediane)
            rb(stack_b);
        i--;
    }
}

int ft_mediane(node *the_node, int mediane_value)
{
    int mediane;
    node *node_suiv;
    
    if (the_node == NULL)
        return (-1);
    while (the_node->index != mediane_value)
        the_node = the_node->next;
    node_suiv = the_node->next;
    mediane = (the_node->content + node_suiv->content) / 2 + 1;
    
    return (mediane);
}