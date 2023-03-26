#ifndef SYMETRIC_VERNAM_H
#define SYMETRIC_VERNAM_H

// Vernam cipher is cryptographically perfect cipher

char* vernam_encrypt( char* pt, char* k );  // encrypts pt with k ( result of function needs to be freed afterwards )
char* vernam_decrypt( char* ct, char* k );

#endif //SYMETRIC_VERNAM_H
