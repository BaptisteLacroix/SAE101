#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"

int deplacementsMonstresLutins(int reponse, int *nbTours, int grille[10][10], int largeurGrille, int nbMonstres, monstre tabMonstres[], int *lLutin, int *cLutin, int lPorte, int cPorte)
{
    (*nbTours)++;
    if (depLutin(grille, lLutin, cLutin, reponse, largeurGrille) == 2)
        return 2;
    else if (*lLutin == lPorte && *cLutin == cPorte)
        return 1;
    else if (depMonstre(grille, tabMonstres, largeurGrille, nbMonstres) == 2)
        return 2;
    else
        return 0;
}

int depGaucheLutin(int grille[10][10], int *lLutin, int *cLutin)
{
    if (*cLutin == 0)                               // La colonne du Lutin vaut 0 donc il est collé à la bordure il ne bouge pas
        return 0;                                   // On renvoie 0, car le Lutin n'est pas rentre dans un monstre
    else if (grille[*lLutin][*cLutin - 1] == 2)     // Si a gauche du Lutin il y a un Monstre
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *cLutin -= 1;                               // colonne du lutin -1 pour le faire aller a gauche
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 2;                                   // On renvoie 2 car le Lutin est rentre en contact avec un monstre.
    }
    else                                            // Sinon On le déplace a gauche
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *cLutin -= 1;                               // colonne du lutin -1 pour le faire aller a gauche
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 0;                                   // On renvoie 0 car le Lutin n'est pas rentre dans un monstre
    }
}

int depHautLutin(int grille[10][10], int *lLutin, int *cLutin)
{
    if (*lLutin == 0)                               // La ligne du Lutin vaut 0 donc il est collé à la bordure il ne bouge pas
        return 0;                                   // On renvoie 0, car le Lutin n'est pas rentre dans un monstre
    else if (grille[*lLutin - 1][*cLutin] == 2)     // Si en haut du Lutin il y a un Monstre
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *lLutin -= 1;                               // ligne du lutin -1 pour le faire aller en haut
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 2;                                   // On renvoie 2 car le Lutin est rentre en contact avec un monstre.
    }
    else                                            // Sinon On le déplace en haut
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *lLutin -= 1;                               // ligne du lutin -1 pour le faire aller en haut
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 0;                                   // On renvoie 0 car le Lutin n'est pas rentre dans un monstre
    }
}

int depDroiteLutin(int grille[10][10], int *lLutin, int *cLutin, int LargeurGrille)
{
    if (LargeurGrille - *cLutin == 1)               // La colonne du Lutin vaut 1 donc il est collé à la bordure il ne bouge pas
        return 0;                                   // On renvoie 0, car le Lutin n'est pas rentre dans un monstre
    else if (grille[*lLutin][*cLutin + 1] == 2)     // Si a droite du Lutin il y a un Monstre
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *cLutin += 1;                               // colonne du lutin +1 pour le faire aller a droite
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 2;                                   // On renvoie 2 car le Lutin est rentre en contact avec un monstre.
    }
    else                                            // Sinon On le déplace a droite
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *cLutin += 1;                               // colonne du lutin +1 pour le faire aller a droite
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 0;                                   // On renvoie 0 car le Lutin n'est pas rentre dans un monstre
    }
}

int depBasLutin(int grille[10][10], int *lLutin, int *cLutin, int LargeurGrille)
{
    if (LargeurGrille - *lLutin == 1)               // La ligne du Lutin vaut 1 donc il est collé à la bordure il ne bouge pas
        return 0;                                   // On renvoie 0, car le Lutin n'est pas rentre dans un monstre
    else if (grille[*lLutin + 1][*cLutin] == 2)     // Si en bas du Lutin il y a un Monstre
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *lLutin += 1;                               // ligne du lutin +1 pour le faire aller en bas
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 2;                                   // On renvoie 2, car le Lutin est rentre dans un monstre
    }
    else                                            // Sinon On le déplace en bas
    {
        grille[*lLutin][*cLutin] = 0;               // Case du Lutin mise a 0
        *lLutin += 1;                               // ligne du lutin -1 pour le faire aller en bas
        grille[*lLutin][*cLutin] = 1;               // On met a jour la grille avec le Lutin deplacé
        return 0;                                   // On renvoie 0 car le Lutin n'est pas rentre dans un monstre
    }
}

int depLutin(int grille[10][10], int *lLutin, int *cLutin, int deplLutin, int LargeurGrille)
{
    if (deplLutin == 1)                             // Si le lutin va vers la gauche
    {
        return depGaucheLutin(grille, lLutin, cLutin);
    }
    else if (deplLutin == 2)                        // Si le lutin va vers le haut
    {
        return depHautLutin(grille, lLutin, cLutin);
    }
    else if (deplLutin == 3)                        // Si le lutin va vers la droite
    {
        return depDroiteLutin(grille, lLutin, cLutin, LargeurGrille);
    }
    else                                            // Si le lutin va vers le bas
    {
        return depBasLutin(grille, lLutin, cLutin, LargeurGrille);
    }
}


void depGaucheMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice)
{
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 0; // On remplace l'ancienne case du monstre par un 0 qui représente un vide
    if (((grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] != 0) &&
        (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 0) &&
        recupCol(tabMonstres, indice) != LargeurGrille - 1) ||
        (recupCol(tabMonstres, indice) == 0 && grille[recupLigne(tabMonstres, indice)][1] == 0)) // Si le monstre se situe à la colonne 0 ou que celui ci a un monstre  ou une porte sur son chemin
    {
        swapCol(tabMonstres, indice, 1);  // on va donc à droite
        swapDepl(tabMonstres, indice, 3); // on change la direction de base du monstre
    }
    else if (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 2 && grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 1)
    {
        *fin = 2;
        *b = 1;
    }
    else if ((grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 2) &&
             (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 2)) // Si il y a un monstre des deux côtés du monstres
    {
        *b = 1; // On ne change rien et on dit que le monstre a bougé
    }
    else // sinon, celui ci a donc le champ libre vers la gauche
    {
        if (recupCol(tabMonstres, indice) == 0 || (recupCol(tabMonstres, indice) == LargeurGrille - 1 && grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 2))
        {
            *b = 1; // On ne change rien et on dit que le monstre a bougé
        }
        else
        {
            swapCol(tabMonstres, indice, -1); // alors on se deplace simplement vers la gauche
        }
    }
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 2; // On remplace la case actuelle du monstre par un 2, qui représente le monstre dans l'affichage de la grille
    *b = 1;                                                                      // On arrete le déplacement pour ce monstre
}


void depHautMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice)
{
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 0; // On remplace l'ancienne case du monstre par un 0 qui représente un vide

    if ((recupLigne(tabMonstres, indice) == 0 && grille[1][recupCol(tabMonstres, indice)] == 0) ||
        ((grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] != 0) &&
        (grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 0))) // Si le monstre se situe à la colonne 0 ou que celui ci a un monstre  ou une porte sur son chemin
    {
        swapLigne(tabMonstres, indice, 1); // on va donc en bas
        swapDepl(tabMonstres, indice, 4);  // on change la direction de base du monstre
    }
    else if (grille[recupLigne(tabMonstres, indice)-1][recupCol(tabMonstres, indice)] == 2 &&
        grille[recupLigne(tabMonstres, indice)+1][recupCol(tabMonstres, indice)] == 1)
    {
        *fin = 2;
        *b = 1;
    }
    else if (((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 2)) ||
            ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 3) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 2)) ||
            ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 3))) // Si il y a un monstre des deux côtés du monstres ou la sortie
    {
        *b = 1; // On ne change rien et on dit que le monstre a bougé
    }
    else // sinon, celui ci a donc le champ libre vers le haut
    {
        if (recupLigne(tabMonstres, indice) == 0 ||
        (recupLigne(tabMonstres, indice) == LargeurGrille - 1 &&
        grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 2))
        {
            *b = 1; // On ne change rien et on dit que le monstre a bougé
        }
        else
        {
            swapLigne(tabMonstres, indice, -1); // alors on se deplace simplement vers le haut
        }
    }
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 2;
    // On remplace la case actuelle du monstre par un 2, qui représente le monstre dans l'affichage de la grille
    *b = 1;
}

void depDroiteMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice)
{
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 0;

    if ((recupCol(tabMonstres, indice) == LargeurGrille - 1 && grille[recupLigne(tabMonstres, indice)][LargeurGrille - 2] == 0) ||  //Si le monstre si situe au max de la grille et qu'il a de la place vers l'autre côté
        ((grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] != 0) &&
        (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 0))) // Si le monstre est censé passer sur la porte et que celui ci n'est pas au max de la grille) //Et qu'il a de la place à gauche, en prenant en compte qu'il n'est pas aux bornes de la grille
    {
        swapCol(tabMonstres, indice, -1); // alors on se deplace simplement vers la gauche
        swapDepl(tabMonstres, indice, 1); // Et on change son sens de direction
    }
    else if (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 2 && grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 1)
    {
        *fin = 2;
        *b = 1;
    }
    else if ((grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) - 1] == 2) &&
             (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 2)) // Si il y a un monstre des deux côtés du monstres
    {
        *b = 1; // On ne change rien et on dit que le monstre a bougé
    }
    else
    {
        if (recupCol(tabMonstres, indice) == LargeurGrille - 1 || (recupCol(tabMonstres, indice) == LargeurGrille - 1 &&
            grille[recupLigne(tabMonstres, indice)][(recupCol(tabMonstres, indice)) + 1] == 2) ||
            (recupCol(tabMonstres, indice) == 0 && grille[recupLigne(tabMonstres, indice)][(recupCol(tabMonstres, indice)) + 1] == 2))
        {
            *b = 1;
        }
        else if (grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice) + 1] == 0)
        {
            swapCol(tabMonstres, indice, 1);
        }
    }
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 2;
    *b = 1;
}

void depBasMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int *b, int *fin, int indice)
{
     grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 0;

    if (((recupLigne(tabMonstres, indice) == LargeurGrille - 1) && (grille[LargeurGrille - 2][recupCol(tabMonstres, indice)] == 0)) ||
        ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 3) &&
        (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 0)) ||
        ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2) &&
         (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 0)))
    {
        swapLigne(tabMonstres, indice, -1);
        swapDepl(tabMonstres, indice, 2);
    }
    else if (grille[recupLigne(tabMonstres, indice)+1][recupCol(tabMonstres, indice)] == 2 &&
            grille[recupLigne(tabMonstres, indice)-1][recupCol(tabMonstres, indice)] == 1)
    {
        *fin = 2;
        *b = 1;
    }
    else if (((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 2)) ||
            ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 3)) ||
             ((grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 3) &&
             (grille[recupLigne(tabMonstres, indice) - 1][recupCol(tabMonstres, indice)] == 2)) ||
            (recupLigne(tabMonstres, indice) == LargeurGrille - 1 ||
             (recupCol(tabMonstres, indice) == LargeurGrille - 1 &&
              grille[recupLigne(tabMonstres, indice)+1][recupCol(tabMonstres, indice)] == 2)))
    {
        *b = 1;
    }
    else
    {
        if (recupLigne(tabMonstres, indice) == 0 && grille[recupLigne(tabMonstres, indice) + 1][recupCol(tabMonstres, indice)] == 2)
        {
            *b = 1;
        }
        else
        {
            swapLigne(tabMonstres, indice, 1);
        }
    }
    grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 2;
    *b = 1;
}


int depMonstre(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int nbMonstres)
{
    int testSiMonstreProcheLutin;
    int fin = 0;
    int indice = 0;
    while ((indice < nbMonstres) && (fin != 2))
    {
        int b = 0; // Variable qui sert à déterminer si le monstre a déjà bouger dans son tour
        // Deplacement Vers le la gauche
        testSiMonstreProcheLutin = testMonstreProcheLutin(grille, tabMonstres, LargeurGrille, indice, 1); // On teste si le monstre se dirige vers un lutin
        if (recupDepl(tabMonstres, indice) == 1 && testSiMonstreProcheLutin == 0 && b == 0)               // Si le monstre se déplace à gauche et qu'il n'y a pas de lutin dans sa direction
        {
            depGaucheMonstre(grille, tabMonstres, LargeurGrille, &b, &fin, indice);
        }
        else if (recupDepl(tabMonstres, indice) == 1 && testSiMonstreProcheLutin == 1 && b == 0) // Or si celui ci possede un lutin dans son sens de direction
        {
            grille[recupLigne(tabMonstres, indice)][recupCol(tabMonstres, indice)] = 2;
            fin = 2; // On regle  le parametre de fin a 2 (qui represente la fin du monstre mange lutin)
            b = 1;   // On arrete le déplacement pour ce monstre
        }
        // Deplacement Vers le haut
        testSiMonstreProcheLutin = testMonstreProcheLutin(grille, tabMonstres, LargeurGrille, indice, 2); // On teste si le monstre se dirige vers un lutin
        if (recupDepl(tabMonstres, indice) == 2 && testSiMonstreProcheLutin == 0 && b == 0)               // Si le monstre se déplace à gauche et qu'il n'y a pas de lutin dans sa direction
        {
            depHautMonstre(grille, tabMonstres, LargeurGrille, &b, &fin, indice);
        }

        else if (recupDepl(tabMonstres, indice) == 2 && testSiMonstreProcheLutin == 1 && b == 0) // Or si celui ci possede un lutin dans son sens de direction
        {
            fin = 2; // On regle le parametre de fin a 2 (qui represente la fin du monstre mange lutin)
            b = 1;   // On arrete le déplacement pour ce monstre
        }
        // Deplacement Vers la droite
        testSiMonstreProcheLutin = testMonstreProcheLutin(grille, tabMonstres, LargeurGrille, indice, 3); // On teste si le monstre se dirige vers un lutin
        if (recupDepl(tabMonstres, indice) == 3 && testSiMonstreProcheLutin == 0 && b == 0)
        {
            depDroiteMonstre(grille, tabMonstres, LargeurGrille, &b, &fin, indice);
        }
        else if (recupDepl(tabMonstres, indice) == 3 && testSiMonstreProcheLutin == 1 && b == 0)
        {
            fin = 2;
            b = 1;
        }
        // Deplacement Vers le bas
        testSiMonstreProcheLutin = testMonstreProcheLutin(grille, tabMonstres, LargeurGrille, indice, 4); // On teste si le monstre se dirige vers un lutin
        if (recupDepl(tabMonstres, indice) == 4 && testSiMonstreProcheLutin == 0 && b == 0)
        {
            depBasMonstre(grille, tabMonstres, LargeurGrille, &b, &fin, indice);
        }
        else if (recupDepl(tabMonstres, indice) == 4 && testSiMonstreProcheLutin == 1 && b == 0)
        {
            fin = 2;
            b = 1;
        }
        indice++;
    }
    return fin;
}

int testMonstreProcheLutin(int grille[10][10], monstre tabMonstres[], int LargeurGrille, int indiceMonstre, int sens)
{
    //* 1=gauche, 2=haut, 3=droite, 4=bas
    if (sens == 1 && grille[recupLigne(tabMonstres, indiceMonstre)][recupCol(tabMonstres, indiceMonstre) - 1] == 1 &&
    recupCol(tabMonstres, indiceMonstre) != LargeurGrille-1)
    {
        return 1;
    }
    if (sens == 2 && grille[(recupLigne(tabMonstres, indiceMonstre)) - 1][recupCol(tabMonstres, indiceMonstre)] == 1 &&
    recupLigne(tabMonstres, indiceMonstre) != LargeurGrille-1)
    {
        return 1;
    }
    if (sens == 3 && grille[recupLigne(tabMonstres, indiceMonstre)][recupCol(tabMonstres, indiceMonstre) + 1] == 1 &&
    recupCol(tabMonstres, indiceMonstre) != LargeurGrille-1)
    {
        return 1;
    }
    if (sens == 4 && grille[(recupLigne(tabMonstres, indiceMonstre)) + 1][recupCol(tabMonstres, indiceMonstre)] == 1 &&
    recupLigne(tabMonstres, indiceMonstre) != LargeurGrille-1)
    {
        return 1;
    }
    else
        return 0;
}