#ifndef GIOCATORE_H
#define GIOCATORE_H

#define MAX_INVENTARIO 10

typedef struct {
    int punti_vita;
    int max_punti_vita;
    int monete;
    int numero_oggetti;
    int missioni_completate;
    // Flag per oggetti chiave
    int ha_spada;       // 0 o 1
    int ha_armatura;    // 0 o 1
    int ha_spada_eroe;  // 0 o 1
    int ha_chiave_castello; // 0 o 1
} Giocatore;

void inizializza_giocatore(Giocatore *g);
void stampa_statistiche_giocatore(const Giocatore *g);

#endif
