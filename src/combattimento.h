#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "entita.h"
#include "giocatore.h"

// Ritorna 1 se il giocatore vince, 0 se muore
int inizia_combattimento(Giocatore *g, Entita *e);
void applica_danno_trappola(Giocatore *g, Entita *trappola);
int combattimento_boss_finale(Giocatore *g); // Returns 1 if win, 0 if lose

#endif
