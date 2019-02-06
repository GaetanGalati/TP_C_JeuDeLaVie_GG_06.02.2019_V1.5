#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "GameOfLife_Head.h"

//**********************************************************
//Description : Le main.
//
//Entrées : X
//
//Sorties :	Une boucle "for" qui retourne l'affichage du jeu de la vie jussqu'a se qu'elle soit au nombre max de génération
//
//Note :  Parfois quand on le compile le jeu ne se lance pas, il faut juste recompilé
//
//**********************************************************
int main()
{
    srand(time(NULL));
    FILE* fichier = NULL;
    fichier = fopen("GAMEOFLIFE.txt","w+");
    int nTab[TAILLE][TAILLE];
    int i=0;
    tRandom Cell;
    initTab(nTab);

    for (i=1; i < GENERATION_MAX+1; i++)
    {
            Display(nTab);
            printf("\nGeneration : %d\n",i);
            fprintf(fichier, "\nGeneration : %d\n",i);/
            genCells(nTab,Cell,fichier);
            Sleep(500);
            system("cls");
    }
    printf("Le fichier GameOfLife.Txt est disponible");
    return i;
}




