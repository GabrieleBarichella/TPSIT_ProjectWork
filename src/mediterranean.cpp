#include "../include/mediterranean.h"

Mediterranean::Mediterranean(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
    temperature = 28.00;
}

std::string Mediterranean::activate() override {
    std::string output = "";
    if(!active) {
        active = true;
        //last_activation =
        output += "L'impianto " + plant_name + " si è attivato.";
    }
    return output;
}

std::string Mediterranean::deactivate() override {
    if(active) {
        active = false;
        //last_activation =
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Mediterranean::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Adaptive";
}