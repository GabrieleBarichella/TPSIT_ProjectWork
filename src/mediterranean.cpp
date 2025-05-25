#include "../include/mediterranean.h"

//costruttore
Mediterranean::Mediterranean(const std::string& name) : Implant(name) {
    active = false;
    implant_type = 2;
    temperature = 28.00;
}

//avvisa quando si accende
std::string Mediterranean::activate(const Clock& c) {
    std::string output = "";
    if(!active) {
        active = true;
        last_activation = c;
        output += "L'impianto " + plant_name + " si e' attivato.";
    }
    return output;
}

//avvisa quando si spegne
std::string Mediterranean::deactivate() {
    if(active) {
        active = false;
        return "L'impianto " + plant_name + " si e' disattivato.";
    }
    return "";
}

//comportamento adattivo che gestisce accensioni e spegnimenti
std::string Mediterranean::adaptive_behaviour(const Clock& c) {
    if(!active) {
        //RAND_MAX è una costante che indica il massimo che può essere restituito da rand().
        if(temperature >= 25) temperature -= 0.01 + (std::rand() / (double)RAND_MAX) * (0.05 - 0.01);
        else return activate(c);
    }
    else {
        if(temperature <= 28) temperature += 0.75 + (std::rand() / (double)RAND_MAX) * (1 - 0.75);
        else return deactivate();
    }
    return "";
}

//ritorna le informazioni principlai
std::string Mediterranean::get_all_infos() {
    return "Type: Mediterranean, Name: " + plant_name + ", Active: " + (active ? "Yes" : "No") + ", Automatic: Adaptive";
}