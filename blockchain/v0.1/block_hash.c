#include "blockchain.h"
/**
 * sha256 - a function that computes the hash of a sequence of bytes.
 * @s: Sequence of bytes to be hashed
 * @len: Bytes to hash
 * @digest: array to store resulting hash in
 *
 * Return: pointer to digest, NULL on error
 */
uint8_t *sha256(int8_t const *s, size_t len,
				uint8_t digest[SHA256_DIGEST_LENGTH]);
/**
 * block_hash - hashes a block
 * @block: pointer to the block to be hashed
 * @hash_buf: pointer to the buffer where the hash will be stored
 * Return: pointer to the hash_buf
 **/
uint8_t *block_hash(block_t const *block,
					uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	sha256((int8_t const *)block,
			block->data.len +  sizeof(block->info), hash_buf);
	return (hash_buf);
}
