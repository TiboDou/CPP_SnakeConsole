#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include "positionxy.h"

class Countdown
{
public:
    //Attributs :
    time_t debut;
    time_t timeElapsed;
    //Méthodes :
    void setTimer();
    void displayCountdown();
    Countdown();
};

#endif // COUNTDOWN_H
