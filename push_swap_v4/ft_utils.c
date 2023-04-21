/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:14:11 by edesaint          #+#    #+#             */
/*   Updated: 2023/03/31 15:26:35 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*ft_new_node(int content)
{
	node	*li;

	li = (node *) malloc(sizeof(node));
	if (!li)
		return (NULL);
	li->content = content;
	li->next = NULL;
	
	return (li);
}

node	*ft_last_node(node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
		
	return (lst);
}

void	ft_addback_node(node **lst, node *newer)
{
	node	*l;

	if (!lst || !newer)
		return ;
	if (*lst)
	{
		l = ft_last_node(*lst);
		l->next = newer;
		newer->prev = l;
	}
	else
		*lst = newer;
}

void	free_stack(stack **the_stack, int type_clean)
{
	node	*the_node;
	node 	*last_node;
	node	*node_suiv;

	the_node = (*the_stack)->begin;
	last_node = (*the_stack)->end;
	if (type_clean == 1)
	{
		while (the_node != last_node)
		{
			node_suiv = the_node->next;
			free(the_node);
			the_node = NULL;
			the_node = node_suiv;
		}
		free(the_node);
		the_node = NULL;
	}
	if (type_clean == 2)
	{
		free(*the_stack);
		*the_stack = NULL;
		the_stack = NULL;
	}
}

void free_all_stack(stack **stack_a, stack **stack_b)
{
    free_stack(stack_a, 1);
    free_stack(stack_a, 2);
    free_stack(stack_b, 1);
    free_stack(stack_b, 2);
}