

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("-01: %d\n", -01); // ok
    printf("+01: %d\n", +01);
    printf("0-1: %d\n", 0-1);
    printf("0000000000000000000+1: %d\n", 0000000000000000000+1);
    printf("01: %d\n", 01);
    printf("+01: %d\n", +01);
    printf("-00: %d\n", -00);
    printf("+00: %d\n", +00);

    printf("\n\n");
    // avec atoi
    printf("-01: %d\n", atoi("-01")); // ok
    printf("+01: %d\n", atoi("+01"));
    printf("0-1: %d\n", atoi("0-1"));
    printf("0000000000000000000+1: %d\n", atoi("0000000000000000000+1"));
    printf("01: %d\n", atoi("01"));
    printf("+01: %d\n", atoi("+01"));
    printf("-00: %d\n", atoi("-00"));
    printf("+00: %d\n", atoi("+00"));

    int i;
    printf("\n\n");
    i = -01;
    printf("-01: %i\n", i); // ok
    i = +01;
    printf("+01: %i\n", i);
    i = 0-1;
    printf("0-1: %i\n", i);
    i = 0000000000000000000+1;
    printf("0000000000000000000+1: %i\n", i);
    i = 01;
    printf("01: %i\n",i);
    i = +01;
    printf("+01: %i\n", i);
    i = -00;
    printf("-00: %i\n",i);
    i = +00;
    printf("+00: %i\n", i);


    return (0);
}