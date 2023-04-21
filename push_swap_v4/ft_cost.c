/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:16:49 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/12 18:07:22 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FONCTIONS DE COUTS
int ft_cost(stack *stack_a, stack *stack_b, node *node_a, node *node_b)
{
    int ra_up;
    int rb_up;
    int ra_down;
    int rb_down;

    ra_down = stack_a->index_max - node_a->index + 1;
    rb_down = stack_b->index_max - node_b->index + 1;
    ra_up = node_a->index;
    rb_up = node_b->index;
    return (ft_best_combo(ra_up, rb_up, ra_down, rb_down));
}

int ft_cost_index(stack *stack_a, stack *stack_b, node *node_a, node *node_b)
{
    int ra_up;
    int rb_up;
    int ra_down;
    int rb_down;

    ra_down = stack_a->index_max - node_a->index + 1;
    rb_down = stack_b->index_max - node_b->index + 1;
    ra_up = node_a->index;
    rb_up = node_b->index;
 
    return (ft_best_combo_index(ra_up, rb_up, ra_down, rb_down));
}

// int *ft_best_combo()
// {
//     int best_combo;
//     int uu;
//     int dd;
//     int ud;
//     int du;

//     uu = ft_max(ra_up, rb_up);
//     dd = ft_max(ra_down, rb_down);
//     ud = ra_up + rb_dstack_b->index;own
//     du = ra_down + ra_up;

//     if (uu || dd || ud || dd)
//         return ();
// }

int ft_best_combo(int ra_up, int rb_up, int ra_down, int rb_down)
{
    int combo[4];
    int best_combo;
    int i;

    combo[0] = ft_max(ra_up, rb_up); //cost up-up
    combo[1] = ft_max(ra_down, rb_down); //cost down-down
    combo[2] = ra_up + rb_down; //cost up-down
    combo[3] = ra_down + ra_up; //cost down-up
    best_combo = combo[0];
    i = 1;
    while (i < 3)
    {
        if (combo[i] < best_combo)
            best_combo = combo[i];
        i++;
    }

    return (best_combo);
}

int ft_best_combo_index(int ra_up, int rb_up, int ra_down, int rb_down)
{
    int combo[4];
    int best_combo;
    int best_combo_index;
    int i;

    combo[0] = ft_max(ra_up, rb_up); //cost up-up
    combo[1] = ft_max(ra_down, rb_down); //cost down-down
    combo[2] = ra_up + rb_down; //cost up-down
    combo[3] = ra_down + ra_up; //cost down-up
    best_combo = combo[0];
    best_combo_index = 0;
    i = 1;
    while (i < 3)
    {
        if (combo[i] < best_combo)
            best_combo_index = i;
        i++;
    }

    return (best_combo_index);
}

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}