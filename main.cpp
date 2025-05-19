#include <iostream>
#include <limits>
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
} //spaziatura eccessiva dopo il caporiga

void CreationSystem() {
    int selection;
    do {
        std::cin>>selection;
        switch (selection) {
            case 1:
                std::cout<<"Creazione Impianto Piante Alpine..."<<std::endl;
                greenhouse.add_implant(std::make_unique<Alpine>("Alpine"));
            break;
            case 2:
                std::cout<<"Creazione Impianto Piante Tropicali..."<<std::endl;
                greenhouse.add_implant(std::make_unique<Tropical>("Tropical"));
            break;
            case 3:
                std::cout<<"Creazione Impianto Piante Carnivore..."<<std::endl;
                greenhouse.add_implant(std::make_unique<Carnivorous>("Carnivorous"));
            break;
            case 4:
                std::cout<<"Creazione Impianto Piante Desertiche..."<<std::endl;
                greenhouse.add_implant(std::make_unique<Desertic>("Desertic"));
            break;
            case 5:
                std::cout<<"Creazione Impianto Piante Mediterranee..."<<std::endl;
                greenhouse.add_implant(std::make_unique<Mediterranean>("Mediterranean"));
            break;
            case 0:
                std::cout<<"Fase di creazione conclusa, avvio simulazione..."<<std::endl;
            break;
            default:
                std::cout<<"Scelta non valida. Selezionare un'opzione disponibile."<<std::endl;
        }
    } while (selection != 0);
} //da sistemare l'interfaccia utente e dare conferma di creazione riuscita (+ nome pianta)

void Simulation() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    greenhouse.logMessage(greenhouse.get_clock(), "Simulazione avviata.", 0);
    std::string inputCommand;
    for(int i = 0; i < 5; i++) {
        std::getline(std::cin, inputCommand);
        greenhouse.processCommand(inputCommand);
    }
} //potenziali errori con il getline
