#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter burst times:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while(completed != n)
    {
        int min = INT_MAX;
        int shortest = -1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            completed++;
            int finish = time;

            wt[shortest] = finish - bt[shortest];
            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess  BT  WT  TAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
