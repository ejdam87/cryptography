#include <stdio.h>
#include <stdlib.h>
#include "congruence.h"

void print_congruence( congruence* cong )
{
    printf( "%ix ≡ %i ( mod %i )", cong -> a, cong -> b, cong -> m );
}

int main()
{

    congruence* cong = malloc( sizeof( congruence ) );
    cong -> a = 5;
    cong -> b = 4;
    cong -> m = 6;

    print_congruence( cong );

}