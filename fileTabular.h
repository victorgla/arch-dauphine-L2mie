#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include<stdio.h>

typedef struct Instructions 
{
    char *keyWord;
    int type; //-1 pour une rupture de séquence, 0 pour une valeure, 1 pour une adresse;
    int nbArguments; 
    long int adress;
}Instructions;
    /* ----------  end of struct Instructions  ---------- */

typedef struct Sequences{
    char **rupture;
    int *adress;
    int size;
}Sequences;


typedef struct TabularInstructions 
{
    Instructions* instruction;
    int size;
}TabularInstructions;
    /* ----------  end of struct TabularInstructions  ---------- */

void InitTabularInstructions(struct TabularInstructions* tabIn);

void InitInstructions(struct Instructions* ins);

void AdressToHexa(struct TabularInstructions *tabins,char **arguments, int *occupation, struct Sequences *sequence);

int LocateFreeAdress(int *Adress);

void FreeTabularIns(struct TabularInstructions* tabins);

void FreeInstrcution(struct Instructions* ins);

#endif


