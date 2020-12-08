#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"


int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    tabins->instruction[0].nbArguments = 1;
    tabins->instruction[0].type = 0;
    tabins->instruction[0].keyWord = "push#";
    tabins->instruction[1].nbArguments = 1;
    tabins->instruction[1].type = 1;
    tabins->instruction[1].keyWord = "push";
    tabins->size = 2;
    char **arguments = malloc(2*sizeof(char*));
    arguments[0] = "1000";
    arguments[1] = "3";
    int *occupation = malloc(4000*sizeof(int));
    Sequences *seq = InitSequences();
    AdressToHexa(tabins,arguments,occupation,seq);
    writeFile("test.txt",tabins);
    return 0;
}		

