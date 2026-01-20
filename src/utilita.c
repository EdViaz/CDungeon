#include "utilita.h"
#include <stdio.h>
#include <stdlib.h>

int lancia_dado(int facce) { return (rand() % facce) + 1; }

// P(n) = P(n-2) + P(n-3)
// P(0)=1, P(1)=1, P(2)=1
int padovan(int n) {
  if (n < 0)
    return 0;
  if (n <= 2)
    return 1;
  return padovan(n - 2) + padovan(n - 3);
}

int controlla_padovan(int num) {
  if (num < 1)
    return 0;
  // Controlliamo i primi 40 numeri, sufficienti per i valori di gioco
  for (int i = 0; i < 40; i++) {
    int p = padovan(i);
    if (p == num)
      return 1;
    if (p > num)
      return 0; // Sequenza crescente
  }
  return 0;
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
  while (scanf("%d", &valore) != 1) {
    while (getchar() != '\n')
      ; // Pulisci buffer
    printf("Input non valido. Inserisci un numero: ");
  }
  while (getchar() != '\n')
    ; // Pulisci fine riga
  return valore;
}

// 1: Scudo, 2: Magia, 3: Spada
int valuta_vittoria_morra(int m1, int m2) {
  if (m1 == m2)
    return 0;

  // Scudo(1) > Spada(3)
  // Magia(2) > Scudo(1)
  // Spada(3) > Magia(2)
  if ((m1 == 1 && m2 == 3) || (m1 == 2 && m2 == 1) || (m1 == 3 && m2 == 2)) {
    return 1;
  }
  return 2;
}
