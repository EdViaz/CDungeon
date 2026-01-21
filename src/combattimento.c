#include "combattimento.h"
#include "utilita.h"
#include <stdio.h>

int inizia_combattimento(Giocatore *g, Stanza *e) {
  printf("\n--- COMBATTIMENTO: %s ---\n", e->nome);

  while (g->punti_vita > 0) {
    printf("\nTu: %d HP | Nemico: %s\n", g->punti_vita, e->nome);
    printf("Premi Invio per attaccare...");
    getchar();

    // Turno Giocatore
    int dado = lancia_dado(6);
    int attacco = dado;

    if (g->ha_spada_eroe)
      attacco += 2;
    else if (g->ha_spada)
      attacco += 1;

    printf("Tiro: %d (Totale: %d)\n", dado, attacco);

    if (attacco > e->colpo_fatale) {
      printf("Colpo fatale! %s sconfitto!\n", e->nome);
      g->monete += e->ricompensa_monete;
      printf("Ottieni %d monete.\n", e->ricompensa_monete);
      return 1;
    } else {
      printf("Mancato (Serviva > %d).\n", e->colpo_fatale);

      // Turno Nemico
      int danno = e->danno;
      if (g->ha_armatura) {
        danno--;
        printf("Armatura assorbe 1 danno.\n");
      }
      g->punti_vita -= danno;
      printf("%s infligge %d danni!\n", e->nome, danno);
    }
  }

  printf("\nSEI STATO SCONFITTO!\n");
  g->punti_vita = 0;
  getchar();
  return 0;
}

void applica_danno_trappola(Giocatore *g, Stanza *trappola) {
  printf("\n!!! TRAPPOLA: %s !!!\n", trappola->nome);

  int danno = trappola->danno;

  if (g->ha_armatura) {
    danno--;
    if (danno < 0)
      danno = 0;
    printf("Armatura assorbe 1 danno.\n");
  }

  g->punti_vita -= danno;
  printf("Subisci %d danni! (HP: %d)\n", danno, g->punti_vita);
}

int combattimento_boss_finale(Giocatore *g) {
  printf("\n--- SCONTRO FINALE: SIGNORE OSCURO ---\n");
  printf("Regole: Scudo > Spada > Magia > Scudo\n");
  printf("Vinci 3 round su 5.\n");

  int vittorie_eroe = 0;
  int vittorie_boss = 0;
  int round = 1;
  const char *mosse[] = {"", "Scudo", "Magia", "Spada"};

  while (vittorie_eroe < 3 && vittorie_boss < 3 && round <= 5) {
    printf("\n--- Round %d (Eroe %d - Boss %d) ---\n", round, vittorie_eroe,
           vittorie_boss);
    printf("1. Scudo\n2. Magia\n3. Spada\nScelta: ");

    int mossa_eroe = leggi_intero();
    if (mossa_eroe < 1 || mossa_eroe > 3)
      continue;

    int mossa_boss = lancia_dado(3);
    printf("Tu: %s | Boss: %s\n", mosse[mossa_eroe], mosse[mossa_boss]);

    int esito = valuta_vittoria_morra(mossa_eroe, mossa_boss);

    if (esito == 0) {
      printf("Pareggio!\n");
    } else if (esito == 1) {
      printf("Vinci il round!\n");
      vittorie_eroe++;
      round++;
    } else {
      printf("Il Boss vince il round!\n");
      vittorie_boss++;
      round++;
    }
  }

  return (vittorie_eroe >= 3);
}
