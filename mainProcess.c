#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Read.h"
#include"mainProcess.h"
#include"stackManagment.h"


int Execution()
{
    TabularInstructions *tabins = InitTabularInstructions();
    Sequences *seq = InitSequences();
    ReadFile("code.txt",seq,tabins); 
    tabins->size = NbrLignes("code.txt");
    writeFile("hexa.txt",tabins,seq);
    Stack *stack = initStack();
    Exec(tabins,stack);
    return 0;
}
