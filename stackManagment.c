#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Read.h"
#include"mainProcess.h"
#include"stackManagment.h"
#include<string.h>
#define SWITCH(S) char *T = S; if(0)
#define CASE(S) }else if(strcmp(T,S) == 0){switch(1) { case 1
#define BREAK }
#define DEFAULT }  else{switch(1) {case(1) 



Stack *initStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->PC = 0;
    stack->SP = 0;
    return stack;
}


int Exec(TabularInstructions* tabins, Stack* stack)
{
        while(stack->PC!=tabins->size)
        {
            SWITCH(tabins->instruction[stack->PC].keyWord)
            {
                CASE("pop"):
                    if(!stack->SP)
                        return -1;
                    stack->memory[tabins->instruction[stack->PC].arg] = stack->pile[stack->SP];
                    stack->SP--;
                    stack->PC++; 
                    BREAK;
                CASE("push"):
                    if(stack->SP==3999)
                        return -1;
                    stack->SP++;
                    stack->pile[stack->SP]= stack->memory[tabins->instruction[stack->PC].arg] ;
                    stack->PC++; 
                    BREAK;
                CASE("iPop"):
                    if(stack->SP<2)
                        return -1;
                    stack->pile[stack->SP-2] = stack->pile[stack->SP-1];
                    stack->SP-=2;
                    stack->PC++; 
                    BREAK;
                CASE("iPush"):
                    if(stack->SP==3999)
                        return -1;
                    stack->pile[stack->SP+1] = stack->pile[stack->SP];
                    stack->SP++;
                    stack->PC++; 
                    BREAK;
                CASE("push#"):
                    if(stack->SP == 3999)
                        return -1;
                    stack->pile[stack->SP] = tabins->instruction[stack->PC].arg;
                    stack->PC++; 
                    BREAK;
                CASE("call"):
                    printf("");
                    stack->PC++; 
                    BREAK;
                CASE("ret"):
                    printf("");
                    //unstack(stack);
                    stack->PC++; 
                    BREAK;
                CASE("jmp"):
                    if(stack->PC - tabins->instruction[stack->PC].arg<0)
                        return -1;
                    stack->PC += tabins->instruction[stack->PC].arg;
                    BREAK;
                CASE("jpc"):
                    if(!stack->SP)
                        return -1;
                    if(!stack->pile[stack->SP] && (stack->PC - tabins->instruction[stack->PC].arg)>=0)
                        stack->PC -= tabins->instruction[stack->PC].arg;
                    else
                        stack->PC++; 
                    stack->SP--;
                    BREAK;
                CASE("write"):
                    printf("%d\n",stack->memory[tabins->instruction[stack->PC].arg]);
                    stack->PC++; 
                    BREAK;
                CASE("read"):
                    printf("Entrez une valeure \n-> ");
                    scanf("%d",&stack->memory[tabins->instruction[stack->PC].arg]);
                    stack->PC++; 
                    BREAK;
                CASE("rnd"):
                    stack->pile[stack->SP] = rand()%tabins->instruction[stack->PC].arg;
                    stack->SP++;
                    stack->PC++; 
                    BREAK;
                CASE("dup"):
                    if(!stack->SP)
                        return -1;
                    stack->pile[stack->SP] = stack->pile[stack->SP-1];
                    stack->SP++;
                    stack->PC++; 
                    BREAK;
                CASE("op"):
                    printf("");
                    stack->PC++; 
                    BREAK;
                CASE("halt"):
                    return 1;
                    BREAK;
                DEFAULT:
                    printf("Erreur dans la detection du mot clé %s \n",tabins->instruction[stack->PC].keyWord);
                    BREAK;
                }
            }
        return -1;
}
