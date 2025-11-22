 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each block
struct Block {
    char data[256];
    struct Block* next;
};

int main() {
    struct Block* firstBlock = NULL;
    struct Block* lastBlock = NULL;

    int blockCount = 0;
    int blockNumber;
    char data[256];
    char choice;

    printf("Linked Allocation Simulation\n");

    while (1) {
        printf("\nEnter 'W' to Write, 'R' to Read, 'Q' to Quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q')
            break;

        // -------------------- WRITE BLOCK --------------------
        if (choice == 'W' || choice == 'w') {
            printf("Enter data for the block: ");
            scanf(" %[^\n]", data);

            struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));

            strcpy(newBlock->data, data);
            newBlock->next = NULL;

            if (blockCount == 0) {
                firstBlock = newBlock;
                lastBlock = newBlock;
            } else {
                lastBlock->next = newBlock;
                lastBlock = newBlock;
            }

            blockCount++;
            printf("Block %d written successfully.\n", blockCount);
        }

        // -------------------- READ BLOCK --------------------
        else if (choice == 'R' || choice == 'r') {

            if (blockCount == 0) {
                printf("No blocks available to read.\n");
                continue;
            }

            printf("Enter block number to read (1-%d): ", blockCount);
            scanf("%d", &blockNumber);

            if (blockNumber < 1 || blockNumber > blockCount) {
                printf("Invalid block number.\n");
            } else {
                struct Block* currentBlock = firstBlock;

                for (int i = 1; i < blockNumber; i++) {
                    currentBlock = currentBlock->next;
                }

                printf("Block %d Data: %s\n", blockNumber, currentBlock->data);
            }
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    // -------- FREE ALLOCATED MEMORY BEFORE EXITING --------
    struct Block* temp = firstBlock;
    while (temp != NULL) {
        struct Block* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
