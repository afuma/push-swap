/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:20:24 by edesaint          #+#    #+#             */
/*   Updated: 2023/03/01 22:04:30 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "push_swap.h"

void ft_tabtolist(t_list_2 *lst, int *tab, int taille)
{
    int i;

    i = 0;
    printf("taille: %d", taille);
    while (i < taille)
    {
        printf("tab[%d]: %d\n", i, tab[i]);
        ft_lstadd_back_2(&lst, ft_lstnew_2(&tab[i]));
        printf("lst bloc [%d]: %d\n", i, *(lst->content + i));
        i++;
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int tab[9] = {3, 1, 6, 5, 4, 2, 9, 8, 7};
    t_list_2 *lst;

    lst = NULL;
    printf("1\n");
    ft_tabtolist(lst, tab, 9);
    free_stash_2(&lst, 1);

    return (0);
}