#ifndef JEUSERPENT_H
#define JEUSERPENT_H
#include "serpent.h"
#include "plateaujeu.h"
#include "vitamine.h"
#include "countdown.h"

class JeuSerpent
{
public:
    //Attributs
    int vitesse;
    //Méthodes
    void jouerJeuSerpent();
    void deplacementVitamines();
    void parametres();
    JeuSerpent();
private:
    Serpent boa;
    PlateauJeu plateau;
    Vitamine appat;
    Countdown timer;
};

#endif // JEUSERPENT_H
