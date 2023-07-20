#ifndef VITAMINE_H
#define VITAMINE_H
#include "positionxy.h"

class Vitamine
{
    public:
        //Attributs
        PositionXY vit;
        //Méthodes
        Vitamine();
        void afficherVitamine();
        void deplacerVitamine();
};

#endif // VITAMINE_H
