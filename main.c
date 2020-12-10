#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Traduction.h"

int main ( int argc, char *argv[] )

{
    TabularInstructions *tabins = InitTabularInstructions();
    Sequences *seq = InitSequences();
    fillTabIns(tabins, seq);
    writeFile("test.txt",tabins,seq);
    return 0;
}		

