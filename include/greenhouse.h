#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "clock.h"
#include "implant.h"
#include "alpine.h"
#include "carnivorous.h"
#include "desertic.h"
#include "mediterranean.h"
#include "tropical.h"

class Greenhouse {
private:
    Clock clock;
    std::vector<std::unique_ptr<Implant>> implants;
public:
    void add_implant(std::unique_ptr<Implant> implant);
    void remove_implant(std::unique_ptr<Implant> implant);

    void set_implant_on(std::string name);
    void set_implant_off(std::string name);
    void set_implant_timers(std::string name, Clock start, Clock stop);
    void set_implant_timers(std::string name, Clock start);
    void show(std::string name);
    void show();
    void set_time(Clock time);
    void reset_time();
    void reset_timers();
    void reset_all();

    void remove_timer(std::string name);
    Clock get_clock();

    void logMessage(const Clock &time, const std::string &message, const int &errorLevel);
    std::vector<std::string> commandParser(const std::string &command);
    void processCommand(const std::string &command);
};

#endif
