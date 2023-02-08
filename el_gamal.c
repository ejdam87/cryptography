#include "el_gamal.h"
#include "pow.h"
#include "modular.h"
#include <stdlib.h>

int encrypt( int msg,
             public_key* pk,
             private_key* my_priv_key,
             shared_keys* sk )
{
    unsigned gb = sk -> b;
    int common = modpow( (int) gb, my_priv_key -> a, pk -> m );
    return ( msg * common ) % pk -> m;
}

int de_encrypt( int enc,
                public_key* pk,
                private_key* my_priv_key,
                shared_keys* sk )
{

    unsigned gb = sk -> a;
    int common = modpow( (int) gb, my_priv_key -> a, pk -> m );
    congruence* cong = create_congruence( common, enc, pk -> m );
    int res = solve_congurence( cong );
    free( cong );
    return res;

}
