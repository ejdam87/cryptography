#include <stdio.h>
#include <stdlib.h>
#include "modular.h"

#define NO_SOLUTION -1
#define INVALID_INPUT -2

congruence* create_congruence( int a, int b, int m )
{
    congruence* res = malloc( sizeof( congruence ) );
    res -> a = a;
    res -> b = b;
    res -> m = m;
    return res;
}

void set_congruence( congruence* cong, int a, int b, int m )
{
    cong -> a = a;
    cong -> b = b;
    cong -> m = m;
}

int positive_modulo( int a, int m )
{
    int res = a % m;
    if ( res < 0 )
    {
        return res + m;
    }
    return a;
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

    cong -> a = positive_modulo( cong -> a, cong -> m );
    cong -> b = positive_modulo( cong -> b, cong -> m );
    int c = cong -> m;
    int d = cong -> m;

    int times;
    while ( cong -> a != 0 )
    {
        times = c / cong -> a;
        c -= times * ( cong -> a );
        d -= times * ( cong -> b );

        swap( &(cong -> a), &c );
        swap( &(cong -> b), &d );

    }

    if ( cong -> b % cong -> m != 0 )
    {
        return NO_SOLUTION;
    }

    swap( &(cong -> a), &c );
    swap( &(cong -> b), &d );

    int e = gcd( cong -> a, cong -> b );
    int f = gcd( e, cong -> m );

    if ( f != 1 )
    {
        cong -> a /= f;
        cong -> b /= f;
        cong -> m /= f;
    }
    else
    {
        cong -> a /= e;
        cong -> b /= f;
    }

    cong -> a = positive_modulo( cong -> a, cong -> m );
    cong -> b = positive_modulo( cong -> b, cong -> m );
    return cong -> b;

}

int solve_system( congruence* cong_1, congruence* cong_2 )
{
    solve_congurence( cong_1 );
    solve_congurence( cong_2 );

    cong_2 -> a = cong_1 -> m;
    cong_2 -> b -= cong_1 -> b;

    solve_congurence( cong_2 );

    int modulo = cong_1 -> m * cong_2 -> m;
    return positive_modulo( cong_2 -> b * cong_1 -> m + cong_1 -> b, modulo );

}

int inverse_modulo( int x, int m )
{
    congruence* cong = create_congruence( x, 1, m );
    int res = solve_congurence( cong );
    free( cong );
    return res;
}

int gcd( int a, int b )
{
    if ( b == 0 )
    {
        return a;
    }
    return gcd( b, a % b );
}

bool are_indisputable( int a, int b )
{
    return gcd( a, b ) > 1;
}

unsigned phi( unsigned n )
{
    unsigned res = 0;

    for ( int i = 1; i < n; i++ )
    {
        if ( are_indisputable( (int) n, i ) )
        {
            res++;
        }
    }

    return res;
}
