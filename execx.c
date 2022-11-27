#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execx(char *arg)
{
    pid_t pid = fork();
    char *path = "/bin/bash";
    if (pid == -1)
    {
        return -1;
    }
    if (pid == 0)
    {
        int val = execve(path, arg, NULL);
    }
    else
    {
        wait(NULL);
    }
}