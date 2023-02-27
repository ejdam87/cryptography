
#ifndef CIPHER_RABIN_H
#define CIPHER_RABIN_H

#include <stdlib.h>


/*
 * encryption of M    -> M ^ 2 ( mod m )
 * de-encryption of C -> sqrt( M ) ( mod m ) ( more solutions ... need to agree on which is valid )
 * */

typedef struct public_key
{
    int modulo;
} public_key;

typedef struct private_key
{
    // m = p * q
    int p;
    int q;
} private_key;

int encrypt( int, public_key* );
int de_encrypt( int, private_key* );

#endif
