#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Read.h"

int fillTabIns(char **arguments, TabularInstructions *tabins, Sequences *seq)
{
    
    tabins->size = NbrLignes("code.txt");
    ReadFile("code.txt",seq,tabins); 
    return 0;
}
