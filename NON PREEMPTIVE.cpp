#include <stdio.h>

int main()
{
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sorting by burst time
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess  BT  WT  TAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
