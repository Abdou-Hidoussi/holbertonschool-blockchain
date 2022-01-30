#include "blockchain.h"

/**
 * blockchain_destroy - destroys a blockchain
 * @blockchain: pointer to the blockchain to be destroyed
 * Return: void
 **/
void blockchain_destroy(blockchain_t *blockchain)
{
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
