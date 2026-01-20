#ifndef UTILITA_H
#define UTILITA_H

int lancia_dado(int facce);

// Funzioni matematiche / logiche
int padovan(int n);
int controlla_padovan(
    int num); // Verifica se un numero appartiene alla sequenza

// Funzioni input/output
void pulisci_schermo();
int leggi_intero();

// Logica Morra Cinese (1: Scudo, 2: Magia, 3: Spada)
// Ritorna: 0 Pareggio, 1 Vince mossa1, 2 Vince mossa2
int valuta_vittoria_morra(int mossa1, int mossa2);

#endif
