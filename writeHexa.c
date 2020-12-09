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
 
void addZeros(char* zeroAdd,int addr)
{
    int dig = 0;
    if(addr)
        dig = log(addr)/log(16);
    dig = 3 - dig;
    for(int i = 0; i < dig;i++)
        zeroAdd[i] = '0';
}


unsigned int getArg(TabularInstructions *tabins,char** arguments, char* leftover,int i, char* zAdd)
{
    argExtra(tabins,arguments,leftover,i);
    addZeros(zAdd,tabins->instruction[i].arg);
    printf("%s",zAdd);
    return (unsigned int)tabins->instruction[i].arg;
}

int writeFile(char *file, TabularInstructions *tabins,char **arguments,Sequences *seq)
{
    unsigned int addr = -1;
    char* zAdd = malloc(4*sizeof(char));
    char* leftover = malloc(255*sizeof(char));
    FILE *fichier = fopen(file,"w");
    if(fichier!=NULL)
    {
        for(int i = 0; i < tabins->size; i++)
        {
            addr = tabins->instruction[i].arg;
            SWITCH(tabins->instruction[i].keyWord)
            {
                CASE("pop"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"00 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("push"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"01 %s%x \n",zAdd,addr); 
                    BREAK;
                CASE("iPop"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"02 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("iPush"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"03 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("push#"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"04 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("call"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"05 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("ret"):
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"06 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("jmp"):
                    findSequenceAdress(seq,arguments[i]);
                    addr = getArg(tabins,arguments,leftover,i,zAdd);
                    fprintf(fichier,"07 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("jpc"):
                    fprintf(fichier,"08 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("write"):
                    fprintf(fichier,"09 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("read"):
                    fprintf(fichier,"10 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("rnd"):
                    fprintf(fichier,"11 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("dup"):
                    fprintf(fichier,"12 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("op"):
                    fprintf(fichier,"13 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("halt"):
                    fprintf(fichier,"99 %s%x \n",zAdd,addr);
                    BREAK;
                DEFAULT:
                    errx(1,"Erreur dans la detection du mot clé %s \n",tabins->instruction[i].keyWord);
                    BREAK;
            }
        }
        free(zAdd);
        free(leftover);
        fclose(fichier);
    }
    return 1;
}
