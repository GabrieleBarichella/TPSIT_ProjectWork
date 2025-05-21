#include "../include/desertic.h"

Desertic::Desertic(const std::string& name) : Implant(name) {
    active = false;
    automatic = false;
}

std::string Desertic::activate(Clock c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
}

std::string Desertic::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Desertic::get_all_infos() {
    return "Type: Desertic - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: No";
}