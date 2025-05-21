#include "../include/desertic.h"

Desertic::Desertic(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 0;
}

std::string Desertic::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

std::string Desertic::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

std::string Desertic::get_all_infos() {
    return "Type: Desertic, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: No";
}

std::string Desertic::adaptive_behaviour(const Clock& c) {
    return "";
}