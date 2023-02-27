#include "ceasar.h"
#include "alphabet.h"


char caesar_encrypt( char ch, int k )
{
    char pos = ch - 'a'; // number from 0 to 25
    char shifted = ( pos + k ) % ALPHABET_LENGTH;
    return shifted + 'a';

}

char caesar_de_encrypt( char enc, int k )
{
    char pos = enc - 'a';
    char shifted = ( pos - k ) % ALPHABET_LENGTH;
    if ( shifted < 0 )
    {
        shifted += ALPHABET_LENGTH;
    }
    return shifted + 'a';
}

void caesar_string_encrypt( char* str, char k )
{

}
