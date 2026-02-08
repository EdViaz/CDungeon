/**
 * @file combattimento.h
 * @brief Gestione del combattimento e delle interazioni con nemici, trappole e boss.
 */

#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H

#include "stanza.h"
#include "giocatore.h"

/**
 * @brief Inizia un combattimento tra il giocatore e un nemico.
 *
 * Gestisce i turni di attacco e difesa, calcola i danni
 * e determina il vincitore del combattimento.
 *
 * @param g Puntatore al giocatore.
 * @param nemico Puntatore alla stanza contenente il nemico.
 * @return 1 se il giocatore vince, 0 se perde (Game Over).
 */
int inizia_combattimento(Giocatore *g, Stanza *nemico);

/**
 * @brief Applica i danni di una trappola al giocatore.
 *
 * Calcola i danni subiti considerando eventuali riduzioni
 * dovute all'equipaggiamento (es. armatura).
 *
 * @param g Puntatore al giocatore.
 * @param trappola Puntatore alla stanza contenente la trappola.
 */
void applica_danno_trappola(Giocatore *g, Stanza *trappola);

/**
 * @brief Gestisce il boss fight finale contro il Signore Oscuro.
 *
 * Implementa una versione a turni della Morra Cinese (Sasso-Carta-Forbice).
 * Il giocatore deve vincere 3 round su 5.
 *
 * @param g Puntatore al giocatore.
 * @return 1 se il giocatore vince, 0 se perde.
 */
int combattimento_boss_finale(Giocatore *g);

#endif
