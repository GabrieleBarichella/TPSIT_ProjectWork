#include "../include/carnivorous.h"

Carnivorous::Carnivorous(const std::string& name) : Implant(name) {
    active = false;
    automatic = true;
}

std::string Carnivorous::activate() {
    if(!active) {
        active = true;
        //last_activation =
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Carnivorous::deactivate() {
    if(active) {
        active = false;
        //last_activation =
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Carnivorous::get_all_infos() {
    return "Type: Carnivorous - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: Yes";
}
