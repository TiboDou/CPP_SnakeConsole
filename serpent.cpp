#include "serpent.h"

Serpent::Serpent()
{

}


/* ===================================================================================================================================================================================================================
    Algorithme : Affichage du serpent          |                                                                                                                |
    Auteur : Thibault Douchin                  |    Notez que je ne prendrai pas la peine de détailler la mise en page dans l'algo, ce qui me semble logique    |
    Date : Février 2020                        |________________________________________________________________________________________________________________|

    DÉBUT

        Aller en (OFFSETX + carEffacement.posX, OFFSETY + carEffacement.posY)
        AFFICHER : un espace avec la couleur de fond de la console

        Pour i, entier allant de 0 jusqu'à longueur - 1 par pas de 1
            Aller en (OFFSETX + corps[i].posX, OFFSETY + corps[i].posY)
            AFFICHER : un caractère qui correspond au corps du serpent

        Aller en (OFFSETX + tete.posX, OFFSETY + tete.posY)
        AFFICHER : un caractère qui correspond à la tête du serpent
    FIN
*/


void Serpent::afficheSerpent()  //Simplement l'affichage du serpent
{
    color(0, 0);
    gotoxy(OFFSETX + carEffacement.posX, OFFSETY + carEffacement.posY);
    std::cout << " ";

    for (int i = 0; i < longueur - 1; i++)
    {
        //color(1 + rand()%(14), 0); Au début j'avais fait un serpent dont chaque partie changeait de couleur à chaque tour dans la boucle principale, mais finalement, j'ai préféré ne pas être responsable de la mort d'épileptiques potentiels
        color(0, 2);
        gotoxy(OFFSETX + corps[i].posX, OFFSETY + corps[i].posY);
        std::cout << " ";
    }
    color(0, 2);
    gotoxy(OFFSETX + tete.posX, OFFSETY + tete.posY);
    std::cout << ":";
}


/* ===================================================================================================================================================================================================================
    Algorithme : Faire grandir le corps du Serpent, attention, extrêmement complexe /!\
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        longueur <- longueur + 1
    FIN
*/


void Serpent::allongeSerpent()
{
    longueur++;
}

/* ===================================================================================================================================================================================================================
    Algorithme : Déplacer le serpent
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        SI (longueur = 1) ALORS
            carEffacementX <- teteX
            carEffacementY <- teteY
        AUTRE
            carEffacementX <- corpsX[longueur - 1]
            carEffacementY <- corpsY[longueur - 1]
        FIN SI

        corpsX[0] <- teteX
        corpsY[0] <- teteY

        Pour i allant de longueur - 1 à 0 par pas de - 1
            corpsX[i] <- corpsX[i-1]
            corpsY[i] <- corpsY[i-1]

        teteX <- teteX + directionX
        teteY <- teteY + directionY
    FIN
*/

void Serpent::deplacerSerpent() //Déplacements du serpent, on commence par la fin
{
    /*Si longueur est égale à 1 (le serpent n'a que la tête), le caractère d'effacement effacera la tête à chaque déplacement */
    if (longueur == 1)
    {
        carEffacement.posX = tete.posX;
        carEffacement.posY = tete.posY;
    }

    /*Si la longueur est différente de 1 (le serpent a donc mangé une ou plusieurs vitamines), le caractère d'effacement effacera le dernier bout du corps */
    else
    {
        carEffacement.posX = corps[longueur - 1].posX;
        carEffacement.posY = corps[longueur - 1].posY;
    }

    /*Le premier bout de corps prendra la place de la tête à chaque déplacements */
    corps[0].posX = tete.posX;
    corps[0].posY = tete.posY;

    /*Le reste du corps prend la place du bout qui le précède */
    for (int i = longueur - 1; i > 0; i--)
    {
        corps[i].posX = corps[i - 1].posX;
        corps[i].posY = corps[i - 1].posY;
    }

    /*La tête se déplace en fonction de la direction choisie par le joueur */
    tete.posX += direction.posX;
    tete.posY += direction.posY;
}


/* ===================================================================================================================================================================================================================
    Algorithme : Initialisation des attributs du serpent
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        longueur <- 1

        teteX <- 31
        teteY <- 11

        Pour i allant de 0 à 100 par pas de 1
            corpsX[i] <- 0
            corpsY[i] <- 0

        directionX <- 0
        directionY <- 0

        carEffacementX <- 30
        carEffacementY <- 11
    FIN
*/


void Serpent::initSerpent() //On initialise tous les attributs de la classe Serpent
{
    longueur = 1;

    tete.posX = 31;
    tete.posY = 11;

    for (int i = 0 ; i < 100 ; i++)
    {
        corps[i].posX = 0;
        corps[i].posY = 0;
    }

    direction.posX = 0;     //J'ai décidé que le serpent resterait statique en début de partie
    direction.posY = 0;

    carEffacement.posX = 0;
    carEffacement.posY = 0;
}


/* ===================================================================================================================================================================================================================
    Algorithme : Conditions de fin de jeu
    Auteur : Thibault Douchin
    Date : Février 2020

    DÉBUT
        SI ( teteX = bords du plateau ) ALORS
            RETOURNER 1
        AUTRE
            Pour i allant de  0 à longueur - 1 par pas de 1
                SI (teteX = corpsX[i + 1] ET teteY = corpsY[i + 1]
                    RETOURNER 1
        FIN SI
        RETOURNER 0
    FIN
*/


bool Serpent::mortSerpent() //Conditions de game over
{
    if ( tete.posX == 1 || tete.posX == 62 || tete.posY == 0 || tete.posY == 22 )
    {
        PlaySound(TEXT("oof.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 1;
    }
    else
    {
        for (int i = 0; i < longueur - 1; i++)
        {
            if (tete.posX == corps[i + 1].posX && tete.posY == corps[i + 1].posY)
            {
                PlaySound(TEXT("yoshi-ow.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return 1;
            }
        }
    }
    return 0;
}
