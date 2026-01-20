#ifndef DUNGEON_H
#define DUNGEON_H

#include "entita.h"
#include "giocatore.h"

#define MAX_STANZE 10

typedef struct {
  Entita entita;
  int completata;
  char descrizione[64];
} Stanza;

typedef struct {
  Stanza stanze[MAX_STANZE];
  int numero_stanze;
  int indice_stanza_corrente;
  int tipo_missione; // 1: Palude, 2: Magione, 3: Grotta
} Dungeon;

// Core logic
Entita genera_entita_missione(int tipo, int dado);
int esegui_missione(Giocatore *g, int tipo_missione, const char *nome_missione);

// Legacy/Future placeholders (optional)
void genera_dungeon(Dungeon *d, int tipo_missione);
void stampa_info_stanza(const Stanza *s);

#endif
