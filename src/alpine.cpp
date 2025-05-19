#include "../include/alpine.h"

Alpine::Alpine(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

std::string Alpine::activate() override {
    if(!active) {
        active = true;
        //last_activation =
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
}

std::string Alpine::deactivate() override {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
}

std::string Alpine::get_all_infos() override {
    return "Type: Alpine - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
