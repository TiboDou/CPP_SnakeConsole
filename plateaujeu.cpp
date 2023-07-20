#include "plateaujeu.h"

PlateauJeu::PlateauJeu()
{

}


/* ===================================================================================================================================================================================================================
    Algorithme : Affichage du plateau
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        AFFICHER : "Score"

        Pour i allant de 0 à 61 par pas de 1
            AFFICHER : "peu importe"
            AFFICHER : "peu importe mais plus bas"

        Pour i allant de 0 à 21 par pas de 1
            AFFICHER : "peu importe"
            AFFICHER : "peu importe mais plus à droite"
    FIN

*/


void PlateauJeu::affichePlateau()
{
    color(3, 0);
    gotoxy(11, 1);
    std::cout << "Score :";

    gotoxy(54, 1);
    std::cout << "Temps restant : ";

    color(13, 0);
    gotoxy(19, 1);
    std::cout << "0";
    gotoxy(70, 1);
    std::cout << "245";

    color(11, 3);
    for ( int i = 0; i < 62; i++ )
    {
        gotoxy(OFFSETX + i + 1, OFFSETY);
        std::cout << " ";
        gotoxy(OFFSETX + i + 1, OFFSETY + 22);
        std::cout << " ";
    }

    for ( int i = 0; i < 22; i++ )
    {
        gotoxy(OFFSETX + 1, OFFSETY + i);
        std::cout << " ";
        gotoxy(OFFSETX + 62, OFFSETY + i);
        std::cout << " ";
    }

    color(5, 0);
    gotoxy(OFFSETX + 63, OFFSETY + 22);
    std::cout << "/";

    gotoxy(OFFSETX + 63, OFFSETY - 1);
    std::cout << "/";

    gotoxy(OFFSETX + 1, OFFSETY - 1);
    std::cout << "/";

    for ( int i = 1; i < 63; i++)
    {
        gotoxy(OFFSETX + 1 + i, OFFSETY - 2);
        std::cout << "_";
    }

    for ( int i = -1; i < 22; i++)
    {
        gotoxy(OFFSETX + 64, OFFSETY + i);
        std::cout << "|";
    }

}
