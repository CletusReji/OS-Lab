#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main()
{
    int fd1 = open("readf.txt", O_RDONLY);
    int fd2 = open("writef.txt", O_RDWR | O_CREAT, S_IRWXU);
    int flag = 1;
    char c[1];
    while (flag == 1)
    {
        flag = read(fd1, c, 1);
        if (flag != 1)
        {
            break;
        }
        write(fd2, c, 1);
    }
    close(fd1);
    close(fd2);
}