#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include<string.h>
#include<err.h>


#define SWITCH(S) char *T = S; \
                            if(0)
#define CASE(S) }else if(!strcmp(T,S)) {switch(1) { case 1
#define BREAK }
#define DEFAULT }  else{ switch(1) { case(1) 
 

int writeFile(char *file, TabularInstructions *tabins)
{
    long int addr = -1; 
    FILE *fichier = fopen(file,"w");
    if(fichier!=NULL)
    {
        for(int i = 0; i < tabins->size; i++)
        {
            addr = tabins->instruction[i].adress;
            SWITCH(tabins->instruction[i].keyWord)
            {
                CASE("pop"):
                    fprintf(fichier,"01 , %li \n",addr);
                    BREAK;
                CASE("iPop"):
                    fprintf(fichier,"02, %li \n",addr);
                    BREAK;
                CASE("iPush"):
                    fprintf(fichier,"03, %li \n",addr);
                    BREAK;
                CASE("push#"):
                    fprintf(fichier,"04, %li \n",addr);
                    BREAK;
                CASE("call"):
                    fprintf(fichier,"05, %li \n",addr);
                    BREAK;
                CASE("ret"):
                    fprintf(fichier,"06, %li \n",addr);
                    BREAK;
                CASE("jmp"):
                    fprintf(fichier,"07, %li \n",addr);
                    BREAK;
                CASE("jpc"):
                    fprintf(fichier,"08, %li \n",addr);
                    BREAK;
                CASE("write"):
                    fprintf(fichier,"09, %li \n",addr);
                    BREAK;
                CASE("read"):
                    fprintf(fichier,"10, %li \n",addr);
                    BREAK;
                CASE("rnd"):
                    fprintf(fichier,"11, %li \n",addr);
                    BREAK;
                CASE("dup"):
                    fprintf(fichier,"12, %li \n",addr);
                    BREAK;
                CASE("op"):
                    fprintf(fichier,"13, %li \n",addr);
                    BREAK;
                CASE("halt"):
                    fprintf(fichier,"99, %li \n",addr);
                    BREAK;
                DEFAULT:
                    err(1,"Erreur dans la detection du mot clé %s",tabins->instruction[i].keyWord);
                    BREAK;
            }
        }
    }
    return 1;
}
