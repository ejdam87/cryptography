
#ifndef CYPHERS_CONGRUENCE_H
#define CYPHERS_CONGRUENCE_H

// Linear-congruence ( ax ≡ b ( mod m ) )
typedef struct congruence
{
    int a;
    int b;
    int m;
} congruence;

void print_congruence( congruence* );
int solve_congurence( congruence* );

#endif //CYPHERS_CONGRUENCE_H
