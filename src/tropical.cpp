#include "../include/tropical.h"

Tropical::Tropical(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

std::string Tropical::activate(Clock c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
}

std::string Tropical::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Tropical::get_all_infos() {
    return "Type: Tropical - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}