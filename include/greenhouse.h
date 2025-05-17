#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <string>
#include <vector>

#include "clock.h"
#include "implant.h"

class Greenhouse {
private:
    Clock clock;
    std::vector<Implant*> implants;
public:
    void add_implant(Implant* implant);
    void remove_implant(Implant* implant);

    void set_implant_on(std::string name);
    void set_implant_off(std::string name);
    void set_implant_timers(std::string name, Clock start, Clock stop);
    void show();
    void set_time(Clock time);
    void reset_time();
    void reset_timers();
    void reset_all();

    Greenhouse();
};

#endif
