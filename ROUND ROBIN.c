#include <stdio.h>

int main() {
    int n, i, time = 0, tq;
    int bt[10], rem[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i]; // remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;

                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
