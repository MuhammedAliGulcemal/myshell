#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execx(char *arg[], int count)
{
    if (strcmp(arg[2], "-f")== 0)//-f yazmışsa writef çağırıyorum
    {
        int fd[2];
        char *writeArr[2] = {arg[3], NULL};//writefe göndermek için array
        if (pipe(fd) == -1)
        {
            puts("An error occured!");
            exit(1);
        }
        for (int i = 0; i < count; i++)//girilen sayı kadar çağırıyorum
        {
            int pid = fork();//fork yapma
            int val;
            if (pid == 0)
            {
                close(fd[0]);//kapama
                val = execve(arg[1], writeArr, NULL);//execve writef için
            }
            wait(&val);//bekleme
            close(fd[1]);//kapama
        }
    }
    else//-f yazmamışsa dönüyorum
    {
        puts("Wrong command!");
        return;
    }
}
int main(int argc, char *argv[])//main metod
{
    execx(argv, atoi(argv[0]));
    return 0;
}