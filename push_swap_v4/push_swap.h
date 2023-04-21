/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:17:17 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/14 18:29:23 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct node
{
	int content;
    int index;
	struct node	*next;
    struct node	*prev;
}	node;

typedef struct stack
{
	int index_max;
	int count;
	struct node *begin;
	struct node *end;
}	stack;

/*
------------------------------------------------------------
                        Graphiquement

    next -> vers le bas (a partir du debut de la liste)
    prev -> vers le haut
    
------------------------------------------------------------
*/

void print_stack_info(stack *the_stack, char choice_stack);
void print_node_info(stack *the_stack, char choice_stack);
void print_info(stack *the_stack, char choice_stack);

// FONCTIONS DU MAIN
int main(int argc, char *argv[]);
void end_main(stack **stack_a, stack **stack_b);
void particular_case(int argc, stack **stack_a, stack **stack_b);
// FONCTIONS DE BASES POUR MANIPULER LES LISTES CHAINEES
// ft_utils.c
node    *ft_new_node(int content);
void        ft_addback_node(node **lst, node *newer);
node	*ft_last_node(node *lst);
void	free_stack(stack **the_stack, int type_clean);
void free_all_stack(stack **stack_a, stack **stack_b);
// ft_utils2.c
int find_min(stack **the_stack);
int find_max(stack **the_stack);
void    sort_two_numbers(stack **stack_a);

// FONCTIONS DE DEBUT (VERIFICATION DES ARGUMENTS, PASSAGE EN LISTE CHAINEE DES ARGUMENTS)
// ft_parse.c
void ft_error();
int is_doublon(int *tab, int last_index);
int is_valid_number(char *argv);
void ft_parse(int argc, char *argv[]);
// ft_init.c
void ft_init_stack(stack **stack_a, stack **stack_b);
void ft_args_to_list(stack **stack_a, int argc, char *argv[]);
void ft_init_index(stack **the_stack);
// ft_preprocess.c
void pre_sort_with_mediane(stack **stack_a, stack **stack_b, int index_max);
int ft_mediane(node *node, int mediane_value);

//FONCTIONS DE TRIE LE PLUS OPTIMISER JUSQUA 5 VALEURS
//ft_first_trie.c
int    sort(stack **stack_a, int min, int max);
int    sort_three_numbers(stack **stack_a);
int    find_position(stack **stack_a, int min);
void    push_min(stack **stack_a, stack **stack_b, int min);
void    sort_five_numbers(stack **stack_a, stack **stack_b, int limit);

//FONCTIONS DE MISE A JOUR ET DE PREPARATION POUR LES CALCULS DE COUTS
// push_swap_utils.c
void ft_update_indexes(stack *the_stack, int sens);
void ft_all_update_indexes(stack **stack_1, stack **stack_2, int is_update_index);

// FONCTIONS DU SUJET
// ft_swap.c
void swap(stack **the_stack, char *name_instruction);
void sa(stack **stack_a);
void sb(stack **stack_b);
void ss(stack **stack_a, stack **stack_b);
// ft_push.c
void push_first(stack **stack_1, stack **stack_2);
void push_second(stack **stack_1, stack **stack_2);
void push(stack **stack_1, stack **stack_2, int is_update_index, char *name_instruction);
void pa(stack **stack_a, stack **stack_b, int is_update_index);
void pb(stack **stack_a, stack **stack_b, int is_update_index);
// ft_rotate.c
void rotate(stack **the_stack, char *name_instruction);
void ra(stack **stack_a);
void rb(stack **stack_b);
void rr(stack **stack_a, stack **stack_b);
// ft_reverse_rotate.c
void reverse_rotate(stack **the_stack, char *name_instruction);
void rra(stack **stack_a);
void rrb(stack **stack_b);
void rrr(stack **stack_a, stack **stack_b);

// FONCTIONS DE CALCULS DE COUTS ET D'EXECUTION
// ft_cost.c
int ft_cost(stack *stack_a, stack *stack_b, node *node_a, node *node_b);
int ft_cost_index(stack *stack_a, stack *stack_b, node *node_a, node *node_b);
int ft_max(int a, int b);
int ft_best_combo(int ra_up, int rb_up, int ra_down, int rb_down);
int ft_best_combo_index(int ra_up, int rb_up, int ra_down, int rb_down);
// ft_exec.c
void ft_main_exec(stack **stack_a, stack **stack_b, node *node_a, node *node_b);
void ft_exec_uu(stack **stack_a, stack **stack_b, int index_elem[2]);
void ft_exec_dd(stack **stack_a, stack **stack_b, int index_elem[2]);
void ft_exec_ud(stack **stack_a, stack **stack_b, int index_elem[2]);
void ft_exec_du(stack **stack_a, stack **stack_b, int index_elem[2]);
// ft_dispatcher.c
void ft_dispatch(stack **stack_a, stack **stack_b, int best_combo, int index_elem[2]);


#endif