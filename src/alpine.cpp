#include "../include/alpine.h"

//costruttore
Alpine::Alpine(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 1;
}

//metodo per attivare l'impianto. restituisce un messaggio di conferma di attivazione
std::string Alpine::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

//metodo per disattivare l'impianto. restituisce un messaggio di conferma di disattivazione
std::string Alpine::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

//restituisce le informazioni principali sull'impianto
std::string Alpine::get_all_infos() {
    return "Type: Alpine, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: Yes";
}

std::string Alpine::adaptive_behaviour(const Clock& c) {
    return "";
}

