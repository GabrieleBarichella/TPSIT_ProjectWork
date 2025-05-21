#include "../include/carnivorous.h"

Carnivorous::Carnivorous(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

std::string Carnivorous::activate(Clock c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
}

std::string Carnivorous::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Carnivorous::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
