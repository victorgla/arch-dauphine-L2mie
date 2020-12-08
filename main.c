#include<stdio.h>
#include"fileTabular.h"
#include"writeHexa.h"


int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    tabins->instruction[0] = *InitInstructions();
    tabins->size++;
    printf("%d",tabins->size); 
    return 0;
}		

