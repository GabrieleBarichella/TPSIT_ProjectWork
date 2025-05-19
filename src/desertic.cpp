#include "../include/desertic.h"

Desertic::Desertic(const std::string& name) : Implant(name) {
    active = false;
    automatic = false;
}

std::string Desertic::activate() {
    if(!active) {
        active = true;
        //last_activation =
        return "L'impianto " + plant_name + " si è attivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Desertic::deactivate() {
    if(active) {
        active = false;
        //last_activation =
        return "L'impianto " + plant_name + " si è disattivato.";
    }
    return "";
} //da gestire il Last Activation

std::string Desertic::get_all_infos() {
    return "Type: Desertic - Name: " + plant_name + " - Active: " + (active ? "Yes" : "No") + " -  Automatic: No";
}