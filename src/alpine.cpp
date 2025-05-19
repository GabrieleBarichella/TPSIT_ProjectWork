#include "../include/alpine.h"

Alpine::Alpine(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

std::string Alpine::activate() {
    if(!active) {
        active = true;
        //last_activation =
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Alpine::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Alpine::get_all_infos() {
    return "Type: Alpine - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
