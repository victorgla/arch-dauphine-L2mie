#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include"writeHexa.h"
#include"Read.h"
#include"mainProcess.h"

typedef struct Stack{
    int pile[4000];
    int PC;
    int SP; //adress pointée
}Stack;

Stack *initStack();

int Exec(TabularInstructions* tabins,  Stack* pile);
