#include "../include/carnivorous.h"

Carnivorous::Carnivorous(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

void Carnivorous::activate() {
    active = true;
    //aggiorna last activation
}

void Carnivorous::deactivate() {
    active = false;
    //disattiva l'impianto
}

std::string Carnivorous::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
