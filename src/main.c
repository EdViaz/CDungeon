#include "giocatore.h"
#include "menu.h"
#include "salvataggio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  NodoSalvataggio *lista_salvataggi = NULL;
  Giocatore giocatore_corrente;

  // Carica i salvataggi esistenti da file
  carica_salvataggi_da_file(&lista_salvataggi);

  // Inizializza seed random
  srand(time(NULL));

  printf("Benvenuto in CDungeon!\n");
  getchar();
  mostra_menu_principale(&lista_salvataggi, &giocatore_corrente);

  // Pulizia della memoria alla chiusura
  libera_salvataggi(lista_salvataggi);

  return 0;
}
