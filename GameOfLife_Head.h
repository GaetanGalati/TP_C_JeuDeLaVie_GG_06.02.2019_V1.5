#ifndef GAMEOFLIFE_HEAD_H_INCLUDED
#define GAMEOFLIFE_HEAD_H_INCLUDED
#define TAILLE 10
#define GENERATION_MAX 25
#define CELL_LIVE_AT_START 15

//---Typedef---
typedef struct tRandom
{
    int nCellX;
    int nCellY;
} tRandom;
typedef enum stat {survive = 2, birth=1, death=0} stat;

//---Prototype---
extern FILE* fopen(const char* GAMEOFLIFE, const char* Ouverture);
extern void Display(int nTab[TAILLE][TAILLE]);
extern void DisplayTxt(int nTab[TAILLE][TAILLE], tRandom Cell,FILE* fichier);
extern void initTab(int nTab[TAILLE][TAILLE]);
extern void initCellStart(int nTab[TAILLE][TAILLE]);
extern void genCells(int nTab[TAILLE][TAILLE], tRandom Cell,FILE* fichier);
extern stat verifCells(int nTab[TAILLE][TAILLE], tRandom Cell);

#endif // GAMEOFLIFE_HEAD_H_INCLUDED
