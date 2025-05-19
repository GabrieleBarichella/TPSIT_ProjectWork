#include "../include/greenhouse.h"
#include <iostream>

void Greenhouse::add_implant(Implant* implant) {
    implants.push_back(implant);
};

void Greenhouse::remove_implant(Implant* implant) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i) == implant)
            implants.erase(implants.begin() + i);
};

void Greenhouse::set_implant_on(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(true);
};

void Greenhouse::set_implant_off(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(false);
};

void Greenhouse::set_implant_timers(std::string name, Clock start, Clock stop) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_timer(start,stop);
};

void Greenhouse::set_implant_timers(std::string name, Clock start) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_timer(start);
}

void Greenhouse::show(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            logMessage(clock, implants.at(i)->get_all_infos(), 0);
};

void Greenhouse::show() {
    for(int i = 0; i < implants.size(); i++)
        logMessage(clock, implants.at(i)->get_all_infos(), 0);
};

void Greenhouse::set_time(Clock time) {
    while(clock.get_total_time() <= time.get_total_time()) {
        clock++;
        for(int i = 0; i < implants.size(); i++) {
            if(implants.at(i)->get_timer_start().get_total_time() == clock.get_total_time()) {
                std::string activation_result = implants.at(i)->activate();
                if(activation_result.empty()) logMessage(clock, activation_result, 0);
            }
            else if(implants.at(i)->is_automatic() && implants.at(i)->get_timer_stop().get_total_time() == clock.get_total_time()) {
                std::string deactivation_result = implants.at(i)->deactivate();
                if(deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
            }
        }
    }
    logMessage(clock, "L'orario attuale è " + clock.tostring(), 0);
};

void Greenhouse::reset_time() {
    clock.set_total_time(0);
    for(int i = 0; i < implants.size(); i++) {
        std::string deactivation_result = implants.at(i)->deactivate();
        if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
        implants.at(i)->remove_timers();
    }
};

void Greenhouse::reset_timers() {
    for(int i = 0; i < implants.size(); i++)
        implants.at(i)->remove_timers();
};

void Greenhouse::reset_all() {
    clock.set_total_time(0);
    for(int i = 0; i < implants.size(); i++) {
        std::string deactivation_result = implants.at(i)->deactivate();
        if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
        implants.at(i)->remove_timers();
        //temperatura a 28 per i mediterranei
    }
};

void Greenhouse::remove_timer(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->remove_timers();
}

Clock Greenhouse::get_clock() {
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
    logMessage(clock, "L'orario attuale è " + clock.tostring(), 0);
    std::vector<std::string> tokens = commandParser(command);

    if (tokens.empty()) {
        throw std::invalid_argument("Errore: comando vuoto.");
    }

    const std::string &action = tokens[0];

    if (action == "set") {
        if (tokens.size() < 2) {
            throw std::invalid_argument("Errore: comando 'set' incompleto.");
        }

        const std::string &deviceName = tokens[1];

        if (deviceName == "time") {
            if (tokens.size() != 3) {
                throw std::invalid_argument("Errore: formato per 'set time' non valido. Usa: set time HH:MM");
            }
            Clock time{tokens[2]};
            set_time(time);
        } else {
            if (tokens.size() < 3) {
                throw std::invalid_argument("Errore: comando 'set' incompleto per dispositivo.");
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
            throw std::invalid_argument("Errore: comando 'rm' non valido. Usa: rm ${DEVICENAME}");
        }
        remove_timer(tokens[1]);
    } else if (action == "show") {
        if (tokens.size() == 1) {
        show();
        } else if (tokens.size() == 2) {
            show(tokens[1]);
        } else {
            throw std::invalid_argument("Errore: comando 'show' non valido. Usa: show oppure show ${DEVICENAME}");
        }

    } else if (action == "reset") {
        if (tokens.size() != 2) {
            throw std::invalid_argument("Errore: comando 'reset' non valido.");
        }

        const std::string &resetType = tokens[1];
        if (resetType == "time") {
            reset_time();
        } else if (resetType == "timers") {
            reset_timers();
        } else if (resetType == "all") {
            reset_all();
        } else {
            throw std::invalid_argument(
                    "Errore: opzione 'reset' non valida. Usa: reset time | reset timers | reset all");
        }
    } else {
        throw std::invalid_argument("Errore: comando '" + action + "' non riconosciuto.");
    }
}