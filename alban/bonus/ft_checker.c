/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/08 14:20:37 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line_bonus.h"

static int	ft_is_cmd_exist(char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 4) || !ft_strncmp(cmd, "pb\n", 4)
		|| !ft_strncmp(cmd, "ra\n", 4) || !ft_strncmp(cmd, "rb\n", 4)
		|| !ft_strncmp(cmd, "rr\n", 4) || !ft_strncmp(cmd, "rra\n", 5)
		|| !ft_strncmp(cmd, "rrb\n", 5) || !ft_strncmp(cmd, "rrr\n", 5)
		|| !ft_strncmp(cmd, "sa\n", 4) || !ft_strncmp(cmd, "sb\n", 4)
	)
		return (1);
	return (0);
}

void	ft_execute_cmd_rr(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "rra\n", 5))
		ft_r_rotate(stack_a);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		ft_r_rotate(stack_b);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
	{
		ft_r_rotate(stack_a);
		ft_r_rotate(stack_b);
	}
}

static int	ft_execute_cmd(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_is_cmd_exist(cmd))
		return (0);
	ft_execute_cmd_rr(stack_a, stack_b, cmd);
	if (!ft_strncmp(cmd, "pa\n", 4))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ft_rotate(stack_a);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		ft_rotate(stack_b);
	else if (!ft_strncmp(cmd, "rr\n", 4))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (!ft_strncmp(cmd, "sa\n", 4))
		ft_swap(stack_a);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		ft_swap(stack_b);
	return (1);
}

static int	ft_execute_program(t_stack **stack_a, t_stack **stack_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!ft_execute_cmd(stack_a, stack_b, cmd))
		{
			free(cmd);
			return (0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_parse(&stack_a, argc, argv);
	ft_set_index(stack_a);
	ft_execute_program(&stack_a, &stack_b);
	if (ft_is_completed_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stackclear(&stack_a);
	return (0);
}
