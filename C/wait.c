#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid = fork();
    if (pid == -1)
    {
        printf("Error\n");
    }
    else if (pid == 0)
    {
        printf("This is Child Executing\n");
    }
    else
    {
        wait(NULL);
        printf("This is Parent Executing after Waiting\n");
    }
}