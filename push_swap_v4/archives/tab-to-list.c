
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "push_swap.h"

// void fusion (int *a, int n, int m)
// {
//     int i;
//     int j;
//     int k;
//     int *liste;
    
//     liste = (int *) malloc(n * sizeof (int));
//     i = 0;
//     j = m;
//     k = 0;
//     while(k < n)
//     {
//         if (j == n)
//             liste[k] = a[i++];
//         else if (i == m)
//             liste[k] = a[j++];
//         else if(a[j] < a[i])
//             liste[k] = a[j++];
//         else
//             liste[k] = a[i++];
//         k++;
//     }
//     i = 0;
//     while(i < n) 
//     {
//         a[i] = liste[i];
//         i++;
//     }
//     free(liste);
// }

void ft_stock_values_from_tab(t_list_2 *lst, int *tab, int taille)
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

// t_list *ft_stock_values(t_list liste, int taille)
// {

// }

// void tri_fusion (t_list liste, int taille)
// {
//     int milieu = taille / 2;
//     t_list *liste_divided;

//     liste_divided = (t_list *) malloc(sizeof(t_list));
//     liste_divided.value = ft_stock_values(liste);
//     if (taille < 2)
//         return;
//     tri_fusion(liste, milieu);
//     tri_fusion(liste_divided, taille - milieu);
//     fusion(liste, taille, milieu);
// }

int main(int argc, char *argv[])
{
    int tab[9] = {3, 1, 6, 5, 4, 2, 9, 8, 7};
    t_list_2 *lst;
    // int i;

    // i = 0;
    lst = NULL;
    printf("1\n");
    ft_stock_values_from_tab(lst, tab, 9);
    //ft_lstprint(lst);
    free_stash_2(&lst, 1);
    // merge_sort(tab, 0, 9);
    // while (i < 9)
    // {
    //     printf("%d ", tab[i]);
    //     i++;
    // }
    return (0);
}