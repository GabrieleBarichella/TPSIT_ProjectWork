#include "../include/alpine.h"

Alpine::Alpine(const std::string& name) : Implant(name) {
    active = false;
    automatic = 1;
}

std::string Alpine::activate(Clock c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
}

std::string Alpine::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Alpine::get_all_infos() {
    return "Type: Alpine - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
