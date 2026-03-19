#include<stdio.h>

int main()
{
    int n,bt[20],p[20],i,j,temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    printf("\nExecution order:\n");
    for(i=0;i<n;i++)
        printf("P%d ",p[i]);

    return 0;
}
