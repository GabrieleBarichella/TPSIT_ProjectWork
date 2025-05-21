#include "../include/implant.h"

Implant::Implant(const std::string& name) : plant_name{name}, active{false}, implant_type{0} {}

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
    timer_start.set_total_time(-1);
    timer_stop.set_total_time(-1);
}

std::string Implant::get_plant_name() const {
    return plant_name;
};

bool Implant::is_active() const {
    return active;
};

int Implant::get_implant_type() const {
    return implant_type;
};

Clock Implant::get_last_activation() const {
    return last_activation;
};

Clock Implant::get_timer_start() const {
    return timer_start;
};

Clock Implant::get_timer_stop() const {
    return timer_stop;
};

