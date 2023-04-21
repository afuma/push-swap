/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:19:06 by edesaint          #+#    #+#             */
/*   Updated: 2023/04/12 14:26:52 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -------- Remplacer printf par ft_printf ----------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //pour le INT_MAX et INT_MIN
// a voir pour enlever les includes ci dessus car deja present dans la libft

#include "./libft/libft.h"

void ft_error()
{
    printf("Error\n");
    exit(EXIT_SUCCESS);
}

void ft_error_tab(int *tab)
{
    free(tab);
    ft_error();
}

int is_doublon(int *tab, int last_index)
{
    int i;
    int last_value;
    
    i = last_index;
    last_value = tab[i];
    i--;
    while (i >= 0)
    {
        if (tab[i] == last_value)
            return (1);
        i--;
    }
    return (0);
}

int is_valid_number(char *argv)
{
    long int nb;
    int index;
    int i;

    index = 0;
    i = 0;
    if (argv[0] == '-' || argv[0] == '+')
        i++;
    while(argv[i] && argv[i] == '0')
        i++;
    index = i;
    while (argv[i])
    {
        if(i > 10 + index || !ft_isdigit(argv[i]))
            return (0);
        i++;
    }
    nb = ft_atol(argv);
    if (nb > INT_MAX || nb < INT_MIN)
        return (0);

    return (1);
}
// methode 1: on ajoute les nombres dans un tableau et on les compare directement entre eux
void ft_parse(int argc, char *argv[])
{
    int i;
    int *tab;

    tab = (int *) malloc(sizeof(int) * (argc - 1));
    if (!tab)
        ft_error();
    if (argc < 2)
        ft_error_tab(tab);
    i = 1;
    while (i <= argc - 1)
    {
        if(!is_valid_number(argv[i]))
            ft_error_tab(tab);
        else
        {
            tab[i - 1] = ft_atoi(argv[i]);
            if (is_doublon(tab, i - 1))
                ft_error_tab(tab);
        }
        i++;
    }
    free(tab);
}

// // methode 2: creer un tableau et le remplir avec les valeurs puis verifier que y a pas de doublons (double boucle)
// void ft_parse(int argc, char *argv[])
// {
//     int i;
//     int *tab;

//     tab = (int *) malloc(sizeof(int) * (argc - 1));
//     if (!tab)
//         ft_error();
//     if (argc < 2)
//         ft_error();
//     i = 1;
//     while (i <= argc - 1)
//     {
//         if(!is_valid_number(argv[i]))
//         {
//             free(tab);
//             ft_error();
//         }
//         else
//             tab[i - 1] = ft_atoi(argv[i]);
//         i++;
//     }
//     // int j = 0;
//     // while (j < i - 1)
//     // {
//     //     printf("%d ", tab[j]);
//     //     j++;
//     // }
//     // printf("\n");
//     // fonction de doublons
// }