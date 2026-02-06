#include "dungeon.h"
#include "combattimento.h"
#include "menu.h"
#include "utilita.h"
#include <stdio.h>
#include <string.h>

void mostra_negozio(Giocatore *g); // Extern

Stanza genera_stanza_missione(int tipo_missione, int dado)
{
  Stanza s;
  s.tipo = STANZA_NESSUNA;
  sprintf(s.nome, "Nulla");
  s.danno = 0;
  s.colpo_fatale = 0;
  s.ricompensa_monete = 0;
  s.is_boss = 0;

  // Configurazione entita in base a missione e dado

  // Missione 1: Palude
  if (tipo_missione == 1)
  {
    if (dado == 1)
    {
      sprintf(s.nome, "Cane Selvaggio");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 2;
      s.danno = 1;
    }
    else if (dado == 2)
    {
      sprintf(s.nome, "Goblin");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 3;
      s.danno = 2;
      s.ricompensa_monete = 2;
    }
    else if (dado == 3)
    {
      sprintf(s.nome, "Scheletro");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 4;
      s.danno = 2;
      s.ricompensa_monete = 4;
    }
    else if (dado == 4)
    {
      sprintf(s.nome, "Orco");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 3;
      s.danno = 4;
      s.ricompensa_monete = 6;
    }
    else if (dado == 5)
    {
      sprintf(s.nome, "Acquitrino Velenoso");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = lancia_dado(6);
    }
    else if (dado == 6)
    {
      sprintf(s.nome, "Generale Orco");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 6;
      s.danno = 3;
      s.ricompensa_monete = 12;
      s.is_boss = 1;
    }
  }
  // Missione 2: Magione
  else if (tipo_missione == 2)
  {
    if (dado == 1)
    {
      sprintf(s.nome, "Botola Buia");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = 3;
    }
    else if (dado == 2)
    {
      sprintf(s.nome, "Pipistrello");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 2;
      s.danno = 2;
      s.ricompensa_monete = 1;
    }
    else if (dado == 3)
    {
      sprintf(s.nome, "Zombie");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 3;
      s.danno = 2;
      s.ricompensa_monete = 2;
    }
    else if (dado == 4)
    {
      sprintf(s.nome, "Fantasma");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 5;
      s.danno = 2;
      s.ricompensa_monete = 4;
    }
    else if (dado == 5)
    {
      sprintf(s.nome, "Vampiro Superiore");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 4;
      s.danno = 4;
      s.ricompensa_monete = 7;
      s.is_boss = 1;
    }
    else if (dado == 6)
    {
      sprintf(s.nome, "Demone Custode");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 4;
      s.danno = 6;
      s.ricompensa_monete = 10;
      s.is_boss = 1;
    }
  }
  // Missione 3: Grotta
  else if (tipo_missione == 3)
  {
    if (dado == 1)
    {
      sprintf(s.nome, "Stanza Vuota");
      s.tipo = STANZA_VUOTA;
    }
    else if (dado == 2)
    {
      sprintf(s.nome, "Cristalli Cadenti");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = 2;
    }
    else if (dado == 3)
    {
      sprintf(s.nome, "Ponte Pericolante");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = 0;
    }
    else if (dado == 4)
    {
      sprintf(s.nome, "Forziere Misterioso");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = 2;
      s.ricompensa_monete = 10;
    }
    else if (dado == 5)
    {
      sprintf(s.nome, "Rupe scoscesa");
      s.tipo = STANZA_TRAPPOLA;
      s.danno = lancia_dado(6);
    }
    else if (dado == 6)
    {
      sprintf(s.nome, "Drago Antico");
      s.tipo = STANZA_NEMICO;
      s.colpo_fatale = 5;
      s.danno = 10;
      s.ricompensa_monete = 12;
      s.is_boss = 1;
    }
  }
  return s;
}

int esegui_missione(Giocatore *g, int tipo_missione, const char *nome_missione)
{
  int target = (tipo_missione == 1) ? 3 : 1;
  int progress = 0;
  int n_stanze = 0;
  int completata = 0;

  do
  {
    pulisci_schermo();
    printf("=== %s ===\n", nome_missione);

    // Obiettivi missione 'Palude'
    if (tipo_missione == 1)
      printf("Obiettivo: Sconfiggi %d Generali Orco (%d/%d)\n", target, progress, target);

    // Obiettivi missione 'Magione'
    else if (tipo_missione == 2)
      printf("Obiettivo: Sconfiggi Vampiro Superiore (%d/%d) e prendi Chiave (%d/1)\n", progress, target, g->ha_chiave_castello);

    // Obiettivi missione 'Grotta'
    else if (tipo_missione == 3)
      printf("Obiettivo: Sconfiggi Drago (%d/1) e prendi Spada (%d/1)\n", progress, g->ha_spada_eroe);

    // Stanze esplorate
    printf("Stanze Esplorate: %d/10\n\n", n_stanze);

    // Menu azioni
    if (n_stanze < 10)
      printf("1. Esplora\n");
    printf("2. Negozio\n3. Inventario\n4. Torna al Villaggio (Completa Obbiettivo oppure Paga 50 monete)\n\n");
    printf("Seleziona una delle opzioni del menu [1-4]: ");

    // Gestione scelta utente
    int scelta = leggi_intero();
    if (scelta == 1 && n_stanze < 10)
    {
      n_stanze++;
      int dado = lancia_dado(6);

      // Forza spawn boss se fine dungeon
      // Palude: Generale Orco
      if (n_stanze >= 8 && !completata && tipo_missione == 1)
        dado = 6;

      // Magione: Demone Custode + Vampiro
      if (n_stanze >= 9 && !completata && tipo_missione == 2)
      {
        if (g->ha_chiave_castello == 0)
          dado = 5;
        else if (g->ha_chiave_castello == 1)
          dado = 6;
      }
      else if (completata && tipo_missione == 2)
        dado = lancia_dado(4); // evita di far spawnare di nuovo i boss

      // Grotta: Drago Antico
      if (n_stanze >= 10 && !completata && tipo_missione == 3)
        dado = 6;
      else if (completata && tipo_missione == 3)
        dado = lancia_dado(5); // evita di far spawnare di nuovo il drago

      Stanza s = genera_stanza_missione(tipo_missione, dado);
      printf("Incontri: %s\n", s.nome);

      if (s.tipo == STANZA_NEMICO)
      {
        if (inizia_combattimento(g, &s))
        {
          // Update progressi missione 'Palude'
          if (tipo_missione == 1 && s.is_boss)
            progress++;

          // Update progressi missione 'Magione'
          else if (tipo_missione == 2 && s.is_boss)
          {
            if (strcmp(s.nome, "Vampiro Superiore") == 0)
            {
              progress++;
            }
            else if (strcmp(s.nome, "Demone Custode") == 0)
            {
              printf("Trovata Chiave del Castello!\n");
              g->ha_chiave_castello = 1;
              g->numero_oggetti++;
            }
          }
          // Update progressi missione 'Grotta'
          else if (tipo_missione == 3 && s.is_boss)
          {
            printf("Trovata Spada Eroe!\n");
            g->ha_spada_eroe = 1;
            g->numero_oggetti++;
            progress++;
          }
        }
        else
          return 0; // Game Over
      }
      else if (s.tipo == STANZA_TRAPPOLA)
      {
        if (strcmp(s.nome, "Forziere Misterioso") == 0)
        {
          int chance = lancia_dado(2);
          printf("Apri il forziere... ");
          if (chance == 1)
          {
            printf("Trappola!\n");
            applica_danno_trappola(g, &s);
          }
          else
          {
            printf("Monete! (+%d)\n", s.ricompensa_monete);
            g->monete += s.ricompensa_monete;
          }
        }
        else if (strcmp(s.nome, "Ponte Pericolante") == 0)
        {
          g->monete -= 3;
          if (g->monete < 0)
            g->monete = 0;
          printf("Caduto dal ponte! Perdi 3 monete. (Monete: %d)\n", g->monete);
        }
        else if (s.danno > 0)
          applica_danno_trappola(g, &s);
      }

      // Check completamento missione 'Palude'
      if (tipo_missione == 1 && progress >= target)
        completata = 1;
      // Check completamento missione 'Magione'
      if (tipo_missione == 2 && progress >= target && g->ha_chiave_castello == 1)
        completata = 1;
      // Check completamento missione 'Grotta'
      if (tipo_missione == 3 && progress >= target && g->ha_spada_eroe == 1)
        completata = 1;

      if (g->punti_vita <= 0)
        return 0;

      printf("Premi Invio...");
      getchar();
    }

    // Scelta negozio
    else if (scelta == 2)
      mostra_negozio(g);

    // Scelta inventario
    else if (scelta == 3)
    {
      stampa_statistiche_giocatore(g);
      getchar();
    }

    // Scelta fuga
    else if (scelta == 4)
    {
      if (completata)
      {
        printf("\nMISSIONE COMPIUTA!\n");
        getchar();
        return 1;
      }
      if (g->monete >= 50)
      {
        g->monete -= 50;
        return 0;
      }
      printf("Non hai 50 monete!\n");
      getchar();
    }
  } while (1);
}