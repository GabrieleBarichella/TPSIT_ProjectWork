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

std::string Implant::get_plant_name() const {
    return plant_name;
};

bool Implant::is_active() const {
    return active;
};

bool Implant::is_automatic() const {
    return automatic;
};

void Implant::activate() {
    active = true;
};

void Implant::deactivate() {
    active = false;
};

std::string Implant::get_all_infos() {
    std::string infos[2];
    infos[0] = active ? "Yes" : "No";
    infos[1] = automatic ? "Yes" : "No";
    return "Active: " + infos[0] + " - Automatic: " + infos[1];
}

Clock Implant::get_last_activation() {
    return last_activation;
};

Clock Implant::get_timer_start() {
    return timer_start;
};

Clock Implant::get_timer_stop() {
    return timer_stop;
};
