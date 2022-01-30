#include "blockchain.h"
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);
uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
    sha256((int8_t const *)block, block->data.len +  sizeof(block->info), hash_buf);
    return(hash_buf);
}
