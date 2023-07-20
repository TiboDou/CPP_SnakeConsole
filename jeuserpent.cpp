#include "jeuserpent.h"

JeuSerpent::JeuSerpent()
{
    parametres();
}

/* =================================================================================================================================================================================================================
    Algorithme : Boucle principale du jeu Snake             |                                                                                                                |
    Auteur : Christian Delvarre                             |               Notez que je ne prendrais pas la peine de détailler les ajouts "cosmétiques"                     |
    Complété par : Thibault Douchin                         |________________________________________________________________________________________________________________|
    Date : Février / Mars 2020

    Variable : car : caractère

    DÉBUT
        RÉPÉTER
            appel de la fonction affichePlateau
            appel de la fonction initSerpent
            appel de la fonction deplacerVitamine
            appel de la fonction afficheSerpent
            vitesse <- 150

            Attente d'une frappe
            appel de la fonction setTimer

            RÉPÉTER
                appel de la fonction afficherVitamine

                SI ( teteX = vitamineX ET teteY = vitamineY )
                    ALORS
                        appel de la fonction allongeSerpent
                        appel de la fonction deplacerVitamine
                        appel de la fonction deplacementVitamines

                        SI ( vitesse > 51 )
                            ALORS vitesse  <- vitesse -3
                        FIN SI

                    AFFICHER : ,longueur - 1,
                FIN SI

                appel de la fonction deplacerSerpent
                appel de la fonction afficheSerpent

                SI ( appel de la fonction kbhit )
                    ALORS
                        car <- appel de la fonction getch
                        SI car = z OU car = Z
                            ALORS directionX <- 0
                                  directionY <- -1
                        SINON
                            SI ( car = q OU car = Q )
                                ALORS directionX <- -1
                                      directionY <- 0
                            SINON
                                SI ( car = s OU car = S )
                                    ALORS directionX <- 0
                                          directionY <- 1
                                SINON
                                    SI ( car = d OU car = D )
                                        ALORS directionX <- 1
                                              directionY <- 0
                                    FIN SI
                                FIN SI
                            FIN SI
                        FIN SI
                FIN SI

                appel de la fonction displayCountdown
                appel de la fonction Sleep
            JUSQU'A ( appel de la fonction mortSerpent = 1 OU timeElapsed = 0 )

            appel de la fonction tableauScore
            AFFICHER : "Voulez-vous recommencer : "

            appel de la fonction clear
        JUSQU'A (  car = n OU car = N )
    FIN
*/

void JeuSerpent::jouerJeuSerpent()
{
    clear();
    char car;

    do
    {
        plateau.affichePlateau();
        boa.initSerpent();
        appat.deplacerVitamine();
        vitesse = 150;
        boa.afficheSerpent();
        color(13, 0);

        do
        {
            gotoxy(30, 9);
            color(13, 0);
            std::cout << "Appuyez sur une touche";
            gotoxy(1, 1);
            Sleep(800);
            gotoxy(30, 9);
            color(0, 0);
            std::cout << "Appuyez sur une touche";
            gotoxy(1, 1);
            Sleep(1000);

        } while ( !kbhit() );

                                                                            //La fonction PlaySound permet de jouer un son au format .wav            |      Cela a demandé l'ajout de la librairie -lwinmm
        PlaySound(TEXT("countdown.wav"), NULL, SND_FILENAME | SND_ASYNC);   //https://docs.microsoft.com/en-us/previous-versions/dd743680(v%3Dvs.85) |                      dans le .pro
        timer.setTimer();
        Sleep(1000);

        do
        {
            appat.afficherVitamine();

            if ( boa.tete.posX == appat.vit.posX && boa.tete.posY == appat.vit.posY )
            {
                PlaySound(TEXT("yoshi.wav"), NULL, SND_FILENAME | SND_ASYNC);

                boa.allongeSerpent();
                appat.deplacerVitamine();
                deplacementVitamines();

                if ( vitesse > 50 )     //Si la vitesse est de 51, on ne diminue plus car le jeu devient difficilement jouable
                {
                    vitesse -= 4;
                }

                gotoxy(19, 1);
                color(13, 0);
                std::cout << boa.longueur - 1;      //Affichage du score du joueur mis à jour à chaque vitamine
            }

            boa.deplacerSerpent();
            boa.afficheSerpent();

            gotoxy(90, 9);

            if( kbhit() )
            {
                car = getch();
                switch (car)
                {
                    case 'z' :
                    case 'Z' :
                        boa.direction.posX = 0;
                        boa.direction.posY = -1;
                        break;
                    case 'q' :
                    case 'Q' :
                        boa.direction.posX = -1;
                        boa.direction.posY = 0;
                        break;
                    case 's' :
                    case 'S' :
                        boa.direction.posX = 0;
                        boa.direction.posY = 1;
                        break;
                    case 'd' :
                    case 'D' :
                        boa.direction.posX = 1;
                        boa.direction.posY = 0;
                        break;
                 }
            }

            timer.displayCountdown();       //Affichage du compte à rebours à chaque tour dans la boucle principale
            gotoxy(1,1);
            Sleep(vitesse);

         } while ( (boa.mortSerpent() != 1 ) && timer.timeElapsed > 0);    //On boucle jusqu'à une erreur du joueur ou la fin du compte à rebours

       Sleep(500);
       color(3, 0);
       gotoxy(26,28);
       std::cout <<"Voulez-vous recommencer (o/n) ? : ";

       do {
           car = getch();

           if ( car == 'o' || car == 'O')
           {
               jouerJeuSerpent();
           }
       } while (car != 'N' && car != 'n' && car != 'o' && car != 'o');

       clear(); //J'ai mis un deuxième clear parce que j'ai eu quelques fois un problème avec l'affichage, le board n'était pas nettoyé

    } while ( car != 'n' && car != 'N' );

}


/* ===================================================================================================================================================================================================================
    Algorithme : Placement des vitamines            |                                                                                                                       |
    Auteur : Thibault Douchin                       |               J'ai constaté que les vitamines s'affichaient parfois sous le corps du Serpent,                         |
    Date : Mars 2020                                |                                       j'ai donc essayé d'y remédier                                                   |
                                                    |_______________________________________________________________________________________________________________________|
    DÉBUT
        Pour i, entier allant de 0 à longueur - 1 par pas de 1
            RÉPÉTER
                SI ( vitamineX = teteX ET vitamineY = teteY )
                    ALORS appel de la fonction déplacerVitamine
                FIN SI
                SI ( vitamineX = corpsX[i] ET vitamineY = corpsY[i]
                    ALORS appel de la fonction déplacerVitamine
                FIN SI
            JUSQU'A ( (vitamineX <> teteX ET vitamineY <> teteY) ET (vitamineX <> corpsX[i] ET vitamineY <> corpsY[i]) )
    FIN

*/


void JeuSerpent::deplacementVitamines()
{
    for (int i = 0; i < boa.longueur - 1; i++)
    {
        do
        {
            if ( appat.vit.posX == boa.tete.posX && appat.vit.posY == boa.tete.posY )   //Si la vitamine se place sur la tête, on la déplace
            {
                appat.deplacerVitamine();
            }

            if ( appat.vit.posX == boa.corps[i].posX && appat.vit.posY == boa.corps[i].posY ) //Si la vitamine se place sur le corps, on la déplace
            {
                appat.deplacerVitamine();
            }

        } while ( (appat.vit.posX == boa.tete.posX && appat.vit.posY == boa.tete.posY) || (appat.vit.posX == boa.corps[i].posX && appat.vit.posY == boa.corps[i].posY) );
    }
}


/* ===================================================================================================================================================================================================================
    Algorithme : Notice ?
    Auteur : Thibault Douchin
    Date : Mars 2020

    DÉBUT
        Il s'agit juste d'afficher les touches, j'ai fait ça surtout pour préserver l'affichage de mon jeu.
        Rien à expliquer je pense.
    FIN
*/


void JeuSerpent::parametres()
{
    clear();
    color(3, 0);
    gotoxy(20, 1);
    std::cout << "Jeu du Serpent par Thibault Douchin";

    gotoxy(15, 5);
    std::cout << "La configuration des touches est la suivante : ";

    gotoxy(65, 4);
    std::cout << "Z";
    gotoxy(63, 5);
    std::cout << "Q";
    gotoxy(65, 6);
    std::cout << "S";
    gotoxy(67, 5);
    std::cout << "D";

    gotoxy(17, 7);
    std::cout << "Appuyez sur une touche pour lancer le jeu ";

    do {
        gotoxy(18, 1);
        color(1 + rand()%(14), 0);
        std::cout << char(186);
        gotoxy(18, 2);
        std::cout << char(186);
        gotoxy(18, 3);
        std::cout << char(200);
        gotoxy(56, 1);
        std::cout << char(186);
        gotoxy(56, 2);
        std::cout << char(186);
        gotoxy(56, 3);
        std::cout << char(188);

        for (int i = 0; i < 37; i++)
        {
            gotoxy(19 + i, 3);
            std::cout << char(205) ;
        }
    } while ( !kbhit() );

    getch();

    jouerJeuSerpent();
}
