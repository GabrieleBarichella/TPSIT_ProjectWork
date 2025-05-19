#ifndef IMPLANT_H
#define IMPLANT_H

#include <string>
#include "Clock.h"

class Implant {
protected:
    std::string plant_name;
    bool active;
    bool automatic;

    Clock last_activation;
    Clock timer_start;
    Clock timer_stop;

public:
    Implant(const std::string& name);

    virtual ~Implant() = default;

    virtual std::string activate() = 0;
    virtual std::string deactivate() = 0;
    virtual std::string get_all_infos() = 0;

    void set_timer(const Clock& start, const Clock& stop);
    void set_timer(const Clock& start);
    void set_active(bool status);

    void remove_timers();

    std::string get_plant_name() const;
    bool is_active() const;
    bool is_automatic() const;

    Clock get_last_activation();
    Clock get_timer_start();
    Clock get_timer_stop();
};

#endif
