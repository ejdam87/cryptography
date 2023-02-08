#include "rsa.h"
#include "pow.h"

int encrypt( int msg, public_key* pk )
{
    return modpow( msg, pk -> exponent, pk -> modulo );
}

int de_encrypt( int enc, private_key* pk )
{
    return modpow( enc, pk -> inverse_exponent, pk -> p * pk -> q );
}
