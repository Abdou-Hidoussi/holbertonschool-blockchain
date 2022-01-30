#include "blockchain.h"
#include <stdlib.h>
#include <string.h>
/**
* init_genesis_block - Creates a genesis block
* @difficulty: Difficulty of the genesis block
*  Return: Pointer to the genesis block
*/
blockchain_t *blockchain_create(void)
{
	block_t *block;
	blockchain_t *blockchain;

	/* The Block */

	block = malloc(sizeof(block_t));
	if (!block)
		return (NULL);
	block->info.index = 0;
	block->info.difficulty = 0;
	block->info.timestamp = 1537578000;
	block->info.nonce = 0;
	memset(block->info.prev_hash, 0, SHA256_DIGEST_LENGTH);

	memcpy(block->data.buffer, "Holberton School", strlen("Holberton School"));
	block->data.len = strlen("Holberton School");

	memcpy(block->hash,
	"\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03",
	SHA256_DIGEST_LENGTH);

	/* The Chain */

	blockchain = malloc(sizeof(blockchain_t));
	if (!blockchain)
		return (NULL);
	blockchain->chain = llist_create(MT_SUPPORT_TRUE);
	if (!blockchain->chain)
		return (NULL);
	llist_add_node(blockchain->chain, block, ADD_NODE_FRONT);

	return (blockchain);
}
