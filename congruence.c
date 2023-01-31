#include <stdio.h>
#include <stdlib.h>
#include "congruence.h"

congruence* create_congruence( int a, int b, int m )
{
    congruence* res = malloc( sizeof( congruence ) );
    res -> a = a;
    res -> b = b;
    res -> m = m;
    return res;
}

int positive_modulo( int a, int m )
{
    int res = a % m;
    if ( res < 0 )
    {
        return res + m;
    }
    return m;
}

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

int solve_congurence( congruence* cong )
{
    /* Using euclid algorithm */

    int c = cong -> m;
    int d = cong -> m;

    int times;
    while ( cong -> a != 1 )
    {
        times = c / cong -> a;
        c -= times * ( cong -> a );
        d -= times * ( cong -> b );

        swap( &(cong -> a), &c );
        swap( &(cong -> b), &d );

        if ( cong -> a == 0 )
        {
            return -1;
        }
    }

    cong -> a = positive_modulo( cong -> a, cong -> m );
    cong -> b = positive_modulo( cong -> b, cong -> m );
    return cong -> b;

}


int inverse_modulo( int x, int m )
{
    congruence* cong = create_congruence( x, 1, m );
    int res = solve_congurence( cong );
    free( cong );
    return res;
}


int main()
{

    printf( "%i", inverse_modulo(13, 6) );

}