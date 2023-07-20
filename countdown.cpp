#include "countdown.h"

 /* =================================================================================================================================================================================================================,
|                   J'ai choisi de faire un compte à rebours et non pas juste de renvoyer le temps qu'aurait duré une partie car cela me permet de contourner la taille restreinte du                                |
|                               corps du serpent. En effet, limiter le corps à 100 caractères sur un plateau de +1000 cases est un appel au crime.                                                                   |
 \__________________________________________________________________________________________________________________________________________________________________________________________________________________*/

Countdown::Countdown()
{

}


/* ====================================================================================================================================================================================================================
    Algorithme : Établir le début de la partie
    Auteur : Thibault Douchin
    Date : Mars 2020

    DÉBUT
        debut <- appel de la fonction time
    FIN
*/

void Countdown::setTimer()
{
    debut = time(0);    //time renvoie le temps écoulé depuis le 01/01/1970 à 00:00:00, cela permet d'établir le lancement de la partie
}


/* ====================================================================================================================================================================================================================
    Algorithme : Affichage compte à rebours
    Auteur : Thibault Douchin
    Date : Mars 2020

    DÉBUT
        tempsÉcoulé <- 180 -(appel de la fonction time - debut)
        AFFICHER : "Temps restant : " ,tempsÉcoulé,
    FIN
*/

void Countdown::displayCountdown()                  //Fonction qui permet l'affichage du compte à rebours
{
     /*=======================================================================================================================,
    |    Ci-dessous, on établit la différence de temps écoulé entre l'instant t dans la boucle ET au lancement de la partie   |
    |                       On soustrait la différence à 245 pour faire un compte à rebours                                   |
     \_______________________________________________________________________________________________________________________*/

    timeElapsed = 245 - (time(0) - debut);

    gotoxy(70, 1);
    color(13, 0);
    std::cout << timeElapsed;

    if (timeElapsed == 99 || timeElapsed == 9)
    {
        std::cout << " ";
    }
}
