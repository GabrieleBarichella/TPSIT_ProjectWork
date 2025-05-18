#include "../include/desertic.h"

Desertic::Desertic(const std::string& name) : Implant(name) {
    active = false;
    automatic = false;
}

void Desertic::activate() {
    active = true;
    //aggiorna last activation
}

void Desertic::deactivate() {
    active = false;
    //disattiva l'impianto
}

std::string Desertic::get_all_infos() {
    return "Type: Desertic - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: No";
}