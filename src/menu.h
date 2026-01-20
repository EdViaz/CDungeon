#ifndef MENU_H
#define MENU_H

#include "giocatore.h"
#include "salvataggio.h"

void mostra_menu_principale(NodoSalvataggio **lista_salvataggi,
                            Giocatore *giocatore_corrente);
void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista_salvataggi);
void mostra_menu_missione(Giocatore *g);
void mostra_negozio(Giocatore *g); // Added

#endif
