#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort burst times (SJF)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output
    printf("\nBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);
    }

    return 0;
}
