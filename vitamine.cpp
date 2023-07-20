#include "vitamine.h"

Vitamine::Vitamine()
{
    srand((int)time(0));    //Fonction permettant de générer des nombres pseudo-aléatoires
}


/* ===================================================================================================================================================================================================================
    Algorithme : Déplacer vitamine
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        vitamineX <- 2 + appel de la fonction rand % 60
        vitamineY <- 2 + appel de la fonction rand % 20
    FIN
*/


void Vitamine::deplacerVitamine()
{
    vit.posX = 2 + rand()%(60);     //Pour que la vitamine apparaisse dans le plateau
    vit.posY = 2 + rand()%(20);
}


/* ===================================================================================================================================================================================================================
    Algorithme : Afficher la vitamine
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        Aller à l'emplacement (OFFSETX + vitamineX, OFFSETY + vitamineY)
        AFFICHER : "un caractère"
    FIN
*/


void Vitamine::afficherVitamine()
{
    color(14, 0);
    gotoxy(OFFSETX + vit.posX, OFFSETY + vit.posY);
    std::cout << "v";
}
