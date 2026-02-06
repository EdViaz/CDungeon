/**
 * @file giocatore.c
 * @brief Implementazione delle funzioni relative al giocatore.
 */

#include "giocatore.h"
#include <stdio.h>

void inizializza_giocatore(Giocatore *g)
{
  g->punti_vita = 20;
  g->max_punti_vita = 20;
  g->monete = 0;
  g->numero_oggetti = 0;
  g->missione_palude = 0;
  g->missione_magione = 0;
  g->missione_grotta = 0;
  g->ha_spada = 0;
  g->ha_armatura = 0;
  g->ha_spada_eroe = 0;
  g->ha_chiave_castello = 0;
}

void stampa_statistiche_giocatore(const Giocatore *g)
{
  printf("\n=== Inventario Giocatore ===\n");
  
  printf("Punti Vita: %d / %d\n", g->punti_vita, g->max_punti_vita);
  printf("Monete: %d\n", g->monete);
  printf("Oggetti: %d\n", g->numero_oggetti);
  printf("Missioni Completate: %d\n", g->missione_palude + g->missione_magione + g->missione_grotta);
  printf("Equipaggiamento:\n");
  if (g->ha_spada || g->ha_spada_eroe)
    printf("- Spada: %s (+%d attacco)\n",
           g->ha_spada_eroe ? "Spada dell'Eroe" : "Spada Ferro",
           g->ha_spada_eroe ? 2 : 1);
  else
    printf("- Nessuna arma\n");
  if (g->ha_armatura)
    printf("- Armatura: Si (-1 danno subito)\n");
  else
    printf("- Nessuna armatura\n");
  if (g->ha_chiave_castello)
    printf("- Oggetti Chiave: Chiave del Castello\n");

  printf("============================\n");
}
