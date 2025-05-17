#ifndef IMPLANT_H
#define IMPLANT_H

#include <string>
#include "Clock.h"

class Implant {
protected:
    std::string plant_name;
    bool active = false;
    bool automatic = false;
    int frequency;
    int duration;
    double temperature;

    Clock last_activation;
    Clock timer_start;
    Clock timer_stop;

public:
    Implant(const std::string& name, int id, bool is_automatic, int freq, int dur);

    virtual ~Implant() = default;

    virtual void update(const Clock& current_time) = 0;
    virtual void turn_on(const Clock& current_time) = 0;
    virtual void turn_off(const Clock& current_time) = 0;
    virtual void print_status() const = 0;

    void set_timer(const Clock& start, const Clock& stop);
    void set_active(bool status);
    void remove_timer();
    bool has_timer() const;
    std::string get_plant_name() const;
    bool is_active() const;
    bool is_automatic() const;

    void activate();
    void deactivate();

    Clock get_last_activation();
    Clock get_timer_start();
    Clock get_timer_stop();
};

#endif
