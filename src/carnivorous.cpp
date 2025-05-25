#include "../include/carnivorous.h"

//costruttore
Carnivorous::Carnivorous(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 1;
}

//metodo per attivare l'impianto. restituisce un messaggio di conferma di attivazione
std::string Carnivorous::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

//metodo per disattivare l'impianto. restituisce un messaggio di conferma di disattivazione
std::string Carnivorous::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

//ritorna le informazioni principali
std::string Carnivorous::get_all_infos() {
    return "Type: Carnivorous, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: Yes";
}

std::string Carnivorous::adaptive_behaviour(const Clock& c) {
    return "";
}
