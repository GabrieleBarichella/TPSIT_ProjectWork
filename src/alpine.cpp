#include "../include/alpine.h"

Alpine::Alpine(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

void Alpine::activate() {
    active = true;
    //aggiorna last activation
}

void Alpine::deactivate() {
    active = false;
    //disattiva l'impianto
}

std::string Alpine::get_all_infos() {
    return "Type: Alpine - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
