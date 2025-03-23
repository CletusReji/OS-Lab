#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    printf("Parent with pid: %d\n", getpid());
    int pid1 = fork();
    if (pid1 == 0)
    {
        printf("Child 1 with PID: %d\n", getpid());
        int pid2 = fork();
        if (pid2 == 0)
        {
            printf("Child 2 with PID: %d\n", getpid());
            int pid3 = fork();
            if (pid3 == 0)
            {
                printf("Child 3 with PID: %d\n", getpid());
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        wait(NULL);
    }
}