/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quartiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:27:45 by edesaint          #+#    #+#             */
/*   Updated: 2023/03/25 17:44:09 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void pre_sort_with_quartile(stack *stack_a, stack *stack_b, int index_max)
{
    int index_tmp;
    int quartile_values[3];
    int quartile[3];
    int i;
    
    quartile_values[0] = stack_a->index_max / 4 + 1;
    quartile_values[1] = stack_a->index_max / 2 + 1;
    quartile_values[2] = 3 * stack_a->index_max / 4 + 1;
    index_tmp = stack_a->index_max;
    quartile[i] = ft_quartile(stack_a, quartile_values[i]);
    i = 2;
    while (i >= 0)
    {
        while (index_tmp > quartile_values[i])
        {
                current_index = ft_find_quartile();
                move_to_up(stack_a, stack_a->index, mediane);
                pb(stack_a, stack_b);
            index_tmp--;
        }
        i--;
    }
}

int ft_find_quartile(stack *stack_a, int quartile, int quartile_value)
{
    // int index_tmp;
    // int current_index;
    
    // current_index = stack_a->index;
    // while (index_tmp > quartile_value)
    // {
    //     if (stack_a->content <= quartile)
    //         return (stack_a->index);
    // }
            
    while (stack_a->next != NULL)
    {
        if (stack_a->content <= quartile)
            return (stack_a->index);
        stack_a = stack_a->next;
    }
}

int ft_quartile(stack *stack_a, int quartile_value)
{
    int quartile;

    while (stack_a->index != quartile_value)
        stack_a = stack_a->next;
    quartile = (stack_a->content + stack_a->next->content) / 2 + 1;
    
    return (quartile);
}