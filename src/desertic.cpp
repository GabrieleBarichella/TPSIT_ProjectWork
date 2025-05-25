#include "../include/desertic.h"

//costruttore
Desertic::Desertic(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 0;
}

//metodo per attivare l'impianto. restituisce un messaggio di conferma di attivazione
std::string Desertic::activate(const Clock& c) {
    if(!active) {
        active = true;
        last_activation = c;
        return "L'impianto " + plant_name + " si e' attivato.";
    }
    return "";
}

//metodo per disattivare l'impianto. restituisce un messaggio di conferma di disattivazione
std::string Desertic::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

//ritorna le informazioni principali
std::string Desertic::get_all_infos() {
    return "Type: Desertic, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: No";
}

std::string Desertic::adaptive_behaviour(const Clock& c) {
    return "";
}