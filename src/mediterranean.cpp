#include "../include/mediterranean.h"

Mediterranean::Mediterranean(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
    temperature = 28.00;
}

std::string Mediterranean::activate(Clock c) {
    std::string output = "";
    if(!active) {
        active = true;
        last_activation = c;
        output += "L'impianto " + plant_name + " si è attivato.";
    }
    return output;
} //da gestire temperatura

std::string Mediterranean::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
} //da gestire temperatura

std::string Mediterranean::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Adaptive";
}