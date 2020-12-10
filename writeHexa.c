#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include<string.h>
#include<err.h>
#include<math.h>

#define SWITCH(S) char *T = S; if(0)
#define CASE(S) }else if(strcmp(T,S) == 0){switch(1) { case 1
#define BREAK }
#define DEFAULT }  else{switch(1) {case(1) 
 

int getArg(TabularInstructions *tabins, char* leftover,int i)
{
    argExtra(tabins,leftover,i);
    return tabins->instruction[i].arg;
}

int writeFile(char *file, TabularInstructions *tabins,Sequences *seq)
{
    int  addr = 0;
    char* leftover = malloc(255*sizeof(char));
    FILE *fichier = fopen(file,"w");
    if(fichier!=NULL)
    {
        for(int i = 0; i < tabins->size; i++)
        {
            SWITCH(tabins->instruction[i].keyWord)
            {
                CASE("pop"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"00 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("push"):
                    argExtra(tabins,leftover,i);
                    addr = tabins->instruction[i].arg;
                    fprintf(fichier,"01 %04x \n",addr & 0xffff); 
                    BREAK;
                CASE("iPop"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"02 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("iPush"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"03 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("push#"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"04 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("call"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"05 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("ret"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"06 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("jmp"):
                    tabins->instruction[i].arg = findSequenceAdress(seq,tabins,i);
                    addr = tabins->instruction[i].arg; 
                    fprintf(fichier,"07 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("jpc"):
                    tabins->instruction[i].arg = findSequenceAdress(seq,tabins,i);
                    addr = tabins->instruction[i].arg; 
                    fprintf(fichier,"08 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("write"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"09 %04x \n",addr & 0xffff);
                    BREAK;
                CASE("read"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"0a %04x \n",addr & 0xffff);
                    BREAK;
                CASE("rnd"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"0b %04x \n",addr & 0xffff);
                    BREAK;
                CASE("dup"):
                    fprintf(fichier,"0c %04x \n",addr & 0xffff);
                    BREAK;
                CASE("op"):
                    addr = getArg(tabins,leftover,i);
                    fprintf(fichier,"0d %04x \n",addr & 0xffff);
                    BREAK;
                CASE("halt"):
                    fprintf(fichier,"99 %04x \n",addr & 0xffff);
                    BREAK;
                DEFAULT:
                    printf("Erreur dans la detection du mot clé %s \n",tabins->instruction[i].keyWord);
                    BREAK;
            }
        }
        free(leftover);
        fclose(fichier);
    }
    return 1;
}
