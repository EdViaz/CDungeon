#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "stanza.h"
#include "giocatore.h"

// Ritorna 1 se il giocatore vince, 0 se muore
int inizia_combattimento(Giocatore *g, Stanza *nemico);
void applica_danno_trappola(Giocatore *g, Stanza *trappola);
int combattimento_boss_finale(Giocatore *g); // Returns 1 if win, 0 if lose

#endif
