#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void fileOperation(char *fileName);

int main()
{
    char data[100];
    char bashData[100];
    char *strArr[100];
    while (strcmp(data, "exit"))
    {
        int noCommand = 1;
        printf("myshell>>");
        scanf("%[^\n]%*c", data);
        char *str = strtok(data, " ");
        int i = 0;
        strArr[i] = str;
        i++;
        while (str != NULL)
        {
            str = strtok(NULL, " ");
            strArr[i] = str;
            i++;
        }
        i--;
        char *command = strArr[0];
        if (strcmp(command, "clear") == 0)
        {
            noCommand = 0;
            system("clear");
        }
        if (strcmp(command, "bash") == 0)
        {
            noCommand = 0;
            while (strcmp(bashData, "exit"))
            {
                printf("bash>>");
                scanf("%[^\n]%*c", bashData);
                system(bashData);
            }
        }
        if (strcmp(command, "writef") == 0 && strcmp(strArr[1], "-f") == 0)
        {
            noCommand = 0;
            puts("file girdi");
            fileOperation(strArr[2]);
        }
        if (strcmp(command, "ls") == 0)
        {
            noCommand = 0;
            system("ls");
        }
        if (strcmp(command, "cat") == 0)
        {
            noCommand = 0;
            printf("cat:");
            for (int j = 1; j < i; j++)
            {
                printf("%s ", strArr[j]);
            }
            puts("");
        }
        if(noCommand == 1 && strcmp(command,"exit")){
            puts("Wrong command!");
        }
    }
    return 1;
}