/**
 * @file menu.h
 * @brief Gestione dei menu e dell'interfaccia utente.
 */

#ifndef MENU_H
#define MENU_H

#include "giocatore.h"
#include "salvataggio.h"

/**
 * @brief Mostra il menu principale del gioco.
 *
 * Permette di iniziare una nuova partita, caricare un salvataggio o uscire.
 * Contiene anche la gestione dei trucchi tramite codice segreto.
 *
 * @param lista_salvataggi Puntatore alla lista dei salvataggi.
 * @param giocatore_corrente Puntatore alla struttura dati del giocatore corrente.
 */
void mostra_menu_principale(NodoSalvataggio **lista_salvataggi, Giocatore *giocatore_corrente);

/**
 * @brief Mostra il menu del villaggio.
 *
 * Hub principale per il giocatore tra le missioni. Permette di curarsi,
 * gestire l'inventario, salvare o intraprendere nuove missioni.
 *
 * @param g Puntatore al giocatore.
 * @param lista_salvataggi Puntatore alla lista dei salvataggi per il salvataggio manuale.
 */
void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista_salvataggi);

/**
 * @brief Mostra il menu di selezione delle missioni.
 *
 * Elenca le missioni disponibili e avviabili dal giocatore.
 *
 * @param g Puntatore al giocatore.
 */
void mostra_menu_missione(Giocatore *g);

/**
 * @brief Mostra il negozio del villaggio.
 *
 * Permette al giocatore di acquistare oggetti e cure in cambio di monete.
 *
 * @param g Puntatore al giocatore.
 */
void mostra_negozio(Giocatore *g);

#endif
