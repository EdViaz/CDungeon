#include "dungeon.h"
#include "combattimento.h"
#include "menu.h"
#include "utilita.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_negozio(Giocatore *g); // Extern

Entita genera_entita_missione(int tipo, int dado) {
  Entita e;
  e.tipo = ENTITA_NESSUNA;
  sprintf(e.nome, "Nulla");
  e.danno = 0;
  e.punti_vita = 0;
  e.colpo_fatale = 0;
  e.ricompensa_monete = 0;
  e.e_boss = 0;

  // Configurazione entita in base a missione e dado
  // Missione 1: Palude
  if (tipo == 1) {
    if (dado == 1) {
      sprintf(e.nome, "Cane Selvaggio");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 10;
      e.colpo_fatale = 2;
      e.danno = 1;
    } else if (dado == 2) {
      sprintf(e.nome, "Goblin");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 15;
      e.colpo_fatale = 3;
      e.danno = 2;
      e.ricompensa_monete = 2;
    } else if (dado == 3) {
      sprintf(e.nome, "Scheletro");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 20;
      e.colpo_fatale = 4;
      e.danno = 2;
      e.ricompensa_monete = 4;
    } else if (dado == 4) {
      sprintf(e.nome, "Orco");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 25;
      e.colpo_fatale = 3;
      e.danno = 4;
      e.ricompensa_monete = 6;
    } else if (dado == 5) {
      sprintf(e.nome, "Acquitrino Velenoso");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = lancia_dado(6);
    } else if (dado == 6) {
      sprintf(e.nome, "Generale Orco");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 30;
      e.colpo_fatale = 6;
      e.danno = 3;
      e.ricompensa_monete = 12;
      e.e_boss = 1;
    }
  }
  // Missione 2: Magione
  else if (tipo == 2) {
    if (dado == 1) {
      sprintf(e.nome, "Botola Buia");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = 3;
    } else if (dado == 2) {
      sprintf(e.nome, "Pipistrello");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 5;
      e.colpo_fatale = 2;
      e.danno = 2;
      e.ricompensa_monete = 1;
    } else if (dado == 3) {
      sprintf(e.nome, "Zombie");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 20;
      e.colpo_fatale = 3;
      e.danno = 2;
      e.ricompensa_monete = 2;
    } else if (dado == 4) {
      sprintf(e.nome, "Fantasma");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 15;
      e.colpo_fatale = 5;
      e.danno = 2;
      e.ricompensa_monete = 4;
    } else if (dado == 5) {
      sprintf(e.nome, "Vampiro Superiore");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 40;
      e.colpo_fatale = 4;
      e.danno = 4;
      e.ricompensa_monete = 7;
      e.e_boss = 1;
    } else if (dado == 6) {
      sprintf(e.nome, "Demone Custode");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 50;
      e.colpo_fatale = 4;
      e.danno = 6;
      e.ricompensa_monete = 10;
    }
  }
  // Missione 3: Grotta
  else if (tipo == 3) {
    if (dado == 1) {
      sprintf(e.nome, "Stanza Vuota");
      e.tipo = ENTITA_VUOTA;
    } else if (dado == 2) {
      sprintf(e.nome, "Cristalli Cadenti");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = 2;
    } else if (dado == 3) {
      sprintf(e.nome, "Ponte Pericolante");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = 0;
    } else if (dado == 4) {
      sprintf(e.nome, "Forziere Misterioso");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = 2;
      e.ricompensa_monete = 10;
    } else if (dado == 5) {
      sprintf(e.nome, "Rupe scoscesa");
      e.tipo = ENTITA_TRAPPOLA;
      e.danno = lancia_dado(6);
    } else if (dado == 6) {
      sprintf(e.nome, "Drago Antico");
      e.tipo = ENTITA_NEMICO;
      e.punti_vita = 60;
      e.colpo_fatale = 5;
      e.danno = 10;
      e.ricompensa_monete = 12;
      e.e_boss = 1;
    }
  }
  return e;
}

int esegui_missione(Giocatore *g, int tipo_missione,
                    const char *nome_missione) {
  int target = (tipo_missione == 1) ? 3 : 1;
  int progress = 0;
  int stanze = 0;
  int completata = 0;

  do {
    pulisci_schermo();
    printf("=== %s ===\n", nome_missione);
    if (tipo_missione == 1)
      printf("Obiettivo: Sconfiggi %d Generali Orco (%d/%d)\n", target,
             progress, target);
    else if (tipo_missione == 2)
      printf("Obiettivo: Sconfiggi Vampiro e prendi Chiave\n");
    else
      printf("Obiettivo: Sconfiggi Drago e prendi Spada\n");

    printf("Stanze: %d/10\n", stanze);
    printf("1. Esplora\n2. Negozio\n3. Inventario\n4. Fuggi (50 "
           "monete)\nScelta: ");
    int s = leggi_intero();

    if (s == 1) {
      stanze++;
      int dado = lancia_dado(6);

      // Forza spawn boss se fine dungeon
      if (stanze >= 8) {
        if (tipo_missione == 1 && progress < target)
          dado = 6;
        else if (!completata && (tipo_missione == 2 || tipo_missione == 3))
          dado = (tipo_missione == 2) ? 5 : 6;
      }

      Entita e = genera_entita_missione(tipo_missione, dado);
      printf("Incontri: %s\n", e.nome);

      if (e.tipo == ENTITA_NEMICO) {
        // Indovinello Drago
        if (strcmp(e.nome, "Drago Antico") == 0) {
          int n = (rand() % 50) + 1;
          printf("Drago: Il numero %d e' di Padovan? [s/n]: ", n);
          char r;
          scanf(" %c", &r);
          getchar();
          int vero = controlla_padovan(n);
          if ((tolower(r) == 's' && vero) || (tolower(r) == 'n' && !vero)) {
            printf("Giusto! Il Drago non attacca.\n");
            e.danno = 0;
          } else
            printf("Sbagliato! Grrr!\n");
        }

        if (inizia_combattimento(g, &e)) {
          // Update progressi
          if (tipo_missione == 1 && e.e_boss)
            progress++;
          if (tipo_missione == 2 &&
              (e.e_boss || strcmp(e.nome, "Demone Custode") == 0)) {
            if (!g->ha_chiave_castello) {
              printf("Trovata Chiave Castello!\n");
              g->ha_chiave_castello = 1;
            }
            if (e.e_boss)
              completata = 1;
          }
          if (tipo_missione == 3 && e.e_boss) {
            printf("Trovata Spada Eroe!\n");
            g->ha_spada_eroe = 1;
            g->numero_oggetti++;
            completata = 1;
          }
        } else
          return 0; // Game Over
      } else if (e.tipo == ENTITA_TRAPPOLA) {
        if (strcmp(e.nome, "Forziere Misterioso") == 0) {
          if (lancia_dado(2) == 1) {
            printf("Trappola!\n");
            applica_danno_trappola(g, &e);
          } else {
            printf("Monete! (+%d)\n", e.ricompensa_monete);
            g->monete += e.ricompensa_monete;
          }
        } else if (e.danno > 0)
          applica_danno_trappola(g, &e);
      }
      if (g->punti_vita <= 0)
        return 0;
      printf("Premi Invio...");
      getchar();
    } else if (s == 2)
      mostra_negozio(g);
    else if (s == 3) {
      stampa_statistiche_giocatore(g);
      getchar();
    } else if (s == 4) {
      if ((tipo_missione == 1 && progress >= target) || completata) {
        printf("Missione Compiuta!\n");
        return 1;
      }
      if (g->monete >= 50) {
        g->monete -= 50;
        return 0;
      }
      printf("Non hai 50 monete!\n");
      getchar();
    }

    if (tipo_missione == 1 && progress >= target)
      completata = 1;

  } while (1);
}

// Placeholder
void genera_dungeon(Dungeon *d, int tipo_missione) {}
void stampa_info_stanza(const Stanza *s) {}
