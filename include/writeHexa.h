#include<stdio.h>
#include"fileTabular.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  writeFile
 *  Description:  Permet selon un nom de fichier choisi de générer les codes op et addr
 * =====================================================================================
 */
int writeFile(char *file,TabularInstructions *tabins,char **arg);



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addZeros
 *  Description:  Detecte le nombre n de 0 a rejouter pour une adresse sur un octet et renvoie un tableau de 0 de n digit
 * =====================================================================================
 */
char* addZeros(int addr);

