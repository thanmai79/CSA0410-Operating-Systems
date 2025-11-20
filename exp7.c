#include <stdio.h>

int main() {
    int at[10], bt[10], pr[10];
    int n, i, j, temp;
    int time = 0, over = 0;
    int sum_wait = 0, sum_turnaround = 0;
    int start;
    float avgwait, avgturn;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority of P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort based on arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
            }
        }
    }

    printf("\n\nProcess\t| Arrival | Burst | Priority | Start | End | Waiting | Turnaround\n");
    printf("--------------------------------------------------------------------------\n");

    while (over < n) {

        // Select highest priority among arrived processes
        int pos = -1;
        int high = -9999;

        for (i = over; i < n; i++) {
            if (at[i] <= time && pr[i] > high) {
                high = pr[i];
                pos = i;
            }
        }

        // If CPU is idle
        if (pos == -1) {
            time++;
            continue;
        }

        // Swap selected process to "over" position
        temp = at[over]; at[over] = at[pos]; at[pos] = temp;
        temp = bt[over]; bt[over] = bt[pos]; bt[pos] = temp;
        temp = pr[over]; pr[over] = pr[pos]; pr[pos] = temp;

        start = time;
        time += bt[over];

        printf("P%d\t|   %d\t|   %d\t|    %d\t|   %d\t|  %d\t|   %d\t|   %d\n",
               over + 1,
               at[over],
               bt[over],
               pr[over],
               start,
               time,
               time - at[over] - bt[over],
               time - at[over]);

        sum_wait += time - at[over] - bt[over];
        sum_turnaround += time - at[over];

        over++;
    }

    avgwait = (float)sum_wait / n;
    avgturn = (float)sum_turnaround / n;

    printf("\nAverage Waiting Time: %f\n", avgwait);
    printf("Average Turnaround Time: %f\n", avgturn);

    return 0;
}
