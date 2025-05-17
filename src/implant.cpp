#include "../include/implant.h"

Implant::Implant(const std::string& name, int id, bool is_automatic, int freq, int dur) {

};

void Implant::set_timer(const Clock& start, const Clock& stop) {
    timer_start = start;
    timer_stop = stop;
    automatic = true;
}

void Implant::set_active(bool status) {
    active = status;
}

void Implant::remove_timer() {

};

bool Implant::has_timer() const {

};

std::string Implant::get_plant_name() const {

};

bool Implant::is_active() const {

};

bool Implant::is_automatic() const {

};

void Implant::activate() {
    active = true;
    //stampa stato attivo, gestisci temperatura,
};

void Implant::deactivate() {
    active = false;
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
