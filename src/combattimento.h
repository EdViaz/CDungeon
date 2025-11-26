#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "giocatore.h"
#include "entita.h"

// Ritorna 1 se il giocatore vince, 0 se muore
int inizia_combattimento(Giocatore *g, Entita *e);
void applica_danno_trappola(Giocatore *g, Entita *trappola);

#endif
