/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 18:42:09 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_args_to_list(t_stack **stack_a, int argc, char *argv[])
{
	t_stack	*new_node;
	int		valid_arg;
	int		i;

	i = 1;
	while (i <= argc - 1)
	{
		valid_arg = ft_atoi(argv[i]);
		new_node = ft_new_node(valid_arg);
		if (!new_node)
			return (ft_stackclear(stack_a));
		else
			ft_addback(stack_a, new_node);
		i++;
	}
}

void	ft_args_to_list_2(t_stack **stack_a, char **args)
{
	t_stack	*new_node;
	int		valid_arg;
	int		i;

	i = 0;
	while (args[i])
	{
		valid_arg = ft_atoi(args[i]);
		new_node = ft_new_node(valid_arg);
		if (!new_node)
			return (ft_stackclear(stack_a));
		else
			ft_addback(stack_a, new_node);
		i++;
	}
}

void	ft_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}
