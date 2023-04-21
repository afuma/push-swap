// Trie fusion video explicative de ce code
// https://www.youtube.com/watch?v=Cp0aHpwB8HU

#include <stdio.h>

void fusion(int l[], int size_l, int g[], int size_g, int d[], int size_d)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size_g && j < size_d)
    {
        if (g[i] < d[j]) {
            l[k] = g[i];
            i++;
        } else {
            l[k] = d[j];
            j++;
        }
        k++;
    }
    while (i < size_g)
    {
        l[k] = g[i];
        i++;
        k++;
    }
    while (j < size_d)
    {
        l[k] = d[j];
        j++;
        k++;
    }
}

void ft_mergesort(int l[], int size)
{
    if (size > 1)
    {
        int m = size / 2;

        int g[m], d[size-m];

        for (int i = 0; i < m; i++) {
            g[i] = l[i];
        }

        for (int i = m; i < size; i++) {
            d[i-m] = l[i];
        }
        tri_fusion(g, m);
        tri_fusion(d, size-m);
        fusion(l, size, g, m, d, size-m);
    }
}

int main()
{
    int l[] = {1, 4, 3, 5, 2, 9, 8, 3};
    int size = sizeof(l) / sizeof(l[0]);

    tri_fusion(l, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");

    return 0;
}
