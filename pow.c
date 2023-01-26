#include "pow.h"

int binpow_iter( int num, unsigned int exp )
{
    int res = 1;

    while ( exp > 0 )
    {
        if ( exp % 2 == 1 )
        {
            res *= num;
        }

        num = num * num;
        exp /= 2;
    }

    return res;
}

int binpow_rec( int num, unsigned int exp )
{
    int subres;
    if ( exp == 0 )
    {
        return 1;
    }

    else if ( exp % 2 == 0 )
    {
        exp /= 2;
        subres = binpow_rec( num, exp );
        return subres * subres;
    }

    else if ( exp % 2 == 1 )
    {
        exp = ( exp - 1 ) / 2;
        subres = binpow_rec( num, exp );
        return num * subres * subres;
    }

    // Unreachable
    return -1;
}

int modpow( int num, unsigned int exp, int mod )
{
    int res = 1;
    num %= mod;

    while ( exp > 0 )
    {
        if ( exp % 2 == 1 )
        {
            res *= num;
            res %= mod;
        }

        num = num * num;
        num %= mod;
        exp /= 2;
    }

    return res;
}
