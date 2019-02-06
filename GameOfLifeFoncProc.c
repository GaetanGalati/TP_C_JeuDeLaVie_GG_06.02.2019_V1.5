#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife_Head.h"

void initTab(int nTab[TAILLE][TAILLE])
{
    int x = 0;
    int y = 0;
    int XTabRand = 0;
    int YTabRand = 0;

    for(x = 1; x < TAILLE; x++)
    {
        for(y = 1; y < TAILLE; y++)
        {
            XTabRand = (rand() % CELL_LIVE_AT_START);
            YTabRand  = (rand() % CELL_LIVE_AT_START);
            nTab[x][y] = 0;
            nTab[XTabRand+1][YTabRand+1]= 1;

        }
    }
}

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

stat verifCells(int nTab[TAILLE][TAILLE], tRandom Cell)
{

    int nCptLive=0;
    int nCptDead=8;
    int nCptBorn=0;

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








