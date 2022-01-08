#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"


int recupLigne(monstre tabMonstres[], int indice)
{
    return tabMonstres[indice].ligne;
}
int recupCol(monstre tabMonstres[], int indice)
{
    return tabMonstres[indice].col;
}
int recupDepl(monstre tabMonstres[], int indice)
{
    return tabMonstres[indice].depl;
}
void swapLigne(monstre tabMonstres[], int indice, int val)
{
    tabMonstres[indice].ligne += val;
}
void swapCol(monstre tabMonstres[], int indice, int val)
{
    tabMonstres[indice].col += val;
}
void swapDepl(monstre tabMonstres[], int indice, int val)
{
    tabMonstres[indice].depl = val;
}
