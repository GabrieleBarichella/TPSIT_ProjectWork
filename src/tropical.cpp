#include "../include/tropical.h"

Tropical::Tropical(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

void Tropical::activate() {
    active = true;
    //aggiorna last activation
}

void Tropical::deactivate() {
    active = false;
    //disattiva l'impianto
}

std::string Tropical::get_all_infos() {
    return "Type: Tropical - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}