#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char data[100];//inputu tutmak için array
    char bashData[100];//bash inputu tutmak için array
    char *strArr[100];//girilen inputu parçalara bölüp tutmak için array
    int fd[2];//pipe için
    while (strcmp(data, "exit"))
    {
        int noCommand = 1;
        printf("myshell>>");
        scanf("%[^\n]%*c", data);//input alma
        char *str = strtok(data, " ");
        int i = 0;
        strArr[i] = str;
        i++;
        while (str != NULL)//inputu parçalara ayırma
        {
            str = strtok(NULL, " ");
            strArr[i] = str;
            i++;
        }
        i--;
        char *command = strArr[0];//ana komutun 0. elemandan alınması
        if (strcmp(command, "clear") == 0)//clearsa 
        {
            noCommand = 0;
            system("clear");//temizle
        }
        if (strcmp(command, "bash") == 0)//bashse
        {
            noCommand = 0;
            while (strcmp(bashData, "exit"))//exit yazmadıkça
            {
                printf("bash>>");
                scanf("%[^\n]%*c", bashData);
                system(bashData);//bash komutunu gir
            }
        }
        if (strcmp(command, "writef") == 0 && strcmp(strArr[1], "-f") == 0)//writefse ve -f yazmışsa
        {
            noCommand = 0;
            char *writeArr[2] = {strArr[2], NULL};//writefe göndermek için array
            if (pipe(fd) == -1)
            {
                puts("An error occured!");
                exit(1);
            }
            int pid = fork();//fork yapma
            int val;
            if (pid == 0)
            {
                close(fd[0]);//kapatma
                val = execve("writef", writeArr, NULL);//execve writef için
            }
            wait(&val);//bekleme
            close(fd[1]);//kapatma
        }
        if (strcmp(command, "execx") == 0 && strcmp(strArr[1], "-t") == 0)//execx ve -t yazmışsa
        {
            noCommand = 0;
            char *execArr[5] = {strArr[2],strArr[3],strArr[4],strArr[5],NULL};//execx için array
            if (pipe(fd) == -1)
            {
                puts("An error occured!");
                exit(1);
            }
            int pid = fork();//fork yapma
            int val;
            if (pid == 0)
            {
                close(fd[0]);//kapatma
                val = execve("execx", execArr, NULL);//execve execx için
            }
            wait(&val);//bekleme
            close(fd[1]);//kapatma
        }
        if (strcmp(command, "ls") == 0)//ls yazmışsa
        {
            noCommand = 0;
            system("ls");
        }
        if (strcmp(command, "cat") == 0)//cat yazmışsa
        {
            noCommand = 0;
            printf("cat:");
            for (int j = 1; j < i; j++)
            {
                printf("%s ", strArr[j]);//ekrana yazdır
            }
            puts("");
        }
        if (noCommand == 1 && strcmp(command, "exit"))//girilen komut yoksa ve exit yazmamışsa
        {
            puts("Wrong command!");//yanlış komut yaz
        }
    }
    return 0;
}