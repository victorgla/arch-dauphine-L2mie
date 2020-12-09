#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include<string.h>
#include<err.h>
#define T_MAX 256

//Trouver le nbre de lignes du fichier
int NbrLignes (char* initialcode){
     FILE *fichier = fopen(initialcode,"r");
     if (initialcode == NULL) {
        printf("%s intouvable", initialcode);
         return 0;
      }
     int compteur=0;
     char c = '0';
     for (c = getc(fichier); c != EOF; c = getc(fichier)){
       if (c=='\n')
        compteur+=1;
     }
     return compteur;
  }

  int ReadFile(char* initialcode, Sequences* seq[], Instructions *Intru[]){
    FILE *fichier = fopen(initialcode,"r");
    if (initialcode == NULL) {
       printf("%s intouvable", initialcode);
        return 0;
     }
     int n= NbrLignes(initialcode);
     char c;
     int j;
     for (int i = 0; i<n ;i++){
       //lire ligne par ligne
       while((c = getc(fichier)) != '\n'){
         *seq[i]->adress = i;
         //Pas d'étiquette
        if (c==' '){
          j=0;
          while(((c = getc(fichier)) == ' '))
          seq[i]->rupture[i][j] = '0';
          j++;
        }
        else{
          j=0;
          while((c = getc(fichier)) != ':'){
            seq[i]->rupture[i][j] = c;
            j++;
          }
        }
        // si le dernier caractère récupéré n'est pas un espace alors c'est la prmière lettre de l'instruction
        if (c != ' '){
          Intru[i]->keyWord[0] = c;
          j=1;
          while ((c=getc(fichier)) !=' '){
            Intru[i]->keyWord[j] = c;
            j++;
            }
          }
          // le dernier caractère récupéré est ":"
        else{
          j=0;
          while ((c=getc(fichier)) !=' '){
            Intru[i]->keyWord[j] = c;
            j++;
          }
        }
        // dernier caractère récupéré est espace donc pas d'arguments (énoncé)
        /**if (c == ' ')
          Intru[i]->nbArguments=0;
        else{
          while((c=getc(fichier)) != '\n'){
            if (c== ' ')
              Intru[i]->nbArguments=2; // osef si c'est plus que 2 parce que ça va renvoyer une erreur
            else
              Intru[i]->nbArguments=1;
            }**/

          }
        


     
  }
     return 0;
  }

