#include<stdio.h>
#include"fileTabular.h"
#include"writeHexa.h"


int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    printf("%d %li",tabins->size,tabins->instruction[0].adress); 
    return 0;
}		

