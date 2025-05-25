#include "../include/greenhouse.h"

#include <iostream>
#include <sstream>

void Greenhouse::add_implant(std::unique_ptr<Implant> implant) {
    implants.push_back(std::move(implant));
    //trasferire l’impianto nel vector senza copiarlo. trasferisce "ownership"
    //"ownership": responsabilità di gestire la vita di un oggetto dinamico
}

void Greenhouse::set_implant_on(const std::string& name) {
    //auto: deduce automaticamente il tipo unique_ptr<Implant>
    //&: significa che non stai facendo una copia ma leggendo un riferimento
    //const: garantisce che non puoi modificare l’oggetto puntato all’interno del ciclo
    for(const auto & implant : implants) {
        if(implant->get_plant_name() == name) {
            if(implant->get_implant_type() != 2) { //se non è adattivo
                std::string activation_result = implant->activate(clock);
                if(!activation_result.empty()) logMessage(clock, activation_result, 0);
                else logMessage(clock, "L'impianto e' gia' acceso.", 0);
            }
            else logMessage(clock, "Non puoi accendere manualmente questo tipo di impianto.",1);
            return;
        }
    }
    logMessage(clock, "Impianto richiesto non trovato.", 1);
}

void Greenhouse::set_implant_off(const std::string& name) {
    for(const auto & implant : implants) {
        if(implant->get_plant_name() == name) {
            if(implant->get_implant_type() != 2) {
                std::string deactivation_result = implant->deactivate();
                if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
                else logMessage(clock, "L'impianto e' gia' spento.", 0);
            }
            else logMessage(clock, "Non puoi disattivare manualmente questo tipo di impianto.",1);
            return;
        }
    }
    logMessage(clock, "Impianto richiesto non trovato.", 1);
}

void Greenhouse::set_implant_timers(const std::string& name, Clock start, Clock stop) {
    for(const auto & implant : implants)
        if(implant->get_plant_name() == name) {
            if(implant->get_implant_type() == 1) {
                implant->set_timer(start,stop);
                logMessage(clock, "Operazione riuscita.", 0);
            }
            else logMessage(clock, "Non puoi inserire un sistema automatico in questo tipo di impianto.", 1);
            return;
        }
    logMessage(clock, "Impianto richiesto non trovato.", 1);
}

void Greenhouse::set_implant_timers(const std::string& name, Clock start) {
    for(const auto & implant : implants)
        if(implant->get_plant_name() == name) {
            if(implant->get_implant_type() != 2) {
                implant->set_timer(start);
                logMessage(clock, "Operazione riuscita.", 0);
                return;
            }
            logMessage(clock, "Non puoi settare un timer per questo tipo di impianto.", 1);
        }
    logMessage(clock, "Impianto richiesto non trovato.", 1);
}

void Greenhouse::show(const std::string& name) {
    for(const auto & implant : implants)
        if(implant->get_plant_name() == name)
            logMessage(clock, implant->get_all_infos(), 0);
}

void Greenhouse::show() {
    for(const auto & implant : implants)
        logMessage(clock, implant->get_all_infos(), 0);
}

void Greenhouse::set_time(Clock time) {
    //scorre in avanti il timer finchè non raggiunge il tempo richiesto
    while(clock.get_total_time() < time.get_total_time()) {
        clock++;
        //per ogni minuto trascorso verifica che ogni tipo di impianto faccia quello che deve
        for(const auto & implant : implants) {
            if(implant->get_timer_start().get_total_time() == clock.get_total_time()) {
                std::string activation_result = implant->activate(clock);
                if(!activation_result.empty()) logMessage(clock, activation_result, 0);
            }
            else if(implant->get_implant_type() == 1 && implant->get_timer_stop().get_total_time() == clock.get_total_time()) {
                std::string deactivation_result = implant->deactivate();
                if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
            }

            //gestione della temperatura per impianti adattivi
            if(implant->get_implant_type() == 2) {
                std::string adaptive_result = implant->adaptive_behaviour(clock);
                if(!adaptive_result.empty()) logMessage(clock, adaptive_result, 0);
            }
        }
    }
}

void Greenhouse::reset_time() {
    clock.set_total_time(0);
    for(const auto & implant : implants) {
        if(implant->get_implant_type() != 2) {
            std::string deactivation_result = implant->deactivate();
            if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
            implant->remove_timers();
        }
    }
    logMessage(clock, "Impianti spenti (tranne adattivi), timer rimossi.", 0);
}

void Greenhouse::reset_timers() {
    for(const auto & implant : implants)
        implant->remove_timers();
    logMessage(clock, "Timer rimossi.", 0);
}

void Greenhouse::reset_all() {
    reset_time();
}

void Greenhouse::remove_timer(const std::string& name) {
    for(const auto & implant : implants)
        if(implant->get_plant_name() == name) {
            implant->remove_timers();
            logMessage(clock, "Timer rimosso.", 0);
            return;
        }
    logMessage(clock, "Impianto richiesto non trovato.", 1);
}

Clock Greenhouse::get_clock() const {
    return clock;
}

void Greenhouse::logMessage(const Clock &time, const std::string &message, const int& errorLevel) {
    if (errorLevel == 0)
        std::cout << "[" << time.tostring() << "]\t" << message << std::endl;
    else if (errorLevel == 1)
        std::cerr << "[" << time.tostring() << "]\t" << message << std::endl;
}

std::vector<std::string> Greenhouse::commandParser(const std::string &command) {
    std::vector<std::string> tokens;
    std::istringstream ss(command);
    std::string token;

    bool isDeviceName = false;
    std::string deviceName;

    while (ss >> token) {
        if (isDeviceName) {
            if (token == "on" || token == "off" || token.find(':') != std::string::npos) {
                if (!deviceName.empty()) {
                    tokens.push_back(deviceName);
                    deviceName.clear();
                }
                isDeviceName = false;
            }
        }

        if (token == "set" || token == "rm" || token == "show") {
            tokens.push_back(token);
            isDeviceName = true;
            continue;
        }

        if (isDeviceName) {
            if (!deviceName.empty()) {
                deviceName += " ";
            }
            deviceName += token;
        } else {
            tokens.push_back(token);
        }
    }

    if (!deviceName.empty()) {
        tokens.push_back(deviceName);
    }

    return tokens;
}

void Greenhouse::processCommand(const std::string &command) {
    std::vector<std::string> tokens = commandParser(command);

    if (tokens.empty()) {
        logMessage(clock, "Errore: comando vuoto.", 1);
        return;
    }

    const std::string &action = tokens[0];

    if (action == "set") {
        if (tokens.size() < 2) {
            logMessage(clock,"Errore: comando 'set' incompleto.",1);
            return;
        }

        const std::string &deviceName = tokens[1];

        if (deviceName == "time") {
            if (tokens.size() != 3) {
                logMessage(clock, "Errore: formato per 'set time' non valido. Usa: set time HH:MM", 1);
                return;
            }
            Clock time{tokens[2]};
            set_time(time);
        } else {
            if (tokens.size() < 3) {
                logMessage(clock, "Errore: comando 'set' incompleto per dispositivo.", 1);
                return;
            }

            const std::string &operation = tokens[2];

            if (operation == "on") {
                set_implant_on(deviceName);
            } else if (operation == "off") {
                set_implant_off(deviceName);
            } else {
                Clock start{operation};
                if (tokens.size() == 4) {
                    Clock stop{tokens[3]};
                    set_implant_timers(deviceName, start, stop);
                } else {
                    set_implant_timers(deviceName, start);
                }

            }
        }

    } else if (action == "rm") {
        if (tokens.size() != 2) {
            logMessage(clock,"Errore: comando 'rm' non valido. Usa: rm ${DEVICENAME}",1);
            return;
        }
        remove_timer(tokens[1]);
    } else if (action == "show") {
        if (tokens.size() == 1) {
        show();
        } else if (tokens.size() == 2) {
            show(tokens[1]);
        } else {
            logMessage(clock,"Errore: comando 'show' non valido. Usa: show oppure show ${DEVICENAME}",1);
            return;
        }

    } else if (action == "reset") {
        if (tokens.size() != 2) {
            logMessage(clock,"Errore: comando 'reset' non valido.",1);
            return;
        }

        const std::string &resetType = tokens[1];
        if (resetType == "time") {
            reset_time();
        } else if (resetType == "timers") {
            reset_timers();
        } else if (resetType == "all") {
            reset_all();
        } else {
            logMessage(clock, "Errore: opzione 'reset' non valida. Usa: reset time | reset timers | reset all", 1);
            return;
        }
    } else {
        logMessage(clock, "Errore: comando '" + action + "' non riconosciuto.", 1);
        return;
    }
    logMessage(clock, "L'orario corrente e' " + clock.tostring(), 0);
}