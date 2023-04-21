// les fonctions de couts pour trouver la solution la plus optimise
// u: up et d: down

#include "push_swap.h"

// -------------------------------------------------------------------

int ft_max(int a, int b){
    if (a > b)
        return (a);
    else
        return (b);
}

int ft_cost_u(stack stack)
{
    return (stack->index);
}

int ft_cost_d(stack stack)
{
    return (stack_a->index_max - stack_a->index + 1);
}

// FONCTIONS DE COUTS
int ft_cost_uu(stack stack_a, stack stack_b)
{
    return (ft_max(ft_cost_u(stack_a), ft_cost_u(stack_b)));
}

int ft_cost_dd()
{
    return (ft_max(ft_cost_d(stack_a), ft_cost_d(stack_b)));
}

int ft_cost_ud()
{
    return (ft_cost_u(stack_a) + ft_cost_d(stack_b));
}

int ft_cost_du()
{
    return (ft_cost_d(stack_a) + ft_cost_u(stack_b));
}

// -------------------------------------------------------------------

// FONCTIONS D'EXECUTION
void ft_exec_uu(stack stack_a, stack stack_b)
{
    while (stack_a->index != 0)
    {
        ra
    }
}

void ft_exec_dd(stack stack_a, stack stack_b)
{
    
}

void ft_exec_ud(stack stack_a, stack stack_b)
{
    
}

void ft_exec_du(stack stack_a, stack stack_b)
{
    
}