#include <stdio.h>

int main() {
    int blockCount, processCount;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    int blockSize[blockCount], blockAllocated[blockCount];

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < blockCount; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // initially free
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    int processSize[processCount], allocation[processCount];

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < processCount; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;   // initially not allocated
    }

    // First Fit Allocation
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];  // reduce block size
                break;  // stop after finding first suitable block
            }
        }
    }

    // Output result
    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
