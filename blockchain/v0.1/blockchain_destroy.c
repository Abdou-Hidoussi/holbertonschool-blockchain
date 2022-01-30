#include "blockchain.h"

void blockchain_destroy(blockchain_t *blockchain)
{
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
