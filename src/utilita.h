
/**
 * @file utilita.h
 * @brief Funzioni di utilità generale per il gioco.
 *
 * Contiene funzioni per la generazione di numeri casuali,
 * calcoli matematici (sequenza di Padovan), gestione input/output
 * e logica di base per la Morra Cinese.
 */

#ifndef UTILITA_H
#define UTILITA_H

/**
 * @brief Lancia un dado con un specificato numero di facce.
 * @param facce Il numero di facce del dado.
 * @return Un numero casuale tra 1 e facce.
 */
int lancia_dado(int facce);

// Funzioni matematiche / logiche

/**
 * @brief Calcola l'n-esimo numero della sequenza di Padovan.
 *
 * La sequenza è definita come P(n) = P(n-2) + P(n-3)
 * con P(0)=1, P(1)=1, P(2)=1.
 *
 * @param n L'indice della sequenza.
 * @return L'n-esimo numero di Padovan.
 */
int padovan(int n);

/**
 * @brief Verifica se un numero appartiene alla sequenza di Padovan.
 *
 * Controlla i primi 25 numeri della sequenza.
 *
 * @param num Il numero da verificare.
 * @return 1 se il numero appartiene alla sequenza, 0 altrimenti.
 */
int controlla_padovan(int num);

// Funzioni input/output

/**
 * @brief Pulisce lo schermo del terminale.
 *
 * Supporta sia sistemi Windows che UNIX-like.
 */
void pulisci_schermo();

/**
 * @brief Legge un singolo carattere da input.
 *
 * Pulisce il buffer e gestisce l'input dell'utente, restituendo
 * il carattere in minuscolo.
 *
 * @return Il carattere letto, oppure 0 in caso di input vuoto o errore.
 */
char leggi_input_char();

/**
 * @brief Legge un numero intero da input.
 *
 * Gestisce la validazione dell'input richiedendo l'inserimento
 * finché non viene fornito un intero valido.
 *
 * @return Il numero intero letto.
 */
int leggi_intero();

// Logica Morra Cinese (1: Scudo, 2: Magia, 3: Spada)

/**
 * @brief Valuta il vincitore nella Morra Cinese.
 *
 * Le regole sono:
 * - Scudo (1) batte Spada (3)
 * - Magia (2) batte Scudo (1)
 * - Spada (3) batte Magia (2)
 *
 * @param mossa1 La mossa del primo giocatore.
 * @param mossa2 La mossa del secondo giocatore (boss).
 * @return 0 per pareggio, 1 se vince mossa1, 2 se vince mossa2.
 */
int valuta_vittoria_morra(int mossa1, int mossa2);

#endif
