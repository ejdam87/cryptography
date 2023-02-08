
#ifndef CIPHER_EL_GAMAL_H
#define CIPHER_EL_GAMAL_H

typedef struct public_key
{
    unsigned g;
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
