#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void fileOperation(char *fileName)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    time_t currentTime;
    currentTime = time(NULL);
    char *strTime = ctime(&currentTime);
    printf("%s", ctime(&currentTime));
    FILE *f ;
    if (f= fopen(fileName, "r"))
    {
        f = fopen(fileName, "a");
        fprintf(f,"Time: %s, pid: %d, ppid: %d\n",strTime,pid,ppid);
    }
    else
    {
        f = fopen(fileName, "w");
        fprintf(f,"Time: %s, pid: %d, ppid: %d\n",strTime,pid,ppid);
    }
    fclose(f);
}
