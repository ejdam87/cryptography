#ifndef SYMETRIC_CEASAR_H
#define SYMETRIC_CEASAR_H

char caesar_encrypt( char ch, int k );       // shifts character 'ch' by 'k' places
char caesar_de_encrypt( char enc, int k );   // inverse operation to encryption

void caesar_string_encrypt( char* str, char** res, char k );    // encrypts 'str' to 'res' char by char
void caesar_string_de_encrypt( char* str, char** res, char k ); // inverse to encrypytion

#endif //SYMETRIC_CEASAR_H
