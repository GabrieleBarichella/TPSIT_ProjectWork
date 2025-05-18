#include <iostream>
#include "include/greenhouse.h"
#include <string>

void PrintMenu();
void CreationSystem();
void Simulation();

Greenhouse greenhouse;

int main() {
    PrintMenu();
    CreationSystem();
    Simulation();
    return 0;
}

void PrintMenu() {
    std::cout<<"\nCreazione Serra\n"<<std::endl;
    std::cout<<"Menu Installazione Impianti:\n"
           "1) Impianto Piante Alpine\n"
           "2) Impianto Piante Tropicali\n"
           "3) Impianto Piante Carnivore\n"
           "4) Impianto Piante Desertiche\n"
           "5) Impianto Piante Mediterranee\n"
           "0) Chiusura Menu e Avvio Simulazione"<<std::endl;
}

void CreationSystem() {
    int selection;
    do {
        std::cin>>selection;
        switch (selection) {
            case 1:
                std::cout<<"Creazione Impianto Piante Alpine..."<<std::endl;
                Alpine* newAlpine = new Alpine("a");
                greenhouse.add_implant(newAlpine);
            break;
            case 2:
                std::cout<<"Creazione Impianto Piante Tropicali..."<<std::endl;
                Tropical* newTropical = new Tropical("a");
                greenhouse.add_implant(newTropical);
            break;
            case 3:
                std::cout<<"Creazione Impianto Piante Carnivore..."<<std::endl;
                Carnivorous* newCarnivorous = new Carnivorous("a");
                greenhouse.add_implant(newCarnivorous);
            break;
            case 4:
                std::cout<<"Creazione Impianto Piante Desertiche..."<<std::endl;
                Desertic* newDesertic = new Desertic("a");
                greenhouse.add_implant(newDesertic);
            break;
            case 5:
                std::cout<<"Creazione Impianto Piante Mediterranee..."<<std::endl;
                Mediterranean* newMediterranean = new Mediterranean("a");
                greenhouse.add_implant(newMediterranean);
            break;
            case 0:
                std::cout<<"Fase di creazione conclusa, avvio simulazione..."<<std::endl;
            break;
            default:
                std::cout<<"Scelta non valida. Selezionare un'opzione disponibile."<<std::endl;
        }
    } while (selection != 0);
}

void Simulation() {
    greenhouse.logMessage(greenhouse.get_clock(), "Simulazione avviata.", 0);
    std::string inputCommand;
    while(true) {
        std::cin>>inputCommand;
        greenhouse.processCommand(inputCommand);
    }
}
