
#ifndef CYPHERS_CONGRUENCE_H
#define CYPHERS_CONGRUENCE_H

// Linear-congruence ( ax ≡ b ( mod m ) )
typedef struct congruence
{
    int a;
    int b;
    int m;
} congruence;

congruence* create_congruence( int, int, int ); // allocates new congruence ( needs to be freed afterwards )
void print_congruence( congruence* );           // prints given congruence to stdout
int solve_congurence( congruence* );            // returns value of x ( also modifies given congruence )
int inverse_modulo( int, int );                 // Returns inverse element to given number ( modulo is also given )

#endif //CYPHERS_CONGRUENCE_H
