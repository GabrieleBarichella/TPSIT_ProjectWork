#include <iostream>
#include "include/greenhouse.h"

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
            break;
            case 2:
                std::cout<<"Creazione Impianto Piante Tropicali..."<<std::endl;
            break;
            case 3:
                std::cout<<"Creazione Impianto Piante Carnivore..."<<std::endl;
            break;
            case 4:
                std::cout<<"Creazione Impianto Piante Desertiche..."<<std::endl;
            break;
            case 5:
                std::cout<<"Creazione Impianto Piante Mediterranee..."<<std::endl;
            break;
            case 0:
                std::cout<<"Fase di creazione conclusa, avvio simulazione..."<<std::endl;
            break;
            default:
                std::cout<<"Scelta non valida. Selezionare un'opzione disponibile."<<std::endl;
        }
    } while (selection != 0);
} //Mancante: aggiunta effettiva degli elementi alla serra

void Simulation() {
    std::string inputCommand;

    //Mancante: codice di Maniglio per l'ingresso dei comandi

    std::string parsedCommand; //Placeholder
}