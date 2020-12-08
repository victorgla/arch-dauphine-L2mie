#include<stdio.h>
#include<stdlib.h>
#include<err.h>
#include<string.h>
#include"fileTabular.h"
#define SIZE 10

Instructions* InitInstructions()
{
    Instructions *ins = malloc(sizeof(Instructions)); 
    ins->type = 0;
    ins->keyWord = malloc(sizeof(char*));
    ins->adress = 0;
    ins->nbArguments = 0;
    return ins;
}

TabularInstructions* InitTabularInstructions()
{
    TabularInstructions* tabins = malloc(sizeof(TabularInstructions));
    tabins->size = SIZE;
    for(int i = 0; i < SIZE; i++)
    {
        tabins->instruction = malloc(SIZE*sizeof(Instructions));
        InitInstructions();
    }
    return tabins;
}

Sequences* InitSequences()
{
    Sequences* seq = malloc(sizeof(Sequences));
    seq->size = SIZE;
    seq->adress = malloc(SIZE*sizeof(seq->adress));
    seq->rupture = malloc(SIZE*sizeof(seq->rupture));
    //on s'embête pas a optimiser la mémoire on utilise la meme taille pour les rupture et le nb d'adresse;
    int i = 0;
    while(seq->rupture[i]!=NULL)
        seq->rupture[i] = malloc(sizeof(char*));
    return seq;
}

int WhiteSpace(char* str)
{
    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]!=' ' || str[i]!='\n')
            return 0;
        i++;
    }
    return 1;
}


int firstAdress(int *occupation)
{
    for(int i = 0; i < 4000; i++)
        if(!occupation[i])
            return i;
    return -1;
}


//Verification que plusieurs etiquettes aient le meme nom ?
int findSequenceAdress(Sequences *sequence,char *arguments)
{
   for(int i = 0; i < sequence->size; i++)
       if(!strcmp(sequence->rupture[i],arguments))
               return sequence->adress[i];
   return -1;
}



void AdressToHexa(TabularInstructions *tabins,char **arguments, int *occupation, Sequences *sequence)
{
  int seq;
  char* leftover;
  for(int i = 0; i < tabins->size; i++)
  {
      if(tabins->instruction[i].nbArguments)
          continue;//source du bug
      switch ( tabins->instruction[i].type ) 
      {
          case 1:
              tabins->instruction[i].adress = strtol(arguments[i],&leftover,10);
              if(!WhiteSpace(leftover))
                   err(1,"Wrong Adress line %d",i);
              break;
          case -1:
              seq = firstAdress(occupation);
              if(seq==-1)
              {
                  err(1,"No free Adress : line %d",i);
                  return;
              }
              tabins->instruction[i].adress = seq;
              break;
          case 0:
              seq = findSequenceAdress(sequence,arguments[i]);
              if(seq == -1)
              {
                  err(1,"arguments[i] does not exist");
                  return;
              }
              tabins->instruction[i].adress = seq - i;
              break;
          default:
              printf("MERDE");
              break;
      }
    free(leftover);             
   }
}

void FreeInstruction(Instructions *ins)
{
    free(ins->keyWord);
    free(ins);
}

void FreeTabularIns(TabularInstructions *tabins)
{
    for(int i = 0; i < tabins->size; i++)
        FreeInstruction(tabins[i].instruction);
    free(tabins);
}

void FreeSequences(Sequences *seq)
{
    free(seq->adress);
    for(int i = 0; i < seq->size;i++)
        free(seq->rupture[i]);
    free(seq->rupture);
    free(seq);
}
