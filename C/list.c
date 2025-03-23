#include <unistd.h>
int main()
{
    execlp("ls", "ls", NULL);
}