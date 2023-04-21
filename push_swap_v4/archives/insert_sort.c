/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:04:04 by edesaint          #+#    #+#             */
/*   Updated: 2023/02/09 14:04:09 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void insert_sort(int tab[], int n)
{
    int value;
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
    {
        value = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > value)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = value;
        i++;
    }
}

int main(int argc, char *argv[])
{
    int tab[9] = {3, 1, 6, 5, 4, 2, 9, 8, 7};
    int i;

    i = 0;
    insert_sort(tab, 9);
    while (i < 9)
    {
        printf("%d ", tab[i]);
        i++;
    }
    return (0);
}