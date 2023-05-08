/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:16:49 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 20:45:21 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cost(t_stack *stack_a, t_stack *stack_b, int ind_a, int ind_b)
{
	return (ft_best_combo(ind_a, ind_b, \
		ft_last(stack_a)->index - ind_a, \
		ft_last(stack_b)->index - ind_b)
	);
}

int	ft_cost_index(t_stack *stack_a, t_stack *stack_b, int ind_a, int ind_b)
{
	return (ft_best_combo_index(ind_a, ind_b, \
		ft_last(stack_a)->index - ind_a, \
		ft_last(stack_b)->index - ind_b)
	);
}

int	ft_best_combo(int ra_up, int rb_up, int ra_down, int rb_down)
{
	int	combo[4];
	int	best_combo;
	int	i;

	combo[0] = ft_max(ra_up, rb_up);
	combo[1] = ft_max(ra_down, rb_down) + 1;
	combo[2] = ra_up + rb_down + 1;
	combo[3] = ra_down + rb_up + 1;
	best_combo = combo[0];
	i = 1;
	while (i < 4)
	{
		if (combo[i] <= best_combo)
			best_combo = combo[i];
		i++;
	}
	return (best_combo);
}

int	ft_best_combo_index(int ra_up, int rb_up, int ra_down, int rb_down)
{
	int	combo[4];
	int	best_combo;
	int	best_combo_index;
	int	i;

	combo[0] = ft_max(ra_up, rb_up);
	combo[1] = ft_max(ra_down, rb_down) + 1;
	combo[2] = ra_up + rb_down + 1;
	combo[3] = ra_down + rb_up + 1;
	best_combo = combo[0];
	best_combo_index = 0;
	i = 1;
	while (i < 4)
	{
		if (combo[i] <= best_combo)
		{
			best_combo_index = i;
			best_combo = combo[i];
		}
		i++;
	}
	return (best_combo_index);
}
