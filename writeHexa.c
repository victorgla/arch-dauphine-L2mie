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
 
char* addZeros(int addr)
{
    int dig = 0;
    if(addr)
        dig = log(addr)/log(16);
    dig = 3 - dig;
    char* zeroAdd = malloc(dig*sizeof(char));
    for(int i = 0; i < dig;i++)
        zeroAdd[i] = '0';
    return zeroAdd;
}



int writeFile(char *file, TabularInstructions *tabins)
{
    unsigned int addr = -1; 
    FILE *fichier = fopen(file,"w");
    if(fichier!=NULL)
    {
        for(int i = 0; i < tabins->size; i++)
        {
            addr = tabins->instruction[i].adress;
            char* zAdd = addZeros(addr);
            SWITCH(tabins->instruction[i].keyWord)
            {
                CASE("pop"):
                    fprintf(fichier,"00 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("push"):
                    fprintf(fichier,"01 %s%x \n",zAdd,addr); 
                    BREAK;
                CASE("iPop"):
                    fprintf(fichier,"02 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("iPush"):
                    fprintf(fichier,"03 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("push#"):
                    fprintf(fichier,"04 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("call"):
                    fprintf(fichier,"05 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("ret"):
                    fprintf(fichier,"06 %s%x \n",zAdd,addr);
                    BREAK;
                CASE("jmp"):
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
        fclose(fichier);
    }
    return 1;
}