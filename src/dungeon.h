#ifndef DUNGEON_H
#define DUNGEON_H

#include "stanza.h"
#include "giocatore.h"

Stanza genera_stanza_missione(int tipo_missione, int dado);
int esegui_missione(Giocatore *g, int tipo_missione, const char *nome_missione);

#endif
