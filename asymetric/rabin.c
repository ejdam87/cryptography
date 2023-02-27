#include "rabin.h"
#include "pow.h"
#include "modular.h"

#define INVALID_MODULO -1

int encrypt( int msg, public_key* pk )
{
    return modpow( msg, 2, pk -> modulo );
}

// Assuming that enc was encrypted with valid modulo
// we also assume that the correct solution is positive
int de_encrypt( int enc, private_key* pk )
{

    if ( pk -> p % 4 != 3 || pk -> q % 4 != 3 )
    {
        return INVALID_MODULO;
    }

    int sqrt_1 = modpow( enc, ( pk -> p + 1 ) / 4, pk -> p );
    int sqrt_2 = -sqrt_1;
    int sqrt_3 = modpow( enc, ( pk -> q + 1 ) / 4, pk -> q );
    int sqrt_4 = -sqrt_3;

    int pos1, pos2;
    int neg1, neg2;

    if ( sqrt_1 > sqrt_2 )
    {
        pos1 = sqrt_1;
        neg1 = sqrt_2;
    }
    else
    {
        pos1 = sqrt_2;
        neg1 = sqrt_1;
    }

    if ( sqrt_3 > sqrt_4 )
    {
        pos2 = sqrt_3;
        neg2 = sqrt_4;
    }
    else
    {
        pos2 = sqrt_4;
        neg2 = sqrt_3;
    }

    congruence* cong_1 = malloc( sizeof( congruence ) );
    set_congruence( cong_1, 1, pos1, pk -> p );

    congruence* cong_2 = malloc( sizeof( congruence ) );
    set_congruence( cong_2, 1, pos2, pk -> q );

    int fst = solve_system( cong_1, cong_2 );

    set_congruence( cong_1, 1, neg1, pk -> p );
    set_congruence( cong_2, 1, neg2, pk -> q );

    int snd = solve_system( cong_1, cong_2 );

    set_congruence( cong_1, 1, neg1, pk -> p );
    set_congruence( cong_2, 1, pos2, pk -> q );

    int thd = solve_system( cong_1, cong_2 );

    set_congruence( cong_1, 1, pos1, pk -> p );
    set_congruence( cong_2, 1, neg2, pk -> q );

    int fth = solve_system( cong_1, cong_2 );

    free( cong_1 );
    free( cong_2 );
    return thd;
}
