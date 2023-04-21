/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:04:13 by edesaint          #+#    #+#             */
/*   Updated: 2023/02/28 18:53:41 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int tab[], int deb, int n)
{
    int tmp;
    
    if (n == 1)
    {
        if (tab[0] > tab[1])
        {
            tmp = tab[0];
            tab[0] = tab[1];
            tab[1] = tmp;
        }
    }
    while (n != 1)
    {
        printf("%d", n);
        merge_sort(tab, 0, n / 2);
        merge_sort(tab, (n / 2) + 1, n);
    }
}

int main(int argc, char *argv[])
{
    printf("bonjour");
    int tab[9] = {3, 1, 6, 5, 4, 2, 9, 8, 7};
    int i;

    i = 0;
    printf("bonjour");
    merge_sort(tab, 0, 9);
    while (i < 9)
    {
        printf("%d ", tab[i]);
        i++;
    }
    return (0);
}