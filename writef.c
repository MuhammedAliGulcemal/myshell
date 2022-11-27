#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void fileOperation(char *fileName)
{
    pid_t pid = getpid();//pid alma
    pid_t ppid = getppid();//ppid alma
    time_t currentTime;
    currentTime = time(NULL);//mevcut zamanı alma
    char *strTime = ctime(&currentTime);//string çevirme
    FILE *f;
    if (f = fopen(fileName, "r"))//file varsa
    {
        f = fopen(fileName, "a");//append modunda aç
        fprintf(f, " pid: %d, ppid: %d, Time: %s\n", pid, ppid,strTime);//ekle
    }
    else//yoksa
    {
        f = fopen(fileName, "w");//yazma modunda aç
        fprintf(f, " pid: %d, ppid: %d, Time: %s\n", pid, ppid,strTime);//yaz
    }
    fclose(f);//dosyayı kapat
}

int main(int argc, char *argv[])//main metod
{
    fileOperation(argv[0]);
    return 0;
}

