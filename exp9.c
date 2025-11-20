#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define SHM_SIZE 1024

int main() {
    HANDLE hMapFile;
    char *shm_ptr;

    // Create file mapping object
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // Use paging file
        NULL,                    // Default security
        PAGE_READWRITE,          // Read/write access
        0,                       // Maximum object size (high-order DWORD)
        SHM_SIZE,                // Maximum object size (low-order DWORD)
        "Local\\MySharedMemory"); // Name of mapping object

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%ld).\n", GetLastError());
        return 1;
    }

    // Map the file to process address space
    shm_ptr = (char *) MapViewOfFile(
        hMapFile,               // Handle to map object
        FILE_MAP_ALL_ACCESS,    // Read/write permission
        0,
        0,
        SHM_SIZE);

    if (shm_ptr == NULL) {
        printf("Could not map view of file (%ld).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Write data to shared memory
    strcpy(shm_ptr, "Hello, shared memory in Windows!");
    printf("Data written to shared memory: %s\n", shm_ptr);

    // Clean up
    UnmapViewOfFile(shm_ptr);
    CloseHandle(hMapFile);

    return 0;
}