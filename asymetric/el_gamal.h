
#ifndef CIPHER_EL_GAMAL_H
#define CIPHER_EL_GAMAL_H

/*
 * participants exchange their ( parital ) keys ( diffie-helmann ) --> g^a
 *
 * encryption of M    -> g^(ab) * M ( mod m )
 * de-encryption of C -> solving congruence above
 * */
typedef struct public_key
{
    unsigned g; // One specific primitive root modulo m
    int m;
} public_key;

typedef struct private_key
{
    unsigned a;
} private_key;

// Diffie-Helmann exchange
typedef struct shared_keys
{
    unsigned a;
    unsigned b;
} shared_keys;

#endif
