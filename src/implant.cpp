#include "../include/implant.h"

Implant::Implant(const std::string& name) : plant_name(name) {}

void Implant::set_timer(const Clock& start, const Clock& stop) {
    timer_start = start;
    timer_stop = stop;
}

void Implant::set_timer(const Clock& start) {
    timer_start = start;
}

void Implant::set_active(bool status) {
    active = status;
}

void Implant::remove_timers() {
    timer_start.set_hour(-1);
    timer_stop.set_minute(-1);
}

std::string Implant::get_plant_name() const {
    return plant_name;
};

bool Implant::is_active() const {
    return active;
};

int Implant::is_automatic() const {
    return automatic;
};

Clock Implant::get_last_activation() {
    return last_activation;
};

Clock Implant::get_timer_start() {
    return timer_start;
};

Clock Implant::get_timer_stop() {
    return timer_stop;
};

std::string Implant::adaptive_behaviour(Clock c) {
    return "";
}

