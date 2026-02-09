/**
 * @file salvataggio.c
 * @brief Implementazione delle funzioni per la gestione dei salvataggi.
 */

#include "salvataggio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Funzione helper per ottenere la data corrente come stringa
void ottieni_data_corrente(char *buffer, size_t size)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  // Formato: GG-MM-AAAA HH:MM:SS
  snprintf(buffer, size, "%02d-%02d-%04d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void salva_tutto_su_file(NodoSalvataggio *testa)
{
  FILE *f = fopen("salvataggi.bin", "wb");
  if (!f)
  {
    perror("Errore apertura file salvataggi");
    return;
  }

  NodoSalvataggio *curr = testa;
  while (curr)
  {
    // Scriviamo ID, timestamp e dati giocatore
    fwrite(&curr->id, sizeof(int), 1, f);
    fwrite(curr->timestamp, sizeof(curr->timestamp), 1, f);
    fwrite(&curr->dati_giocatore, sizeof(Giocatore), 1, f);

    // Passiamo al prossimo nodo
    curr = curr->prossimo;
  }
  fclose(f);
}

void aggiungi_salvataggio(NodoSalvataggio **testa, Giocatore *g)
{
  NodoSalvataggio *nuovo = (NodoSalvataggio *)malloc(sizeof(NodoSalvataggio));
  if (!nuovo)
  {
    printf("Errore di allocazione memoria per il salvataggio.\n");
    return;
  }

  // Copia i dati del giocatore
  nuovo->dati_giocatore = *g;
  ottieni_data_corrente(nuovo->timestamp, sizeof(nuovo->timestamp));
  nuovo->prossimo = NULL;

  // Calcolo ID: Massimo attuale + 1
  int max_id = 0;
  NodoSalvataggio *curr = *testa;
  while (curr)
  {
    if (curr->id > max_id)
      max_id = curr->id;
    curr = curr->prossimo;
  }
  nuovo->id = max_id + 1;

  // Inserimento in testa alla lista
  nuovo->prossimo = *testa;
  *testa = nuovo;

  // Aggiorna il file dopo l'aggiunta
  salva_tutto_su_file(*testa);

  printf("Partita salvata con successo! (ID: %d)\n", nuovo->id);
}

NodoSalvataggio *carica_salvataggio(NodoSalvataggio *testa, int id)
{
  // Parto dalla testa e cerco il nodo con l'ID corrispondente
  NodoSalvataggio *curr = testa;
  while (curr)
  {
    if (curr->id == id)
    {
      return curr;
    }
    // Passo al prossimo nodo
    curr = curr->prossimo;
  }
  return NULL;
}

void elimina_salvataggio(NodoSalvataggio **testa, int id)
{
  NodoSalvataggio *curr = *testa;
  NodoSalvataggio *prev = NULL;

  while (curr)
  {
    if (curr->id == id)
    {
      // Rimuoviamo il nodo dalla lista
      if (prev)
      {
        // Se non è il primo nodo, aggiorniamo il puntatore del nodo precedente
        prev->prossimo = curr->prossimo;
      }
      else
      {
        // Se è il primo nodo, aggiorniamo la testa della lista
        *testa = curr->prossimo;
      }
      free(curr);

      // Aggiorniamo il file dopo la modifica
      salva_tutto_su_file(*testa);

      printf("Salvataggio %d eliminato.\n", id);
      return;
    }
    // Passiamo al prossimo nodo
    prev = curr;
    curr = curr->prossimo;
  }
  printf("Salvataggio con ID %d non trovato.\n", id);
}

void stampa_salvataggi(NodoSalvataggio *testa)
{
  if (!testa)
  {
    printf("Nessun salvataggio disponibile.\n");
    return;
  }

  NodoSalvataggio *curr = testa;
  while (curr)
  {
    // Formato richiesto: ID. DATA , P. VITA , MONETE , OGGETTI , MISSIONI COMPLETATE
    printf("%d. %s , %d P. VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE\n",
           curr->id, curr->timestamp, curr->dati_giocatore.punti_vita,
           curr->dati_giocatore.monete, curr->dati_giocatore.numero_oggetti,
           curr->dati_giocatore.missione_palude + curr->dati_giocatore.missione_magione + curr->dati_giocatore.missione_grotta);

    curr = curr->prossimo;
  }
}

void libera_salvataggi(NodoSalvataggio *testa)
{

  // Scorriamo la lista e liberiamo ogni nodo
  NodoSalvataggio *curr = testa;
  while (curr)
  {
    NodoSalvataggio *temp = curr;
    // Passiamo al prossimo nodo prima di liberare quello corrente
    curr = curr->prossimo;
    free(temp);
  }
}

void carica_salvataggi_da_file(NodoSalvataggio **testa)
{
  FILE *f = fopen("salvataggi.bin", "rb");
  if (!f)
    return; // File non esistente, nessun salvataggio

  // Svuota lista attuale se ce ne fosse bisogno
  libera_salvataggi(*testa);
  *testa = NULL;

  while (1)
  {
    NodoSalvataggio *nuovo = (NodoSalvataggio *)malloc(sizeof(NodoSalvataggio));
    if (!nuovo)
      break;

    // Leggi i 3 campi (ID, timestamp, dati_giocatore)

    if (fread(&nuovo->id, sizeof(int), 1, f) != 1) // Se non riesce a leggere l'ID, probabilmente siamo alla fine del file
    {
      free(nuovo); // Dealloca se fallisce la lettura
      break;
    }

    fread(nuovo->timestamp, sizeof(nuovo->timestamp), 1, f); // Legge il timestamp
    fread(&nuovo->dati_giocatore, sizeof(Giocatore), 1, f);  // Legge i dati del giocatore

    // Inserisce il nuovo nodo in fondo alla lista
    nuovo->prossimo = NULL;
    if (*testa == NULL)
    {
      // Se la lista è vuota, il nuovo nodo diventa la testa
      *testa = nuovo;
    }
    else
    {
      // Altrimenti, scorriamo fino alla fine della lista e aggiungiamo il nuovo nodo
      NodoSalvataggio *temp = *testa;
      while (temp->prossimo)
        temp = temp->prossimo;
      temp->prossimo = nuovo;
    }
  }
  fclose(f);
}
