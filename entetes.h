#ifndef MON_H
#define MON_H

#include <stdio.h>




typedef struct
{
    int ligne ; //[0]
    int col ;   //[1]
    int depl ;  //[2]     /// 1=gauche, 2=haut, 3=droite, 4=bas
} monstre ;

//tabMonstres[0][0]==ligne du monstre 0
//tabMonstres->ligne

void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte) ;
void afficherMonstres (monstre tabMonstres [], int nbMonstres) ;
void afficherLigneVide (int largeur) ;
void afficherLigneNumeros (int grille [10][10], int largeur, int l) ;
void afficherLignePleine (int largeur) ;
void afficherGrille (int grille [10][10], int largeur) ;


int deplacementsMonstresLutins (int reponse, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) ;

int depLutin(int grille[10][10], int *lLutin, int *cLutin, int deplLutin, int LargeurGrille);

int depGaucheLutin(int grille[10][10], int *lLutin, int *cLutin);
int depHautLutin(int grille[10][10], int *lLutin, int *cLutin);
int depDroiteLutin(int grille[10][10], int *lLutin, int *cLutin, int LargeurGrille);
int depBasLutin(int grille[10][10], int *lLutin, int *cLutin, int LargeurGrille);

int depMonstre(int grille [10][10], monstre tabMonstres[], int LargeurGrille, int nbMonstres);

void depGaucheMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice);
void depHautMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice);
void depDroiteMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice);
void depBasMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice);

int testMonstreProcheLutin(int grille[10][10],monstre tabMonstres [],int LargeurGrille, int indiceMonstre,int sens);

int recupDepl(monstre tabMonstres[], int indice);
int recupCol(monstre tabMonstres[], int indice);
int recupLigne(monstre tabMonstres[], int indice);

void swapLigne(monstre tabMonstres[], int indice, int val);
void swapCol(monstre tabMonstres[], int indice, int val);
void swapDepl(monstre tabMonstres[], int indice, int val);

#endif