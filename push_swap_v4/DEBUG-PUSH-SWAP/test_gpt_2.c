
#include <stdio.h>
#include "libft/libft.h"

typedef struct node
{
    int content;
    int index;
    struct node *next;
    struct node *prev;
} node;

typedef struct stack
{
    int index_max;
    struct node *begin;
    struct node *end;
} stack;

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

void ft_init_stack(stack **stack_a, stack **stack_b)
{
    *stack_a = (stack *) malloc(sizeof(stack));
    *stack_b = (stack *) malloc(sizeof(stack));
    (*stack_a)->begin = NULL;
    (*stack_a)->end = NULL;
    (*stack_b)->begin = NULL;
    (*stack_b)->end = NULL;
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
            //(*stack_a)->end = new_node;
        }
        node_tmp = new_node;
        printf("node_tmp %i: %p\n", i, node_tmp);
        i++;
    }
    (*stack_a)->end = node_tmp;
    printf("stack_a->end: %d: %p\n", i-1, (*stack_a)->end);
}


int main(int argc, char *argv[])
{
    stack *stack_a;
    stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    ft_init_stack(&stack_a, &stack_b);
    ft_args_to_list(&stack_a, argc, argv);
    printf("stack_a->begin: %p", stack_a->begin);
    
    return (0);
}
