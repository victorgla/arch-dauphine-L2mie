#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"


int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    tabins->instruction[0].keyWord = "push#";
    tabins->instruction[1].keyWord = "push";
    tabins->size = 2;
    char **arguments = malloc(2*sizeof(char*));
    arguments[0] = "1000";
    arguments[1] = "3";
    char leftover[255];
    argExtra(tabins,arguments,leftover,0);
    writeFile("test.txt",tabins,arguments);
    return 0;
}		

