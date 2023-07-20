#ifndef SERPENT_H
#define SERPENT_H
#include "positionxy.h"

class Serpent
{
public:
    //Attributs
    PositionXY carEffacement;
    PositionXY corps[100];
    PositionXY direction;
    int longueur;
    PositionXY tete;
    //Méthodes
    Serpent();
    void afficheSerpent();
    void allongeSerpent();
    void deplacerSerpent();
    void initSerpent();
    bool mortSerpent();
};

#endif // SERPENT_H
