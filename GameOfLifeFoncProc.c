#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife_Head.h"

//**********************************************************
//Description : L'initialisation du tableau.
//
//Entrées : le tableau Ntab
//
//Sorties :	le tableau Ntab inisialisé (chaque case = 1 OU 0)
//
//Note :  Utilisation du random
//
//**********************************************************
void initTab(int nTab[TAILLE][TAILLE])
{
    int x = 0;
    int y = 0;//Postion en XY (chaque itération de for)
    int XTabRand = 0;
    int YTabRand = 0;//Postion random dans le tableau

    for(x = 1; x < TAILLE; x++)
    {
        for(y = 1; y < TAILLE; y++)
        {
            XTabRand = (rand() % CELL_LIVE_AT_START);
            YTabRand  = (rand() % CELL_LIVE_AT_START);
            nTab[x][y] = 0;//La cellule en [X] et [Y] prend la valeur 0
            nTab[XTabRand+1][YTabRand+1]= 1;//Une cellule dans le tableau prend la valeur 1

        }
    }
}

//**********************************************************
//Description : Génération de chaque cellules
//
//Entrées : le tableau Ntab, la cellule et le fichier
//
//Sorties :	Affection du tablau et lancement de l'affichage
//
//Note :  x
//
//**********************************************************
void genCells(int nTab[TAILLE][TAILLE], tRandom Cell,FILE* fichier)
{
    for(Cell.nCellX = 1; Cell.nCellX < TAILLE; Cell.nCellX++)
    {
        for(Cell.nCellY = 1; Cell.nCellY < TAILLE; Cell.nCellY++)
        {
            switch(verifCells(nTab, Cell))
            {
            case birth:
                nTab[Cell.nCellX][Cell.nCellY]= 1;
                DisplayTxt(nTab,Cell,fichier);
                break;

            case survive:
                nTab[Cell.nCellX][Cell.nCellY]= 1;
                DisplayTxt(nTab,Cell,fichier);
                break;

            case death:
                nTab[Cell.nCellX][Cell.nCellY]= 0;
                DisplayTxt(nTab,Cell,fichier);
                break;

            default :
                printf("\nLa cellule en [%d][%d] : Erreur",Cell.nCellX,Cell.nCellY);
                break;
            }
        }
    }
}

//**********************************************************
//Description : Verification de la cellule
//
//Entrées : le tableau et une position (tRandom Cell)
//
//Sorties :	survive , birth, death
//
//Note :  x
//
//**********************************************************
stat verifCells(int nTab[TAILLE][TAILLE], tRandom Cell)
{

    int nCptLive=0;//Compteur de cellule en vie au tour de la cellule que l'on vérifie
    int nCptDead=8;//Compteur de cellule mortes au tour de la cellule que l'on vérifie
    int nCptBorn=0;//Compteur pour la naiscance

    if (Cell.nCellY+1 >= TAILLE)
    {
        Cell.nCellY = Cell.nCellY -1;
    }
    if (Cell.nCellX+1 >= TAILLE )
    {
        Cell.nCellX = Cell.nCellX -1 ;
    }
    if (Cell.nCellY-1 <= 0)
    {
        Cell.nCellY = TAILLE-1;
    }
    if (Cell.nCellX-1 <= 0 )
    {
        Cell.nCellX = TAILLE-1 ;
    }

//Mort par surpopulation :
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX+1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY-1][Cell.nCellX-1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX-1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY-1][Cell.nCellX+1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY][Cell.nCellX+1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY][Cell.nCellX-1]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX]==1)
    {
        nCptLive += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY-1][Cell.nCellX]==1)
    {
        nCptLive += 1;
    }

//Mort par isolement
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX+1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]== 1&& nTab[Cell.nCellY-1][Cell.nCellX-1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX-1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY-1][Cell.nCellX+1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY][Cell.nCellX+1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY][Cell.nCellX-1]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY+1][Cell.nCellX]==0)
    {
        nCptDead -= 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==1 && nTab[Cell.nCellY-1][Cell.nCellX]==0)
    {
        nCptDead -= 1;
    }


    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY+1][Cell.nCellX+1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY-1][Cell.nCellX-1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY+1][Cell.nCellX-1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY-1][Cell.nCellX+1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY][Cell.nCellX+1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY][Cell.nCellX-1]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY+1][Cell.nCellX]==1)
    {
        nCptBorn += 1;
    }
    if(nTab[Cell.nCellY][Cell.nCellX]==0 && nTab[Cell.nCellY-1][Cell.nCellX]==1)
    {
        nCptBorn += 1;
    }

    if(nCptLive > 3 ||  nCptDead <= 1)
    {
        return death;
    }
    else if (nCptBorn >=4)
    {
        return birth;
    }
    else if (nCptLive == 2 || nCptLive == 3)
    {
        return survive;
    }
}








