/**
 * @file salvataggio.h
 * @brief Gestione del sistema di salvataggio e caricamento.
 */

#ifndef SALVATAGGIO_H
#define SALVATAGGIO_H

#include "giocatore.h"

/**
 * @brief Nodo di una lista concatenata per memorizzare i salvataggi.
 */
typedef struct NodoSalvataggio
{
  int id;                  /**< Identificativo univoco del salvataggio */
  char timestamp[32];      /**< Data e ora di creazione del salvataggio */
  Giocatore dati_giocatore; /**< Copia dello stato del giocatore */
  struct NodoSalvataggio *prossimo; /**< Puntatore al prossimo nodo della lista */
} NodoSalvataggio;

/**
 * @brief Aggiunge un nuovo salvataggio alla lista e al file.
 *
 * Crea un nuovo nodo con i dati attuali del giocatore, genera un nuovo ID,
 * lo aggiunge in testa alla lista e aggiorna il file di salvataggio.
 *
 * @param testa Puntatore doppio alla testa della lista.
 * @param g Puntatore ai dati del giocatore da salvare.
 */
void aggiungi_salvataggio(NodoSalvataggio **testa, Giocatore *g);

/**
 * @brief Cerca un salvataggio nella lista tramite ID.
 *
 * @param testa Testa della lista dei salvataggi.
 * @param id ID del salvataggio da cercare.
 * @return Puntatore al nodo trovato, o NULL se non esiste.
 */
NodoSalvataggio *carica_salvataggio(NodoSalvataggio *testa, int id);

/**
 * @brief Elimina un salvataggio dalla lista e dal file.
 *
 * Rimuove il nodo corrispondente all'ID specificato e riscrive il file binario.
 *
 * @param testa Puntatore doppio alla testa della lista.
 * @param id ID del salvataggio da eliminare.
 */
void elimina_salvataggio(NodoSalvataggio **testa, int id);

/**
 * @brief Stampa a video l'elenco dei salvataggi disponibili.
 *
 * Mostra ID, timestamp e riepilogo delle statistiche per ogni salvataggio.
 *
 * @param testa Testa della lista dei salvataggi.
 */
void stampa_salvataggi(NodoSalvataggio *testa);

/**
 * @brief Carica tutti i salvataggi dal file binario all'avvio.
 *
 * Legge il file "salvataggi.bin" e ricostruisce la lista concatenata in memoria.
 *
 * @param testa Puntatore doppio alla testa della lista (verrà inizializzata).
 */
void carica_salvataggi_da_file(NodoSalvataggio **testa);

/**
 * @brief Salva l'intera lista dei salvataggi su file.
 *
 * Sovrascrive il file "salvataggi.bin" con il contenuto attuale della lista.
 *
 * @param testa Testa della lista dei salvataggi.
 */
void salva_tutto_su_file(NodoSalvataggio *testa);

/**
 * @brief Libera la memoria allocata per la lista dei salvataggi.
 *
 * Da chiamare alla chiusura del programma.
 *
 * @param testa Testa della lista da deallocare.
 */
void libera_salvataggi(NodoSalvataggio *testa);

#endif
