#include "utilita.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int lancia_dado(int facce) { return (rand() % facce) + 1; }

// P(n) = P(n-2) + P(n-3)
// P(0)=1, P(1)=1, P(2)=1
int padovan(int n)
{
  if (n < 0)
    return 0;
  if (n <= 2)
    return 1;
  return padovan(n - 2) + padovan(n - 3);
}

int controlla_padovan(int num)
{
  if (num < 1)
    return 0;
  for (int i = 0; i < 25; i++)
  {
    int p = padovan(i);
    if (p == num)
      return 1;
    if (p > num)
      return 0;
  }
  return 0;
}

void pulisci_schermo()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Legge un singolo carattere dall'input dell'utente e lo restituisce in minuscolo
char leggi_input_char()
{
  char b[100]; // Buffer per memorizzare l'input (100 caratteri max)

  // Legge una linea intera da stdin in modo sicuro
  if (fgets(b, sizeof(b), stdin))
  {
    // Rimuove il carattere di newline inserito automaticamente da fgets
    b[strcspn(b, "\n")] = 0;

    // Se l'utente ha premuto solo invio (input vuoto), restituisce 0
    if (strlen(b) == 0)
      return 0;

    // Se l'utente ha inserito solo uno spazio, lo restituisce
    if (strcmp(b, " ") == 0)
      return ' ';

    // Restituisce il primo carattere convertito a minuscolo
    return tolower(b[0]);
  }

  // Se fgets fallisce, restituisce 0
  return 0;
}

int leggi_intero()
{
  int valore;
  while (scanf("%d", &valore) != 1)
  {
    while (getchar() != '\n')
      ; // Pulisci buffer
    printf("Input non valido. Inserisci un numero: ");
  }
  while (getchar() != '\n')
    ; // Pulisci fine riga
  return valore;
}

// 1: Scudo, 2: Magia, 3: Spada
int valuta_vittoria_morra(int m1, int m2)
{
  if (m1 == m2)
    return 0;

  // Scudo(1) > Spada(3)
  // Magia(2) > Scudo(1)
  // Spada(3) > Magia(2)
  if ((m1 == 1 && m2 == 3) || (m1 == 2 && m2 == 1) || (m1 == 3 && m2 == 2))
  {
    return 1;
  }
  return 2;
}
