
ROUNDS = { 16: 10, 24: 12, 32: 14 } ## length of the key -> number of encryption rounds

Byte = int

def create_aes_matrix( data: bytes ) -> list[ list[ Byte ] ]:
    res = [ [ 0 for _ in range( 4 ) ] for _ in range( 4 ) ]
    i = 0
    for col in range( 4 ):  ## AES uses column-major order
        for row in range( 4 ):
            res[ row ][ col ] = data[ i ]
            i += 1

    return res

def aes_encrypt( block: bytes, key: bytes ) -> bytes:
    assert len( block ) == 16  ## AES algorithm works with 16 byte (128 bit) long blocks
    assert len( key ) in ROUNDS ## AES algorithms requires 128, 196, or 256 bits long key

    rounds = ROUNDS[ len( key ) ]
    matrix = create_aes_matrix( block )
    print( matrix )

    ## TODO: Key schedule



## SHOWCASE

key = bytes.fromhex( 16 * "00" )
data = bytes.fromhex( 16 * "ff" )

aes_encrypt( data, key )
