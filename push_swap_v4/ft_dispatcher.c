/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:18:36 by edesaint          #+#    #+#             */
/*   Updated: 2023/03/30 20:00:18 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_dispatch(stack **stack_a, stack **stack_b, int best_combo, int index_elem[2])
{
    if (best_combo == 0)
        ft_exec_uu(stack_a, stack_b, index_elem);
    else if (best_combo == 1)
        ft_exec_dd(stack_a, stack_b, index_elem);
    else if (best_combo == 2)
        ft_exec_ud(stack_a, stack_b, index_elem);
    else if (best_combo == 3)
        ft_exec_du(stack_a, stack_b, index_elem);
    else
        ft_error();
}
