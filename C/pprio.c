#include <stdio.h>

struct procs
{
    int pid, arrive, burst, complete, turnaround, wait, remaining, priority;
};

int main()
{
    int n;
    printf("Enter number of processes: ");
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
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
        p[i].complete = 0;
    }

    int currentTime = 0, completed = 0, minPriority;

    while (completed < n)
    {
        minPriority = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrive <= currentTime && p[i].remaining > 0)
            {
                if (minPriority == -1 || p[i].priority < p[minPriority].priority)
                    minPriority = i;
            }
        }

        if (minPriority == -1)
        {
            currentTime++;
            continue;
        }

        p[minPriority].remaining--;

        if (p[minPriority].remaining == 0)
        {
            p[minPriority].complete = currentTime + 1;
            p[minPriority].turnaround = p[minPriority].complete - p[minPriority].arrive;
            p[minPriority].wait = p[minPriority].turnaround - p[minPriority].burst;
            completed++;
        }

        currentTime++;
    }

    printf("\nProcess\tArrival\tWaiting\tBurst\tTurnaround\tCompletion");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t\t%d", p[i].pid, p[i].arrive, p[i].wait, p[i].burst, p[i].turnaround, p[i].complete);
    }
    printf("\n");
    return 0;
}