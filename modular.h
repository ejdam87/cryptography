
#ifndef CIPHER_CONGRUENCE_H
#define CIPHER_CONGRUENCE_H

#include <stdbool.h>

// Linear-congruence ( ax ≡ b ( mod m ) )
typedef struct congruence
{
    int a;
    int b;
    int m;
} congruence;

congruence* create_congruence( int, int, int );     // allocates new congruence ( needs to be freed afterwards )
void set_congruence( congruence*, int, int, int );  // self-explanatory
void print_congruence( congruence* );               // prints given congruence to stdout
int solve_congurence( congruence* );                // returns value of x ( also modifies given congruence )
int solve_system( congruence*, congruence* );       // returns solution of system of 2 congruences ( also modifes them )

int gcd( int, int );                                // greatest common divisor
bool are_indisputable( int, int );                  // self-explanatory
int inverse_modulo( int, int );                     // Returns inverse element to given number ( modulo is also given )
unsigned phi( unsigned );                           // computes euler totient function

#endif
