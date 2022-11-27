#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>


void fileOperation(char* fileName){
    if(ifExists(fileName) == 1){
        FILE *f = fopen(fileName, "a");
        fputs(f,"mali");
        puts("mali append");
    }else{
        FILE *f = fopen(fileName, "w");
        fputs(f,"mali");
        puts("mali write");
    }
}

int ifExists(char* fileName){
    FILE *f = fopen(fileName, "r");
    if(f != NULL){
        fclose(f);
        return 1;
    }else{
        return 0;
    }
}