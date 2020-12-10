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




int  opManagment(Stack *stack, TabularInstructions *tabins)

{
    switch(tabins->instruction[stack->PC].arg)
    {
        case 0:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] == stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
            break;
        case 1:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] != stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
            break;
        case 2:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] < stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
            break;
        case 3:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] <= stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
        case 4:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] > stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
        case 5:
            if(stack->SP<1)
                return -1;
            if(stack->pile[stack->SP] >= stack->pile[stack->SP-1])
                stack->pile[stack->SP-1] = 1;
            stack->pile[stack->SP-1] = 0;
            stack->SP--;
            return 0;
        case 6:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1] & stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 7:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1] | stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 8:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1]^stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 9:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] =~ stack->pile[stack->SP-1];
            stack->SP--;
            return 0;
        case 10:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = -2*stack->pile[stack->SP-1];
            stack->SP--;
            return 0;
         case 11:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1] + stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 12:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1]-stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 13:
            if(stack->SP<1)
                return -1;
            stack->SP--;
            stack->pile[stack->SP-1]*=stack->pile[stack->SP];
            return 0;
        case 14:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1]/stack->pile[stack->SP];
            stack->SP--;
            return 0;
        case 15:
            if(stack->SP<1)
                return -1;
            stack->pile[stack->SP-1] = stack->pile[stack->SP-1]%stack->pile[stack->SP];
            stack->SP--;
    }
            return 0;
}


int unstack(Stack *stack)
{
    return 0;
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
                    stack->pile[tabins->instruction[stack->PC].arg] = stack->pile[stack->SP];
                    stack->SP--;
                    stack->PC++; 
                    BREAK;
                CASE("push"):
                    if(stack->SP==3999)
                        return -1;
                    stack->pile[stack->SP]= stack->pile[tabins->instruction[stack->PC].arg] ;
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
                    stack->SP++;
                    stack->PC++; 
                    BREAK;
                CASE("call"):
                    printf("");
                    stack->PC++; 
                    BREAK;
                CASE("ret"):
                    printf("");
                    unstack(stack);
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
                    printf("%d\n",stack->pile[tabins->instruction[stack->PC].arg]);
                    stack->PC++; 
                    BREAK;
                CASE("read"):
                    printf("Entrez une valeure \n-> ");
                    scanf("%d",&stack->pile[tabins->instruction[stack->PC].arg]);
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
                    opManagment(stack,tabins);
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
