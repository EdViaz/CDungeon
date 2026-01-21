#include "menu.h"
#include "combattimento.h"
#include "dungeon.h"
#include "giocatore.h"
#include "salvataggio.h"
#include "utilita.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void gestisci_trucchi(Giocatore *g, NodoSalvataggio **lista);

char leggi_input_char() {
  char b[100];
  if (fgets(b, sizeof(b), stdin)) {
    b[strcspn(b, "\n")] = 0;
    if (strlen(b) == 0)
      return 0;
    if (strcmp(b, " ") == 0)
      return ' ';
    return tolower(b[0]);
  }
  return 0;
}

void mostra_menu_principale(NodoSalvataggio **lista, Giocatore *g) {
  char in;
  const char *k_code = "wwssadadba ";
  int k_idx = 0;
  int cheat = 0;

  do {
    pulisci_schermo();
    printf("=== CDungeon ===\n");
    printf("1. Nuova Partita\n2. Carica\n");
    if (cheat)
      printf("3. Trucchi\n4. Esci\n");
    else
      printf("3. Esci\n");
    printf("Scelta: ");

    in = leggi_input_char();
    if (isdigit(in)) {
      int s = in - '0';
      if (s == 1) {
        inizializza_giocatore(g);
        mostra_menu_villaggio(g, lista);
      } else if (s == 2) {
        stampa_salvataggi(*lista);
        printf("ID: ");
        int id = leggi_intero();
        if (id) {
          NodoSalvataggio *salv = carica_salvataggio(*lista, id);
          if (salv) {
            printf("Scegli operazione:\n1. Carica\n2. Elimina\n0. "
                   "Annulla\nScelta: ");
            int op = leggi_intero();
            if (op == 1) {
              *g = salv->dati_giocatore;
              mostra_menu_villaggio(g, lista);
            } else if (op == 2) {
              elimina_salvataggio(lista, id);
              getchar(); // Attendi invio per leggere messaggio
            }
          } else {
            printf("Salvataggio non trovato.\n");
            getchar();
          }
        }
      } else if (cheat && s == 3)
        gestisci_trucchi(g, lista);
      else
        return;
    } else {
      if (in == k_code[k_idx]) {
        k_idx++;
        if (k_idx == strlen(k_code)) {
          cheat = 1;
          k_idx = 0;
          printf("Trucchi Attivi!\n");
          getchar();
        }
      } else {
        k_idx = (in == 'w') ? 1 : 0;
      }
    }
  } while (1);
}

void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista) {
  do {
    pulisci_schermo();
    printf("=== Villaggio ===\nHP: %d/%d | Monete: %d\n", g->punti_vita,
           g->max_punti_vita, g->monete);
    printf(
        "1. Missioni\n2. Riposa\n3. Inventario\n4. Salva\n5. Esci\nScelta: ");
    int s = leggi_intero();

    switch (s) {
    case 1:
      mostra_menu_missione(g);
      break;
    case 2:
      g->punti_vita = g->max_punti_vita;
      printf("Riposato.\n");
      getchar();
      break;
    case 3:
      stampa_statistiche_giocatore(g);
      getchar();
      break;
    case 4:
      aggiungi_salvataggio(lista, g);
      getchar();
      break;
    case 5:
      return;
    }
  } while (1);
}

void mostra_menu_missione(Giocatore *g) {
  do {
    pulisci_schermo();
    printf("=== Missioni ===\n");
    // Flag ora sono diretti
    int f1 = g->missione_palude;
    int f2 = g->missione_magione;
    int f3 = g->missione_grotta;

    if (!f1)
      printf("1. Palude\n");
    if (!f2)
      printf("2. Magione\n");
    if (!f3)
      printf("3. Grotta\n");
    if (f1 && f2 && f3)
      printf("4. Castello Finale\n");
    printf("0. Indietro\nScelta: ");

    int s = leggi_intero();
    if (s == 0)
      return;

    if (s == 1 && !f1) {
      if (esegui_missione(g, 1, "Palude"))
        g->missione_palude = 1;
      else if (g->punti_vita <= 0)
        return;
    } else if (s == 2 && !f2) {
      if (esegui_missione(g, 2, "Magione"))
        g->missione_magione = 1;
      else if (g->punti_vita <= 0)
        return;
    } else if (s == 3 && !f3) {
      if (esegui_missione(g, 3, "Grotta"))
        g->missione_grotta = 1;
      else if (g->punti_vita <= 0)
        return;
    } else if (s == 4 && f1 && f2 && f3) {
      if (combattimento_boss_finale(g)) {
        printf("HAI VINTO IL GIOCO!\n");
        getchar();
        return;
      } else {
        printf("Game Over.\n");
        g->punti_vita = 0;
        getchar();
        return;
      }
    }
  } while (1);
}

void mostra_negozio(Giocatore *g) {
  do {
    pulisci_schermo();
    printf("=== Negozio (Monete: %d) ===\n", g->monete);
    printf("1. Pozione (4)\n2. Spada (5)\n3. Armatura (10)\n0. Esci\nScelta: ");
    int s = leggi_intero();
    if (s == 0)
      return;

    if (s == 1 && g->monete >= 4) {
      g->monete -= 4;
      g->punti_vita += lancia_dado(6);
      if (g->punti_vita > g->max_punti_vita)
        g->punti_vita = g->max_punti_vita;
      printf("Curato.\n");
    } else if (s == 2 && g->monete >= 5) {
      if (!g->ha_spada) {
        g->monete -= 5;
        g->ha_spada = 1;
        g->numero_oggetti++;
        printf("Presa Spada.\n");
      }
    } else if (s == 3 && g->monete >= 10) {
      if (!g->ha_armatura) {
        g->monete -= 10;
        g->ha_armatura = 1;
        g->numero_oggetti++;
        printf("Presa Armatura.\n");
      }
    } else
      printf("Non puoi.\n");
    getchar();
  } while (1);
}

void gestisci_trucchi(Giocatore *g, NodoSalvataggio **lista) {
  do {
    pulisci_schermo();
    stampa_salvataggi(*lista);
    printf("Inserisci ID salvataggio (0 per uscire): ");
    int id = leggi_intero();
    if (id == 0)
      return;

    NodoSalvataggio *salv = carica_salvataggio(*lista, id);
    if (!salv) {
      printf("Salvataggio non trovato.\n");
      getchar();
      continue;
    }

    // Copia i dati dal salvataggio per lavorarci
    *g = salv->dati_giocatore;

    printf("\n--- TRUCCHI (Salvataggio ID: %d) ---\n", id);
    printf("1. Max Monete (999)\n");
    printf("2. Max HP (999)\n");
    printf("3. Sblocca Tutte le Missioni\n");
    printf("4. Torna indietro\n");
    printf("Scelta: ");

    int s = leggi_intero();
    int modificato = 0;

    if (s == 1) {
      salv->dati_giocatore.monete = 999;
      modificato = 1;
      printf("Monete impostate a 999!\n");
    } else if (s == 2) {
      salv->dati_giocatore.max_punti_vita = 999;
      salv->dati_giocatore.punti_vita = 999;
      modificato = 1;
      printf("HP impostati a 999!\n");
    } else if (s == 3) {
      salv->dati_giocatore.missione_palude = 1;
      salv->dati_giocatore.missione_magione = 1;
      salv->dati_giocatore.missione_grotta = 1;
      modificato = 1;
      printf("Tutte le missioni sbloccate!\n");
    } else if (s == 4) {
      continue;
    }

    if (modificato) {
      salva_tutto_su_file(*lista);
      printf("Salvataggio aggiornato su file.\n");
      // Aggiorna anche g per riflettere le modifiche se l'utente carica subito
      *g = salv->dati_giocatore;
    }
    getchar();

  } while (1);
}
