#include "vigenere.h"
#include "caesar.h"

#include <string.h>

void vigenere_encrypt( char* plain, char** res, char* key )
{
    size_t key_len = strlen( key );

    for ( int i = 0; i < strlen( plain ); i++ )
    {
        (*res)[ i ] = caesar_encrypt( plain[ i ], key[ i % key_len ] );
    }
}

void vigenere_de_encrypt( char* enc, char** res, char* key )
{
    size_t key_len = strlen( key );

    for ( int i = 0; i < strlen( enc ); i++ )
    {
        (*res)[ i ] = caesar_de_encrypt( enc[ i ], key[ i % key_len ] );
    }
}
