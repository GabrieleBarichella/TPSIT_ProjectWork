#include "../include/carnivorous.h"

Carnivorous::Carnivorous(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 1;
}

std::string Carnivorous::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

std::string Carnivorous::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

std::string Carnivorous::get_all_infos() {
    return "Type: Carnivorous, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: Yes";
}

std::string Carnivorous::adaptive_behaviour(const Clock& c) {
    return "";
}
