/**
 * @file main.c
 * @brief Entry point del gioco CDungeon.
 */
#include "giocatore.h"
#include "menu.h"
#include "salvataggio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Funzione principale del programma.
 *
 * Inizializza il generatore di numeri casuali, carica i salvataggi
 * e avvia il loop principale del menu.
 *
 * @return 0 se il programma termina correttamente.
 */
int main(){
  NodoSalvataggio *lista_salvataggi = NULL;
  Giocatore giocatore_corrente;

  // Carica i salvataggi esistenti da file
  carica_salvataggi_da_file(&lista_salvataggi);

  // Inizializza seed random
  srand(time(NULL));

  printf("Benvenuto in CDungeon! (premi Invio per iniziare)\n");
  getchar();
  mostra_menu_principale(&lista_salvataggi, &giocatore_corrente);

  // Pulizia della memoria alla chiusura
  libera_salvataggi(lista_salvataggi);

  return 0;
}
