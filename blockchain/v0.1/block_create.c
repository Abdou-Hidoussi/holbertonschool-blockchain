#include "blockchain.h"
/**
 * block_create - creates a new block
 * @prev: pointer to the previous block
 * @data: data to be stored in the block
 * @data_l: length of the data
 * Return: On success pointer to the new block
 * On error, return NULL
 **/
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_l)
{
	uint32_t length;
	block_t *block;

	block = calloc(1, sizeof(block_t));

	block->info.index = prev->info.index + 1;
	block->info.difficulty = 0;
	block->info.timestamp = time(NULL);
	block->info.nonce = 0;
	memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);

	if (data_l <= BLOCKCHAIN_DATA_MAX)
		length = data_l;
	else
	{
		length = BLOCKCHAIN_DATA_MAX;
	}
	memcpy(block->data.buffer, data, length);
	block->data.len = length;

	memset(block->hash, 0, SHA256_DIGEST_LENGTH);
	return (block);
}
