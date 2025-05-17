#include "../include/greenhouse.h"

Greenhouse::Greenhouse() {

}

void Greenhouse::add_implant(Implant* implant) {
    implants.push_back(implant);
};

void Greenhouse::remove_implant(Implant* implant) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i) == implant)
            implants.erase(implants.begin() + i);
};

void Greenhouse::set_implant_on(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(true);
};

void Greenhouse::set_implant_off(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(false);
};

void Greenhouse::set_implant_timers(std::string name, Clock start, Clock stop) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_timer(start,stop);
};

void Greenhouse::show() {

};

void Greenhouse::set_time(Clock time) {
    while(clock.get_total_time() <= time.get_total_time()) {
        clock++;
        for(int i = 0; i < implants.size(); i++) {
            if(implants.at(i)->get_timer_start().get_total_time() == clock.get_total_time()) {
                implants.at(i)->activate();
            }
            else if(implants.at(i)->is_automatic() && implants.at(i)->get_timer_stop().get_total_time() == clock.get_total_time()) {
                implants.at(i)->deactivate();
            }
        }
    }
};

void Greenhouse::reset_time() {

};

void Greenhouse::reset_timers() {

};

void Greenhouse::reset_all() {

};