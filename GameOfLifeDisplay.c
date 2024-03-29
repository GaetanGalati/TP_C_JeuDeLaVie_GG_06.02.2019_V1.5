#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife_Head.h"

//**********************************************************
//Description : affichage dans la consol
//
//Entrées : le tableau
//
//Sorties :l'affichage
//
//Note :  x
//
//**********************************************************
void Display(int nTab[TAILLE][TAILLE])
{
    int y = 1;
    int x = 1;

    for (x=1; x < TAILLE; x++)
    {
        for (y=1; y < TAILLE; y++)
        {
            printf("%d ", nTab[x][y]);//Afichage du tableau en X et Y
        }
        printf("\n");//Saut de ligne
    }
}

//**********************************************************
//Description : affichage dans le doc.txt
//
//Entrées : le tableau, la position, le ficher
//
//Sorties :l'affichage dans le txt
//
//Note :  x
//
//**********************************************************
void DisplayTxt(int nTab[TAILLE][TAILLE], tRandom Cell,FILE* fichier){

    switch(verifCells(nTab, Cell))
    {
        case birth:
                fprintf(fichier, "\nLa cellule en [%d][%d] : est née ! :) ",Cell.nCellX,Cell.nCellY);//En cas de naiscance ecrire...
        break;

        case survive:
                fprintf(fichier, "\nLa cellule en [%d][%d] : est encore en vie ! :O ",Cell.nCellX,Cell.nCellY);
        break;

        case death:
                fprintf(fichier, "\nLa cellule en [%d][%d] : est morte... ! :( ",Cell.nCellX,Cell.nCellY);
        break;

        default :
                fprintf(fichier, "\nLa cellule en [%d][%d] : Erreur ",Cell.nCellX,Cell.nCellY);
            break;
        }

}
