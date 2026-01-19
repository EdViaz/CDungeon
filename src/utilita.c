#include "utilita.h"
#include <stdio.h>
#include <stdlib.h>

int lancia_dado(int facce) { return (rand() % facce) + 1; }

// Funzione ricorsiva per la sequenza di Padovan
// P(n) = P(n-2) + P(n-3)
// P(0) = P(1) = P(2) = 1
int padovan(int n) {
  if (n < 0)
    return 0; // Gestione errori
  if (n <= 2)
    return 1;
  return padovan(n - 2) + padovan(n - 3);
}

void pulisci_schermo() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int leggi_intero() {
  int valore;
  // Legge un intero e pulisce il buffer fino al newline
  while (scanf("%d", &valore) != 1) {
    // Se l'input non è un numero, pulisci il buffer
    while (getchar() != '\n')
      ;
    printf("Input non valido. Inserisci un numero: ");
  }
  // Pulisci il resto della riga (es. se l'utente scrive "1 abc")
  while (getchar() != '\n')
    ;
  return valore;
}
