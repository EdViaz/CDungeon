#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "dungeon.h"
#include "stanza.h"
#include "giocatore.h"

int inizia_combattimento(Giocatore *g, Stanza *nemico);
void applica_danno_trappola(Giocatore *g, Stanza *trappola);
int combattimento_boss_finale(
    Giocatore *g); // Ritorna 1 se il giocatore vince, 0 se muore

#endif
