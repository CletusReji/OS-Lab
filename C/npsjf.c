#include <stdio.h>
struct procs
{
    int pid, arrive, burst, complete, turnaround, wait;
};

void swap(struct procs *a, struct procs *b)
{
    struct procs temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter no. of Processes: ");
    scanf("%d", &n);
    struct procs p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nFor Process %d:", i + 1);
        printf("\nArrival Time: ");
        scanf("%d", &p[i].arrive);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrive > p[j + 1].arrive || p[j].arrive == p[j + 1].arrive && p[j].burst > p[j + 1].burst)
            {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
    int curtime = 0, completed = 0, min;
    int iscomplete[n];
    for (int i = 0; i < n; i++)
    {
        iscomplete[i] = 0;
    }
    while (completed < n)
    {
        min = -1;
        for (int i = 0; i < n; i++)
        {
            if (iscomplete[i] == 0 && p[i].arrive <= curtime)
            {
                if (min == -1 || p[i].burst < p[min].burst)
                {
                    min = i;
                }
            }
        }
        if (min == -1)
        {
            curtime++;
        }
        else
        {
            p[min].complete = curtime + p[min].burst;
            p[min].turnaround = p[min].complete - p[min].arrive;
            p[min].wait = p[min].turnaround - p[min].burst;
            curtime = p[min].complete;
            iscomplete[min] = 1;
            completed++;
        }
    }
    printf("\nProcess\tArrival\tWaiting\tBurst\tTurnaround\tCompletion");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t\t%d", p[i].pid, p[i].arrive, p[i].wait, p[i].burst, p[i].turnaround, p[i].complete);
    }
    printf("\n");
    return 0;
}