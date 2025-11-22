#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 200   // Maximum track number (example)

int main() {
    int n, head, seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk request queue:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Sort request queue
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nSCAN (Elevator) Disk Scheduling:\n");
    printf("Head Movement Sequence: %d", head);

    int index = 0;

    // Find the first request = head
    for (int i = 0; i < n; i++) {
        if (request[i] >= head) {
            index = i;
            break;
        }
    }

    // Move RIGHT first
    for (int i = index; i < n; i++) {
        seek_time += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    // Then go to END (last track)
    seek_time += abs(head - (DISK_SIZE - 1));
    head = DISK_SIZE - 1;
    printf(" -> %d", head);

    // Then move LEFT
    for (int i = index - 1; i >= 0; i--) {
        seek_time += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);

    return 0;
}
