/**
 * @file giocatore.h
 * @brief Definizione della struttura Giocatore e funzioni correlate.
 */

#ifndef GIOCATORE_H
#define GIOCATORE_H

/**
 * @brief Struttura che rappresenta lo stato del giocatore.
 */
typedef struct
{
  int punti_vita;       /**< Punti vita attuali del giocatore */
  int max_punti_vita;   /**< Punti vita massimi del giocatore */
  int monete;           /**< Numero di monete possedute */
  int numero_oggetti;   /**< Conteggio generico oggetti (non usato per inventario specifico) */
  
  // Flag per missioni completate
  int missione_palude;  /**< 1 se la missione palude è completata, 0 altrimenti */
  int missione_magione; /**< 1 se la missione magione è completata, 0 altrimenti */
  int missione_grotta;  /**< 1 se la missione grotta è completata, 0 altrimenti */
  
  // Flag per oggetti chiave
  int ha_spada;           /**< 1 se possiede la spada base, 0 altrimenti */
  int ha_armatura;        /**< 1 se possiede l'armatura, 0 altrimenti */
  int ha_spada_eroe;      /**< 1 se possiede la spada dell'eroe, 0 altrimenti */
  int ha_chiave_castello; /**< 1 se possiede la chiave del castello, 0 altrimenti */
} Giocatore;

/**
 * @brief Inizializza un nuovo giocatore con valori di default.
 *
 * Imposta HP a 20, monete a 0 e resetta missioni e inventario.
 *
 * @param g Puntatore alla struttura Giocatore da inizializzare.
 */
void inizializza_giocatore(Giocatore *g);

/**
 * @brief Stampa a video le statistiche e l'inventario del giocatore.
 *
 * Mostra HP, monete, missioni completate ed equipaggiamento attuale.
 *
 * @param g Puntatore alla struttura Giocatore costante.
 */
void stampa_statistiche_giocatore(const Giocatore *g);

#endif
