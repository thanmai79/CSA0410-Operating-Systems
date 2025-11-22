 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a block
struct Block {
    int blockNumber;
    char data[256];
};

int main() {
    FILE *file;
    struct Block block;
    int blockNumber;

    // Index block: stores file offsets of blocks
    long indexBlock[100];
    for (int i = 0; i < 100; i++)
        indexBlock[i] = -1;   // -1 means no block exists

    // Open file for writing (binary mode)
    file = fopen("indexed_file.txt", "wb");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    printf("Enter blocks (Enter 0 as block number to stop writing):\n");

    while (1) {
        printf("Block Number: ");
        scanf("%d", &block.blockNumber);

        if (block.blockNumber == 0)
            break;

        printf("Data: ");
        scanf(" %[^\n]", block.data);

        // Record file position before writing
        long position = ftell(file);

        fwrite(&block, sizeof(struct Block), 1, file);

        // Save pointer in index block
        indexBlock[block.blockNumber] = position;
    }

    fclose(file);

    // Open file for reading
    file = fopen("indexed_file.txt", "rb");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    while (1) {
        printf("\nEnter block number to read (0 to exit): ");
        scanf("%d", &blockNumber);

        if (blockNumber == 0)
            break;

        if (blockNumber < 0 || blockNumber >= 100 || indexBlock[blockNumber] == -1) {
            printf("Block not found.\n");
        } else {
            // Move to the correct block location
            fseek(file, indexBlock[blockNumber], SEEK_SET);
            fread(&block, sizeof(struct Block), 1, file);

            printf("Block Number: %d\n", block.blockNumber);
            printf("Data: %s\n", block.data);
        }
    }

    fclose(file);
    return 0;
}
