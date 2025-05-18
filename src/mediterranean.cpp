#include "../include/mediterranean.h"

Mediterranean::Mediterranean(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
    temperature = 28.00;
}

void Mediterranean::activate() {
    active = true;
    //aggiorna last activation
}

void Mediterranean::deactivate() {
    active = false;
    //disattiva l'impianto
}

std::string Mediterranean::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Adaptive";
}