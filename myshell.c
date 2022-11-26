#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char *data;
    while (strcmp(&data, "exit"))
    {
        printf("myshell>>");
        scanf("%s", &data);
        printf("data: %s\n", &data);
        if(strcmp(&data, "clear") == 0){
            system("clear");
        }
    }   
}