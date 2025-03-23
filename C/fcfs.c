#include <stdio.h>
struct procs
{
    int pid, arrive, burst, wait, turn, complete;
};
int main()
{
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    struct procs p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Process %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].arrive);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst);
    }
}