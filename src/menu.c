#include "menu.h"
#include "giocatore.h"
#include "gioco.h" // Per costanti o funzioni di gioco se necessarie
#include "salvataggio.h"
#include "utilita.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Forward declarations
void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista_salvataggi);
void mostra_menu_missione(Giocatore *g);
void gestisci_trucchi(
    Giocatore *g); // Da implementare se richiesto nel menu principale

// Funzione helper per leggere input in modo sicuro e gestire Konami code
char leggi_input_menu_principale() {
  char buffer[100];
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Rimuovi newline
    buffer[strcspn(buffer, "\n")] = 0;

    // Se l'input è vuoto (solo invio), ritorna un carattere nullo o speciale
    if (strlen(buffer) == 0)
      return 0;

    // Se è ' ' (spazio), ritornalo
    if (strcmp(buffer, " ") == 0)
      return ' ';

    // Ritorna il primo carattere minuscolo per facilitare i controlli
    return tolower(buffer[0]);
  }
  return 0;
}

void mostra_menu_principale(NodoSalvataggio **lista_salvataggi,
                            Giocatore *giocatore_corrente) {
  char input;
  // Sequenza Konami: w w s s a d a d b a ' '
  const char *konami_sequence =
      "wwssadadba "; // Nota: l'ultimo carattere è spazio
  int konami_index = 0;
  int trucchi_sbloccati = 0;

  do {
    pulisci_schermo();
    printf("=== CDungeon ===\n");
    printf("1. Nuova Partita\n");
    printf("2. Carica Salvataggio\n");
    if (trucchi_sbloccati) {
      printf("3. Trucchi\n");
      printf("4. Esci\n");
    } else {
      printf("3. Esci\n");
    }

    int max_scelta = trucchi_sbloccati ? 4 : 3;
    printf("Seleziona un'opzione [1-%d]: ", max_scelta);

    input = leggi_input_menu_principale();

    // Controllo Menu Standard
    if (isdigit(input)) {
      int scelta = input - '0';

      if (scelta == 1) {
        printf("Inizio nuova partita...\n");
        inizializza_giocatore(giocatore_corrente);
        printf("Premi Invio per entrare nel villaggio...");
        getchar(); // Attendi invio
        mostra_menu_villaggio(giocatore_corrente, lista_salvataggi);
        konami_index = 0; // Reset konami
      } else if (scelta == 2) {
        stampa_salvataggi(*lista_salvataggi);
        printf("Inserisci ID salvataggio da selezionare (0 per annullare): ");
        int id = leggi_intero();
        if (id != 0) {
          NodoSalvataggio *s = carica_salvataggio(*lista_salvataggi, id);
          if (s) {
            printf("Seleziona un'opzione per il salvataggio %d:\n", id);
            printf("1. Carica\n");
            printf("2. Elimina\n");
            printf("Seleziona opzione [1-2]: ");
            int sub_scelta = leggi_intero();
            if (sub_scelta == 1) {
              *giocatore_corrente = s->dati_giocatore;
              printf("Salvataggio caricato!\n");
              printf("Premi Invio per continuare...");
              getchar(); // Consuma il newline rimasto da leggi_intero
              mostra_menu_villaggio(giocatore_corrente, lista_salvataggi);
            } else if (sub_scelta == 2) {
              printf(
                  "Sei sicuro di voler eliminare definitivamente il salvataggio? "
                  "[s/n]: ");
              char conferma;
              scanf(" %c", &conferma);
              getchar(); // Consuma newline
              if (tolower(conferma) == 's') {
                elimina_salvataggio(lista_salvataggi, id);
              }
            }
          } else {
            printf("Salvataggio non trovato.\n");
            printf("Premi Invio per continuare...");
            getchar();
          }
        } else {
          // Consuma newline se necessario
          getchar();
        }
        konami_index = 0;
      } else if (trucchi_sbloccati && scelta == 3) {
        // Menu Trucchi
        gestisci_trucchi(giocatore_corrente);
        konami_index = 0;
      } else if ((!trucchi_sbloccati && scelta == 3) ||
                 (trucchi_sbloccati && scelta == 4)) {
        printf("Arrivederci!\n");
        return; // Esci dalla funzione e quindi dal gioco
      } else {
        printf("Opzione non valida.\n");
      }
    } else {
      // Controllo Konami Code
      // Se l'input corrisponde al carattere atteso nella sequenza
      if (input == konami_sequence[konami_index]) {
        konami_index++;
        if (konami_index == strlen(konami_sequence)) {
          printf("\n*** TRUCCHI SBLOCCATI! ***\n");
          trucchi_sbloccati = 1;
          konami_index = 0;
          printf("Premi Invio per aggiornare il menu...");
          getchar();
        }
      } else {
        konami_index = 0; // Reset se sbaglia sequenza
        // Controllo se il carattere inserito è l'inizio della sequenza (w) per
        // ripartire subito
        if (input == 'w') {
          konami_index = 1;
        }
      }
    }

  } while (1);
}

void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista_salvataggi) {
  int scelta;
  do {
    pulisci_schermo();
    printf("=== Menu del Villaggio ===\n");
    printf("1. Intraprendi una missione\n");
    printf("2. Riposati (Ripristina HP)\n");
    printf("3. Inventario\n");
    printf("4. Salva la partita\n");
    printf("5. Esci al Menu Principale\n");
    printf("Seleziona un'opzione [1-5]: ");

    scelta = leggi_intero();

    switch (scelta) {
    case 1:
      mostra_menu_missione(g);
      break;
    case 2:
      if (g->punti_vita == g->max_punti_vita) {
        printf("Hai già le forze al massimo!\n");
        printf("Premi Invio per continuare...");
        getchar();
        break;
      }else{
      g->punti_vita = g->max_punti_vita;
      printf("Ti sei riposato e hai recuperato le forze! (%d HP)\n",
             g->punti_vita);
      printf("Premi Invio per continuare...");
      getchar();
      break;
    }
    case 3:
      stampa_statistiche_giocatore(g);
      printf("Premi Invio per continuare...");
      getchar();
      break;
    case 4:
      aggiungi_salvataggio(lista_salvataggi, g);
      printf("Premi Invio per continuare...");
      getchar();
      break;
    case 5: {
      char conferma;
      printf("Stai uscendo dal gioco ricordati di salvare la partita per non "
             "perdere i tuoi progressi.\n");
      printf("Sei sicuro di voler procedere? [s/n]: ");
      scanf(" %c", &conferma);
      getchar(); // Consuma newline
      if (tolower(conferma) == 's') {
        return; // Torna al menu principale
      }
    } break;
    default:
      printf("Scelta non valida.\n");
      break;
    }
  } while (1);
}

void mostra_menu_missione(Giocatore *g) {
  pulisci_schermo();
  printf("=== Menu di Selezione Missione ===\n");
  printf("(Funzionalità da implementare dai tuoi amici!)\n");
  printf("1. Palude Putrescente\n");
  printf("2. Magione Infestata\n");
  printf("3. Grotta di Cristallo\n");
  printf("Seleziona... (premi invio per tornare indietro)\n");
  getchar();
}

void gestisci_trucchi(Giocatore *g) {
  int scelta;
  do {
    pulisci_schermo();
    printf("=== Menu Trucchi ===\n");
    printf("1. Setta Monete a 999\n");
    printf("2. Setta HP a 999\n");
    printf("3. Sblocca Missione Finale (Placeholder)\n");
    printf(
        "4. Seleziona un salvataggio da modificare (Placeholder)\n"); // Opzione
                                                                      // extra
                                                                      // menzionata
                                                                      // nelle
                                                                      // specifiche
    printf("5. Torna indietro\n");
    printf("Scelta: ");
    scelta = leggi_intero();

    switch (scelta) {
    case 1:
      g->monete = 999;
      printf("Monete impostate a 999!\n");
      break;
    case 2:
      g->max_punti_vita = 999;
      g->punti_vita = 999;
      printf("HP impostati a 999!\n");
      break;
    case 3:
      printf("Missione finale sbloccata (logica da implementare)!\n");
      break;
    case 4:
      // Qui servirebbe logica per selezionare un salvataggio specifico dalla
      // lista
      printf("Modifica salvataggi non implementata in questo menu rapido.\n");
      break;
    case 5:
      return;
    }
    printf("Premi Invio per continuare...");
    getchar();
  } while (1);
}
