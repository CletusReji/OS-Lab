#include<stdio.h>
#include<unistd.h>
int main() {
    printf("Parent ID: %d\nProcess ID: %d\n", getppid(), getpid());
}