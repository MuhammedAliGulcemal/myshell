#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// void fileOperation(char* fileName);

int main()
{
    char *data[100];
    char *bashData[100];
    while (strcmp(data, "exit"))
    {
        printf("myshell>>");
        scanf("%[^\n]%*c", &data);
        printf("data: %s\n", &data);
        if (strcmp(data, "clear") == 0)
        {
            system("clear");
        }
        if (strcmp(data, "bash") == 0)
        {
            while (strcmp(bashData, "exit"))
            {
                printf("bash>>");
                scanf("%[^\n]%*c", &bashData);
                printf("data: %s\n", &bashData);
                system(bashData);
            }
        }
        /*if (strcmp(data, "writef -f") == 0)
        {
            puts("file girdi");
            fileOperation("mali");
        }*/
        if (strcmp(data, "ls") == 0)
        {
            system("ls");
        }

        if (strcmp(data,"cat") == 0)
        {   
            printf("%s\n", data);
        }
        else
        {
            puts("Wrong command!");
        }
    }
    return 1;
}