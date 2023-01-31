#include <stdio.h>
#include <stdlib.h>
#include "congruence.h"

void print_congruence( congruence* cong )
{
    printf( "%ix ≡ %i ( mod %i )\n", cong -> a, cong -> b, cong -> m );
}

void swap( int* a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max( int a, int b )
{
    if ( a > b )
    {
        return a;
    }
    return b;
}

int min( int a, int b )
{
    if ( a < b )
    {
        return a;
    }
    return b;
}

int solve_congurence( congruence* cong )
{
    /* Using euclid algorithm */

    int c = cong -> m;
    int d = cong -> m;

    while ( cong -> a != 1 )
    {
        c %= cong -> a;
        d %= cong -> b;

        swap( &(cong -> a), &c );
        swap( &(cong -> b), &d );

        if ( cong -> a == 0 )
        {
            return -1;
        }
    }

    return cong -> b;

}

int main()
{

    congruence* cong = malloc( sizeof( congruence ) );
    cong -> a = 13;
    cong -> b = 23;
    cong -> m = 6;

    print_congruence( cong );

    solve_congurence( cong );

    print_congruence( cong );

}