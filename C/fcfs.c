#include <stdio.h>
struct procs
{
    int pid;
    int arrive;
    int wait;
    int burst;
    int turnaround;
    int completion;
};

int main()
{
    int n;
    printf("Enter no. of Processes: ");
    scanf("%d", &n);
    struct procs process[n];
    for (int i = 0; i < n; i++)
    {
        process[i].pid = i + 1;
        printf("\nFor Process %d:", i + 1);
        printf("\nArrival Time: ");
        scanf("%d", &process[i].arrive);
        printf("Burst Time: ");
        scanf("%d", &process[i].burst);
    }
    struct procs temp;
    int swapped = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (process[j].arrive > process[j + 1].arrive)
            {
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
    process[0].completion = process[0].burst + process[0].arrive;
    process[0].turnaround = process[0].completion - process[0].arrive;
    process[0].wait = 0;
    for (int i = 1; i < n; i++)
    {
        process[i].completion = process[i - 1].completion + process[i].burst;
        process[i].turnaround = process[i].completion - process[i].arrive;
        process[i].wait = process[i].turnaround - process[i].burst;
    }
    printf("\nProcess\t\tArrival Time\tWaiting Time\tBurst Time\tTurnaround Time\tCompletion Time");
    float avgwait = 0, avgturn = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", process[i].pid, process[i].arrive, process[i].wait, process[i].burst, process[i].turnaround, process[i].completion);
        avgwait += process[i].wait;
        avgturn += process[i].turnaround;
    }
    avgwait /= n;
    avgturn /= n;
    printf("\n");
    return 0;
}