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
       if (c=="\n")
        compteur+=1;
     }
     return compteur;
  }

<<<<<<< HEAD
  int ReadFile(char* initialcode, Sequences* seq[], Instructions *Intru[]){
=======
  int ReadFile(char* initialcode, Sequences* seq, Instructions *Intru[]){
>>>>>>> a3dccd5eb1698bc9bf2e1dd77b71064cd2e19b71
    FILE *fichier = fopen(initialcode,"r");
    if (initialcode == NULL) {
       printf("%s intouvable", initialcode);
        return 0;
     }
     int n= NbrLignes(initialcode);
     char c;
<<<<<<< HEAD
     int j;
     for (int i = 0; i<n ;i++){
       //lire ligne par ligne
       while(c = getc(fichier) != '\n'){
         seq[i]->adress=i;
         //Pas d'étiquette
        if (c==' '){
          j=0;
          while(c = getc(fichier) == " ")
          seq[i]->rupture[i][j] = "0";
          j++;
=======
     for (int i = 0; i<n ;i++){
       //lire ligne par ligne
       for (c = getc(fichier); c != '\n'; c = getc(fichier)){
         //Pas d'étiquette
        if (c==' '){
          seq->rupture[i]=0;
>>>>>>> a3dccd5eb1698bc9bf2e1dd77b71064cd2e19b71
        }
        else{
          j=0;
          while(c = getc(fichier) != ":"){
            seq[i]->rupture[i][j] = c;
            j++;
          }
        }
        // si le dernier caractère récupéré n'est pas un espace alors c'est la prmière lettre de l'instruction
        if (c != " "){
          Instru[i]->keyword[0] = c;
          j=1;
          while (c=getc(fichier) !=' '){
            Instru[i]->keyword[j] = c;
            j++;
            }
          }
          // le dernier caractère récupéré est ":"
        else{
          j=0;
          while (c=getc(fichier) !=' '){
            Instru[i]->keyword[j] = c;
            j++;
          }
        }
        // dernier caractère récupéré est espace donc pas d'arguments (énoncé)
        if (c == ' ')
          Instru[i].nbArguments=0;
        else{
          while(c=getc(fichier) != "\n"){
            if (c== ' ')
              Instru[i].nbArguments=2; // osef si c'est plus que 2 parce que ça va renvoyer une erreur
            else
              Instru[i].nbArguments=1;
            }

          }
        


     }
  }
