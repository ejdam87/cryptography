
#ifndef CYPHERS_RSA_H
#define CYPHERS_RSA_H

/*
 * e - exponent
 * d - inverse number to e ( modulo m )
 * m - modulo ( m = p * q ); p, q - prime factors of m
 *
 * encryption of M    -> C = M ^ e ( mod m )
 * de-encryption of C -> M = C ^ d ( mod m )
*/

typedef struct public_key
{
    unsigned exponent;
    int modulo;
} public_key;

typedef struct private_key
{
    // modulo = p * q
    unsigned inverse_exponent;
    int p;
    int q;
} private_key;

int encrypt( int, public_key* );
int de_encrypt( int, private_key* );

#endif
