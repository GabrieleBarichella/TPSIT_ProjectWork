#include "../include/greenhouse.h"
#include <iostream>

void Greenhouse::add_implant(std::unique_ptr<Implant> implant) {
    implants.push_back(std::move(implant));
};

void Greenhouse::set_implant_on(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(true);
}; //probabilmente da rivedere

void Greenhouse::set_implant_off(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_active(false);
}; //probabilmente da rivedere

void Greenhouse::set_implant_timers(std::string name, Clock start, Clock stop) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_timer(start,stop);
};

void Greenhouse::set_implant_timers(std::string name, Clock start) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->set_timer(start);
} //potrebbe dare problemi la macnanza di timer finale

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
    while(clock.get_total_time() < time.get_total_time()) {
        clock++;
        for(int i = 0; i < implants.size(); i++) {
            if(implants.at(i)->get_timer_start().get_total_time() == clock.get_total_time()) {
                std::string activation_result = implants.at(i)->activate(clock);
                if(!activation_result.empty()) logMessage(clock, activation_result, 0);
            }
            else if(implants.at(i)->is_automatic() == 1 && implants.at(i)->get_timer_stop().get_total_time() == clock.get_total_time()) {
                std::string deactivation_result = implants.at(i)->deactivate();
                if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
            }

            if(implants.at(i)->is_automatic() == 2) {
                std::string adaptive_result = implants.at(i)->adaptive_behaviour(clock);
                if(!adaptive_result.empty()) logMessage(clock, adaptive_result, 0);
            }
        }
    }
};

void Greenhouse::reset_time() {
    clock.set_total_time(0);
    for(int i = 0; i < implants.size(); i++) {
        std::string deactivation_result = implants.at(i)->deactivate();
        if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
        implants.at(i)->remove_timers();
    }
}; //non ho idea se sia giusto

void Greenhouse::reset_timers() {
    for(int i = 0; i < implants.size(); i++)
        implants.at(i)->remove_timers();
}; //non ho idea se sia giusto

void Greenhouse::reset_all() {
    clock.set_total_time(0);
    for(int i = 0; i < implants.size(); i++) {
        std::string deactivation_result = implants.at(i)->deactivate();
        if(!deactivation_result.empty()) logMessage(clock, deactivation_result, 0);
        implants.at(i)->remove_timers();
        //temperatura a 28 per i mediterranei
    }
}; //non ho idea se sia giusto

void Greenhouse::remove_timer(std::string name) {
    for(int i = 0; i < implants.size(); i++)
        if(implants.at(i)->get_plant_name() == name)
            implants.at(i)->remove_timers();
} //non ho idea se sia giusto

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