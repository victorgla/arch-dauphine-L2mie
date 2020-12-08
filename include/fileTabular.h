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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitSequences
 *  Description:  Initialise une structure de sequence 
 * =====================================================================================
 */
Sequences* InitSequences();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitTabularInstructions
 *  Description: Initialise la structure TS et alloue l'espace mémoire suffisant 
 * =====================================================================================
 */
TabularInstructions*  InitTabularInstructions();


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitInstructions
 *  Description: Initialise la structure I  
 * =====================================================================================
 */
Instructions *InitInstructions();


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  firstAdress
 *  Description: A partir du tableau d'occupation de toutes les adress
 *  Return : -1 si il n'y a aucune adress libre sinon l'indice de celle-ci
 =====================================================================================
 */
int firstAdress(int *occupation);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitInstructions
 *  Description: Reccupère les adresses contenues dans séquence et les transfert une
 *  fois adapté à l'ecriture binaire dans la structure TI 
 * =====================================================================================
 */
void AdressToHexa(struct TabularInstructions *tabins,char **arguments, int *occupation, struct Sequences *sequence);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  findSequenceAdress
 *  Description: Detecte si l'etiquette existe dans le code 
 *  Return: L'adresse de la première étiquette correspondante 
 * =====================================================================================
 */
int findSequenceAdress(Sequences *sequence, char *arguments);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  FreeTabularIns
 *  Description: Libère l'espace utilisé par la structure TI 
 * =====================================================================================
 */
void FreeTabularIns(struct TabularInstructions* tabins);



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  FreeInstruction
 *  Description: Libère l'espace utilisé par la structure I 
 * =====================================================================================
 */
void FreeInstrcution(struct Instructions* ins);



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  FreeSequences
 *  Description:  Libère l'espace occupé par les éléments de sequence 
 * =====================================================================================
 */
void FreeSequences(struct Sequences *seq);

#endif


