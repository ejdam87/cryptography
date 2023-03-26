#include "vernam.h"
#include <stdlib.h>
#include <string.h>

char* vernam_encrypt( char* pt, char* k )
{
    if ( strlen( pt ) != strlen( k ) )
    {
        return NULL;
    }

    char *res = malloc( strlen( pt ) * sizeof( char ) );
    for ( int i = 0; i < strlen( pt ); i++ )
    {
        res[ i ] = pt[ i ] ^ k[ i ];
    }

    return res;
}

char* vernam_decrypt( char* ct, char* k )
{
    return vernam_encrypt( ct, k );
}
