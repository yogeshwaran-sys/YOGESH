#include<stdio.h>

int main()
{
    int n,i,j,time=0,highest;
    int bt[10],rt[10],priority[10];
    int remain,flag=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain=n;

    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority of P%d: ",i+1);
        scanf("%d %d",&bt[i],&priority[i]);
        rt[i]=bt[i];   // remaining time
    }

    while(remain!=0)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                if(highest==-1 || priority[i] < priority[highest])
                {
                    highest=i;
                }
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            remain--;
            printf("Process P%d completed at time %d\n",highest+1,time);
        }
    }

    return 0;
}

