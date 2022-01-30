#include "blockchain.h"
/**
 * _get_endianness - Get current endianness
 *
 * Return: 1 for little endian, 2 for big endian, 0 for unknown
 */
uint8_t	_get_endianness(void);

/**
 * blockchain_serialize - serializes a blockchain
 * @blockchain: pointer to the blockchain to be serialized
 * @path: path to the file to be created
 * if the file already exists, it will be overwritten
 * Return: 0 on success, -1 on failure
 **/
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	header_file_t header;
	block_t *block;
	FILE *fp;
	int i;

	memcpy(header.hblk_magic, "HBLK", 4);
	memcpy(header.hblk_version, "0.1", 3);
	header.hblk_endian = _get_endianness();
	header.hblk_blocks = llist_size(blockchain->chain);

	fp = fopen(path, "wb");
	fwrite(&header, sizeof(header), 1, fp);
	for (i = 0; i < llist_size(blockchain->chain); i++)
	{
		block = llist_get_node_at(blockchain->chain, i);

		fwrite((void *)&block->info, sizeof(block->info), 1, fp);
		fwrite((void *)&block->data.len, sizeof(block->data.len), 1, fp);
		fwrite((void *)block->data.buffer, block->data.len + 1, 1, fp);
		fwrite((void *)block->hash, SHA256_DIGEST_LENGTH, 1, fp);
	}

	fclose(fp);
	return (1);

}
