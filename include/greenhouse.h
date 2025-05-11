#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <list>
#include "clock.h"
#include "implant.h"

class Greenhouse {
private:
    Clock clock;
public:
    std::list<Implant*> implants;

    void add_implant(Implant* implant);
    void remove_implant(Implant* implant);

    Greenhouse();
};

#endif
