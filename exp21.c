 #include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

// Initialize memory as free
void initializeMemory() {
    for (int i = 0; i < MAX_MEMORY; i++) {
        memory[i] = -1;
    }
}

// Display all free memory blocks
void displayMemory() {
    printf("\nMemory Status:\n");

    int i = 0, j;

    while (i < MAX_MEMORY) {
        if (memory[i] == -1) {
            j = i;
            while (j < MAX_MEMORY && memory[j] == -1) {
                j++;
            }
            printf("Free memory block %d - %d\n", i, j - 1);
            i = j;
        } else {
            i++;
        }
    }
}

// Allocate memory using WORST-FIT
void allocateMemory(int processId, int size) {

    int bestStart = -1;
    int bestSize = -1;

    int i = 0;

    while (i < MAX_MEMORY) {
        if (memory[i] == -1) {

            int start = i;
            int blockSize = 0;

            while (i < MAX_MEMORY && memory[i] == -1) {
                blockSize++;
                i++;
            }

            // Choose the **largest free block**
            if (blockSize >= size && blockSize > bestSize) {
                bestStart = start;
                bestSize = blockSize;
            }

        } else {
            i++;
        }
    }

    if (bestStart != -1) {
        for (int k = bestStart; k < bestStart + size; k++) {
            memory[k] = processId;
        }

        printf("Allocated memory block %d - %d to Process %d\n",
               bestStart, bestStart + size - 1, processId);
    } else {
        printf("Allocation failed for Process %d (no suitable block).\n", processId);
    }
}

// Free memory of a process
void deallocateMemory(int processId) {
    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == processId) {
            memory[i] = -1;
        }
    }
    printf("Memory released by Process %d\n", processId);
}

int main() {

    initializeMemory();

    displayMemory();

    allocateMemory(1, 200);
    displayMemory();

    allocateMemory(2, 300);
    displayMemory();

    deallocateMemory(1);
    displayMemory();

    allocateMemory(3, 400);
    displayMemory();

    return 0;
}
