#include <stdio.h>
#include <stdlib.h>

// Structure for a record
struct Record {
    int recordNumber;
    char data[256];
};

int main() {

    FILE *file;
    struct Record record;
    int recordNumber;

    // Open file for writing
    file = fopen("sequential_file.txt", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter records (Enter 0 as record number to stop writing):\n");

    while (1) {
        printf("Record Number: ");
        scanf("%d", &record.recordNumber);

        if (record.recordNumber == 0)
            break;

        printf("Data: ");
        scanf(" %[^\n]", record.data);

        fwrite(&record, sizeof(struct Record), 1, file);
    }

    fclose(file);

    // Open file for reading
    file = fopen("sequential_file.txt", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    while (1) {
        printf("\nEnter the record number to read (0 to exit): ");
        scanf("%d", &recordNumber);

        if (recordNumber == 0)
            break;

        rewind(file); // Reset pointer before each read

        int found = 0;

        while (fread(&record, sizeof(struct Record), 1, file)) {
            if (record.recordNumber == recordNumber) {
                printf("Record Number: %d\n", record.recordNumber);
                printf("Data: %s\n", record.data);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Record not found.\n");
    }

    fclose(file);

    return 0;
}
