#include <stdio.h>
#include "menu.h"
#include "salvataggio.h"
#include "giocatore.h"

int main() {
    NodoSalvataggio *lista_salvataggi = NULL;
    Giocatore giocatore_corrente;
    
    // Inizializza seed random
    // srand(time(NULL));

    printf("Benvenuto in CDungeon!\n");
    mostra_menu_principale(&lista_salvataggi, &giocatore_corrente);

    return 0;
}
