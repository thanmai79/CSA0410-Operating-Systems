 #include <stdio.h>

void bestfit(int mp[], int p[], int m, int n) {
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (mp[i] >= p[j]) {
            printf("\nProcess %d of size %d fits in partition %d of size %d",
                   j + 1, p[j], i + 1, mp[i]);
            mp[i] = mp[i] - p[j];
            j++;
            i = i - 1;
        }
    }

    // Remaining processes
    for (int i = j; i < m; i++) {
        printf("\nProcess %d of size %d must wait (No partition available)",
               i + 1, p[i]);
    }
}

void sort(int a[], int n) { // Ascending
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void rsort(int a[], int n) { // Descending
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void firstfit(int mp[], int p[], int m, int n) {
    // First fit DOES NOT SORT (I corrected your logic)
    int used[20] = {0};

    for (int i = 0; i < m; i++) {
        int allocated = 0;
        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                printf("\nProcess %d of size %d fits in partition %d",
                       i + 1, p[i], j + 1);
                mp[j] -= p[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("\nProcess %d of size %d must wait (No partition available)",
                   i + 1, p[i]);
        }
    }
}

void bestfit_call(int mp[], int p[], int m, int n) {
    sort(mp, n);  // ascending
    bestfit(mp, p, m, n);
}

void worstfit(int mp[], int p[], int m, int n) {
    rsort(mp, n); // descending
    bestfit(mp, p, m, n);
}

int main() {
    int m, n, mp[20], p[20], ch;

    printf("Number of memory partitions: ");
    scanf("%d", &n);

    printf("Number of processes: ");
    scanf("%d", &m);

    printf("Enter the memory partitions :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &mp[i]);
    }

    printf("Enter process sizes :\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            firstfit(mp, p, m, n);
            break;

        case 2:
            bestfit_call(mp, p, m, n);
            break;

        case 3:
            worstfit(mp, p, m, n);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
