#ifndef SALVATAGGIO_H
#define SALVATAGGIO_H

#include "giocatore.h"

typedef struct NodoSalvataggio {
    int id;
    char timestamp[32];
    Giocatore dati_giocatore;
    struct NodoSalvataggio *prossimo;
} NodoSalvataggio;

void aggiungi_salvataggio(NodoSalvataggio **testa, Giocatore *g);
NodoSalvataggio* carica_salvataggio(NodoSalvataggio *testa, int id);
void elimina_salvataggio(NodoSalvataggio **testa, int id);
void stampa_salvataggi(NodoSalvataggio *testa);
void carica_salvataggi_da_file(NodoSalvataggio **testa);
void libera_salvataggi(NodoSalvataggio *testa);

#endif
