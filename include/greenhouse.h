#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <list>
#include <string>

#include "clock.h"
#include "implant.h"

class Greenhouse {
private:
    Clock clock;
public:
    std::list<Implant*> implants;

    void add_implant(Implant* implant);
    void remove_implant(Implant* implant);

    void set_implant_on(std::string n);
    void set_implant_off(std::string n);
    void set_implant_timers(std::string start, std::string stop);
    void show();
    void set_time(std::string t);
    void reset_time();
    void reset_timers();
    void reset_all();

    Greenhouse();
};

#endif
