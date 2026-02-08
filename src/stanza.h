/**
 * @file stanza.h
 * @brief Definizione della struttura e dei tipi di stanza.
 */

#ifndef STANZA_H
#define STANZA_H

/**
 * @brief Enum che rappresenta i diversi tipi di stanza.
 */
typedef enum
{
  STANZA_NESSUNA,  /**< Stanza non definita */
  STANZA_NEMICO,   /**< Stanza con un nemico da affrontare */
  STANZA_TRAPPOLA, /**< Stanza con una trappola da superare */
  STANZA_VUOTA     /**< Stanza vuota senza eventi */
} TipoStanza;

/**
 * @brief Struttura che rappresenta una stanza del dungeon.
 */
typedef struct
{
  char nome[32];         /**< Nome della stanza */
  TipoStanza tipo;       /**< Tipo di stanza (nemico, trappola, vuota) */
  int danno;             /**< Danno inflitto dalla stanza al giocatore */
  int colpo_fatale;      /**< Danno che il giocatore deve infliggere per sconfiggere il nemico */
  int ricompensa_monete; /**< Ricompensa in monete per il giocatore */
  int is_boss;           /**< Indica se la stanza contiene un boss */
} Stanza;

#endif