#ifndef DUNGEON_H
#define DUNGEON_H

#include "entita.h"

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

void genera_dungeon(Dungeon *d, int tipo_missione);
void stampa_info_stanza(const Stanza *s);

#endif
