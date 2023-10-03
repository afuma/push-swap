/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:17:17 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/05 22:49:30 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

//FONCTIONS POUR LES BONUS

//static int	ft_execute_program(t_stack *stack_a, t_stack *stack_b);
//static int	ft_execute_cmd(t_stack *stack_a, t_stack *stack_b, char *cmd);
//static int	ft_is_cmd_exist(char *cmd);

// FONCTIONS DE LA LIBFT
// libft.c
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
void		ft_free(void **ptr);
int			ft_max(int a, int b);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// FONCTIONS DU MAIN
int			main(int argc, char *argv[]);
bool		ft_is_sorted(t_stack *stack);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);

// FONCTIONS DE BASES POUR MANIPULER LES LISTES CHAINEES
// ft_utils.c
t_stack		*ft_new_node(int nbr);
void		ft_addfront(t_stack **stack, t_stack *node);
t_stack		*ft_last(t_stack *stack);
void		ft_addback(t_stack **stack, t_stack *node);
void		ft_stackclear(t_stack **stack);

// ft_utils2.c
t_stack		*ft_find_min(t_stack *stack);
t_stack		*ft_find_max(t_stack *stack);
void		ft_make_order(t_stack **stack);
bool		ft_is_completed_sorted(t_stack *stack_a);

// FONCTIONS DE PARSING
// ft_parse.c
void		ft_error(void);
void		ft_error_tab(int *tab);
int			ft_is_duplicate(int *tab, int last_index);
int			is_valid_number(char *argv);
void		ft_parse(int argc, char *argv[]);

// ft_init.c
void		ft_args_to_list(t_stack **stack_a, int argc, char *argv[]);
void		ft_set_index(t_stack *stack);

// FONCTIONS DU SUJET
// ft_moves.c
void		ft_swap(t_stack **stack);
void		ft_rotate(t_stack **stack);
void		ft_r_rotate(t_stack **stack);
void		ft_push(t_stack **stack_src, t_stack **stack_dst);

// FONCTIONS DE CALCULS DE COUTS ET D'EXECUTION
// ft_cost.c
int			ft_cost(t_stack *stack_a, t_stack *stack_b, int ind_a, int ind_b);
int			ft_cost_index(t_stack *stack_a, t_stack *stack_b, \
							int ind_a, int ind_b);
int			ft_max(int a, int b);
int			ft_best_combo(int ra_up, int rb_up, int ra_down, int rb_down);
int			ft_best_combo_index(int ra_up, int rb_up, int ra_down, int rb_down);

// ft_exec.c
t_stack		*ft_suiv_a(t_stack *stack_a, t_stack *node_b);
t_stack		*ft_find_best_elem(t_stack *stack_a, t_stack *stack_b);
void		ft_make_best_combo(t_stack **stack_a, t_stack **stack_b);

//ft_exec_func.c
void		ft_exec_uu(t_stack **stack_a, t_stack **stack_b, \
							int ind_a, int ind_b);
void		ft_exec_dd(t_stack **stack_a, t_stack **stack_b, \
							int ind_a, int ind_b);
void		ft_exec_ud(t_stack **stack_a, t_stack **stack_b, \
							int ind_a, int ind_b);
void		ft_exec_du(t_stack **stack_a, t_stack **stack_b, \
							int ind_a, int ind_b);
void		ft_add_exex_dd(t_stack **stack, int ind, \
								int size_stack, char *inst);

#endif
