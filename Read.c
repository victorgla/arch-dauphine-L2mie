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
     char c
     for (c = getc(fichier); c != EOF; c = getc(fichier)){
       if (c==\n)
        compteur+=1;
     }
     return compteur;
  }

  int ReadFile(char* initialcode, Sequences* seq, Instructions *Intru[]){
    FILE *fichier = fopen(initialcode,"r");
    if (initialcode == NULL) {
       printf("%s intouvable", initialcode);
        return 0;
     }
     int n= NbrLignes(initialcode);
     char c;
     for (int i = 0; i<n ;i++){
       //lire ligne par ligne
       for (c = getc(fichier); c != '\n'; c = getc(fichier)){
         //Pas d'étiquette
        if (c==' '){
          seq->rupture[i]=0;
        }
     }
  }
