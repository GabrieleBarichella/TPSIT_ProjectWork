#include <iostream>
#include <limits>
#include "include/greenhouse.h"
#include <string>

void PrintMenu();
void CreationSystem();
void Simulation();

Greenhouse greenhouse;

int main() {
    std::srand(time(nullptr)); //per i random in Mediterranean (per temperatura)
    PrintMenu();
    CreationSystem();
    Simulation();
    return 0;
}

void PrintMenu() {
    greenhouse.logMessage(greenhouse.get_clock(),"Creazione Serra",0);
    greenhouse.logMessage(greenhouse.get_clock(),"Menu Installazione Impianti:\n"
           "1) Impianto Piante Alpine\n"
           "2) Impianto Piante Tropicali\n"
           "3) Impianto Piante Carnivore\n"
           "4) Impianto Piante Desertiche\n"
           "5) Impianto Piante Mediterranee\n"
           "0) Chiusura Menu e Avvio Simulazione",0);
}

void CreationSystem() {
    int selection;
    int counters[5] = {0};
    do {
        std::cin>>selection;
        switch (selection) {
            case 1:
                counters[0]++;
                greenhouse.logMessage(greenhouse.get_clock(), "Creazione Impianto Piante Alpine...",0);
                greenhouse.add_implant(std::make_unique<Alpine>("Alpine" + std::to_string(counters[0])));
                greenhouse.logMessage(greenhouse.get_clock(), "Pianta Alpina: Alpine" + std::to_string(counters[0]) + " Creata...", 0);
            break;
            case 2:
                counters[1]++;
                greenhouse.logMessage(greenhouse.get_clock(),"Creazione Impianto Piante Tropicali...", 0);
                greenhouse.add_implant(std::make_unique<Tropical>("Tropical" + std::to_string(counters[1])));
                greenhouse.logMessage(greenhouse.get_clock(),"Pianta Tropicale: Tropical" + std::to_string(counters[1]) + " Creata...", 0);
            break;
            case 3:
                counters[2]++;
                greenhouse.logMessage(greenhouse.get_clock(),"Creazione Impianto Piante Carnivore...", 0);
                greenhouse.add_implant(std::make_unique<Carnivorous>("Carnivorous" + std::to_string(counters[2])));
                greenhouse.logMessage(greenhouse.get_clock(),"Pianta Carnivora: Carnivorous" + std::to_string(counters[2]) + " Creata...", 0);
            break;
            case 4:
                counters[3]++;
                greenhouse.logMessage(greenhouse.get_clock(),"Creazione Impianto Piante Desertiche...", 0);
                greenhouse.add_implant(std::make_unique<Desertic>("Desertic" + std::to_string(counters[3])));
                greenhouse.logMessage(greenhouse.get_clock(),"Pianta Desertica: Desertic" + std::to_string(counters[3]) + " Creata...", 0);
            break;
            case 5:
                counters[4]++;
                greenhouse.logMessage(greenhouse.get_clock(),"Creazione Impianto Piante Mediterranee...",0 );
                greenhouse.add_implant(std::make_unique<Mediterranean>("Mediterranean" + std::to_string(counters[4])));
                greenhouse.logMessage(greenhouse.get_clock(),"Pianta Mediterranea: Mediterranean" + std::to_string(counters[4]) + " Creata...", 0);
            break;
            case 0:
                greenhouse.logMessage(greenhouse.get_clock(),"Fase di creazione conclusa, avvio simulazione...", 0);
            break;
            default:
                greenhouse.logMessage(greenhouse.get_clock(),"Scelta non valida. Selezionare un'opzione disponibile.", 1);
        }
    } while (selection != 0);
}

void Simulation() {
    bool going = true;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    greenhouse.logMessage(greenhouse.get_clock(), "Simulazione avviata.", 0);
    std::string inputCommand;
    while(going) {
        std::getline(std::cin, inputCommand);
        if(inputCommand == "exit") going = false;
        else greenhouse.processCommand(inputCommand);
    }
}
