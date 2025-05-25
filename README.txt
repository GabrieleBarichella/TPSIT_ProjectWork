

Questo progetto simula una **serra intelligente** che gestisce automaticamente luce, irrigazione e ventilazione in base all'orario simulato e ai comandi dell'utente. Ogni pianta può avere impianti specifici con comportamenti intelligenti.

Tecnologie

- Linguaggio: **C++**
- IDE consigliato: **CLion**
- Modalità: **Applicazione da terminale**  
- Input: **File `comandi.txt`**

Struttura del Progetto

```
/SerraIntelligente/
├── main.cpp
├── CSerra.h / CSerra.cpp
├── CImpianto.h / CImpianto.cpp
├── CLuce.h / CLuce.cpp
├── CIrrigazione.h / CIrrigazione.cpp
├── CVentilazione.h / CVentilazione.cpp
├── COrologio.h / COrologio.cpp
├── ComandoParser.h / ComandoParser.cpp
└── comandi.txt
```

 Compilazione e Esecuzione

1. Apri il progetto con CLion o un qualsiasi ambiente C++.
2. Compila il progetto (`Build`).
3. Assicurati che il file `comandi.txt` sia presente nella directory del progetto.
4. Avvia il programma (`Run`): verranno letti ed eseguiti i comandi in sequenza.

 Esempio di file `comandi.txt`

```txt
OROLOGIO 06:00
ATTIVA IMPIANTO luce basilico
STATO IMPIANTO luce basilico
OROLOGIO 22:00
STATO IMPIANTO luce basilico
```
 Comandi Supportati

- `OROLOGIO hh:mm`  
  Imposta l'orologio della serra.

- `ATTIVA IMPIANTO [luce|irrigazione|ventilazione] [nome_pianta]`  
  Attiva un impianto specifico per una pianta.

- `DISATTIVA IMPIANTO [luce|irrigazione|ventilazione] [nome_pianta]`  
  Disattiva un impianto.

- `STATO IMPIANTO [luce|irrigazione|ventilazione] [nome_pianta]`  
  Mostra lo stato attuale dell'impianto, tenendo conto dell'orario.

 Funzionalità Intelligenti

- Gli impianti si adattano automaticamente all’orario (es. la luce si spegne di notte).
- Gli impianti usano **polimorfismo**: ogni tipo ha un comportamento diverso.
- L'orologio è gestito da una classe `COrologio` centrale.


```

