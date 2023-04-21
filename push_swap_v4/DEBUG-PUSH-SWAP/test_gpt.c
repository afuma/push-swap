
// chatGPT debug ft_init_stack. 
// l'Objectif est d'initialiser la stack en modifiant la stack directement

// la reponse est parfaite !

prompt:
//------------------------------------------------------------------------------------------------------
voici mon code: "
# include <stdio.h>

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
	struct node *begin;
	struct node *end;
}	stack;

int main(int argc, char *argv[])
{
    stack *stack_a;
    stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    ft_init_stack(stack_a, stack_b);
    printf("2-stack_a: %p", stack_a);
    
    return (0);
}
void ft_init_stack(stack *stack_a, stack *stack_b)
{
    stack_a = (stack *) malloc(sizeof(stack));
    stack_b = (stack *) malloc(sizeof(stack));
    stack_a->begin = NULL;
    stack_a->end = NULL;
    stack_b->begin = NULL;
    stack_b->end = NULL;

    printf("1-stack_a: %p\n", stack_a);
    printf("stack_b: %p\n", stack_b);
    printf("stack_a->begin: %p\n", stack_a->begin);
    
}" explique moi pourquoi le printf avec le label "1-stack_a" et l'autre printf avec le label "2-stack_a" n'ont pas la meme valeur ?
//------------------------------------------------------------------------------------------------------------






reponse:
//------------------------------------------------------------------------------------------------------------
Dans votre code, vous passez les adresses de stack_a et stack_b à la fonction ft_init_stack. 
Cependant, à l'intérieur de cette fonction, vous modifiez les valeurs de ces adresses locales plutôt que les valeurs des pointeurs passés en argument.
 Cela signifie que lorsque vous essayez d'afficher les valeurs de stack_a dans main, la valeur n'a pas été modifiée car la modification a été effectuée sur une copie locale de la variable.

Pour corriger cela, vous devez passer les pointeurs en tant que pointeurs de pointeurs. 
Cela signifie que vous passerez l'adresse de la variable pointeur dans la fonction, et la fonction mettra à jour 
l'adresse de la variable pointeur elle-même, plutôt que de simplement mettre à jour la valeur pointée.

Voici comment vous pouvez modifier votre code pour résoudre ce problème :

arduino
Copy code
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int content;
    int index;
    struct node *next;
    struct node *prev;
} node;

typedef struct stack
{
    int index_max;
    struct node *begin;
    struct node *end;
} stack;

void ft_init_stack(stack **stack_a, stack **stack_b)
{
    *stack_a = (stack *) malloc(sizeof(stack));
    *stack_b = (stack *) malloc(sizeof(stack));
    (*stack_a)->begin = NULL;
    (*stack_a)->end = NULL;
    (*stack_b)->begin = NULL;
    (*stack_b)->end = NULL;

    printf("1-stack_a: %p\n", *stack_a);
    printf("stack_b: %p\n", *stack_b);
    printf("(*stack_a)->begin: %p\n", (*stack_a)->begin);
}

int main(int argc, char *argv[])
{
    stack *stack_a;
    stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    ft_init_stack(&stack_a, &stack_b);
    printf("2-stack_a: %p", stack_a);
    
    return (0);
}
Maintenant, vous passez les adresses de stack_a et stack_b à la fonction ft_init_stack en tant que pointeurs de pointeurs. 
Dans la fonction, vous modifiez la valeur des pointeurs de pointeurs en utilisant l'opérateur d'indirection *, 
de sorte que la valeur des pointeurs pointés est modifiée directement. En conséquence, lorsque vous affichez la valeur de stack_a dans main, la valeur mise à jour est affichée.
//------------------------------------------------------------------------------------------------------------