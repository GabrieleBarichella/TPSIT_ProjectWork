#include "../include/tropical.h"

//costruttore
Tropical::Tropical(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 1;
}

//gestione attivazione con messaggio di conferma
std::string Tropical::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

//disattivazione con messaggio di conferma
std::string Tropical::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

//ritorna informazioni principali
std::string Tropical::get_all_infos() {
    return "Type: Tropical, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: Yes";
}

std::string Tropical::adaptive_behaviour(const Clock& c) {
    return "";
}