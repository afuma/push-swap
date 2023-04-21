
// #include <stdio.h>

// void main(void)
// {
//     int mediane;

//     mediane = 5/2;
//     printf("%d", mediane);
// }

on a 3 elements, si le prev est plus grand pour 3 element cest bonm sinon on swap

trier en 1 operation

prev de lelement a gauche -> dernier element
next -> a droite
Objectif final pour le trie a trois elements: 1 2 3

1 2 3 -> ok
1 3 2 -> sa -> 3 1 2 -> ra
2 1 3 -> sa -> 1 2 3
2 3 1 -> rra
3 1 2 -> ra
3 2 1 -> sa -> 2 3 1 -> rra

Objectif final petit trie: 1 2 3 ou 2 3 1 ou 3 1 2
une operation max
1 2 3 -> ok
1 3 2 -> sa
2 1 3 -> sa
2 3 1 -> ok
3 1 2 -> ok
3 2 1 -> sa

int i;
node *node_tmp;

node_tmp = first_elem;
i = 0;
while (i < 2)
{
    if (node_tmp->next->content < node_tmp->content)
        sa();
    i++;
    node_tmp = node_tmp->next;
}

// fonction de trie de 3 elements
meilleur des cas -> deja trier rien a faire
pire des cas: ra ou rra, puis swap