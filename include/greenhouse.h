#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <list>
#include "clock.h"
#include "implant.h"

class Greenhouse {
private:
    std::list<Implant*> implants;
    Clock clock;
public:
    void add_implant(Implant* implant);
    void remove_implant(Implant* implant);

    Greenhouse();
};

#endif
