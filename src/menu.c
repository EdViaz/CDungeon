#include "menu.h"
#include "utilita.h"
#include <stdio.h>
#include <stdlib.h>

void mostra_menu_principale(NodoSalvataggio **lista_salvataggi, Giocatore *giocatore_corrente) {
    int scelta;
    do {
        pulisci_schermo();
        printf("=== CDungeon ===\n");
        printf("1. Nuova Partita\n");
        printf("2. Carica Salvataggio\n");
        printf("3. Esci\n");
        printf("Seleziona un'opzione [1-3]: ");
        
        scelta = leggi_intero();

        switch (scelta) {
            case 1:
                printf("Inizio nuova partita...\n");
                // Qui chiameremo la logica per inizializzare il gioco
                // inizializza_giocatore(giocatore_corrente);
                // mostra_menu_villaggio(giocatore_corrente, lista_salvataggi);
                printf("Premi Invio per continuare...");
                getchar();
                break;
            case 2:
                printf("Caricamento salvataggi non ancora implementato.\n");
                printf("Premi Invio per continuare...");
                getchar();
                break;
            case 3:
                printf("Arrivederci!\n");
                break;
            default:
                // Controllo trucchi (Konami code) andrebbe qui
                printf("Opzione non valida.\n");
                getchar();
                break;
        }
    } while (scelta != 3);
}

void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista_salvataggi) {
    printf("Menu Villaggio Placeholder\n");
}

void mostra_menu_missione(Giocatore *g) {
    printf("Menu Missione Placeholder\n");
}
