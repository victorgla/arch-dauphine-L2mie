#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Traduction.h"

int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    Sequences *seq = InitSequences();
    tabins->size = 12;
    fillTabIns(tabins, seq);
    //writeFile("test.txt",tabins);
    return 0;
}		

