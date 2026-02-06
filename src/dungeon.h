/**
 * @file dungeon.h
 * @brief Gestione della generazione e del flusso del dungeon.
 */

#ifndef DUNGEON_H
#define DUNGEON_H

#include "stanza.h"
#include "giocatore.h"

/**
 * @brief Genera una stanza casuale in base alla missione e al lancio del dado.
 *
 * @param tipo_missione ID della missione corrente (1, 2 o 3).
 * @param dado Risultato del lancio del dado per determinare il contenuto.
 * @return La struttura Stanza generata.
 */
Stanza genera_stanza_missione(int tipo_missione, int dado);

/**
 * @brief Gestisce il loop principale di esecuzione di una missione.
 *
 * Include la navigazione tra le stanze, il combattimento, il negozio
 * e la gestione degli obiettivi della missione.
 *
 * @param g Puntatore al giocatore.
 * @param tipo_missione ID della missione da eseguire.
 * @param nome_missione Nome visualizzato della missione.
 * @return 1 se la missione è completata con successo, 0 in caso di fallimento o rinuncia.
 */
int esegui_missione(Giocatore *g, int tipo_missione, const char *nome_missione);

#endif
