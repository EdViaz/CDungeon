#include "menu.h"
#include "combattimento.h"
#include "dungeon.h"
#include "giocatore.h"
#include "salvataggio.h"
#include "utilita.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Forward declarations
void gestisci_trucchi(Giocatore *g, NodoSalvataggio **lista);
void mostra_menu_salvataggi(Giocatore *g, NodoSalvataggio **lista);

// Legge un singolo carattere dall'input dell'utente e lo restituisce in minuscolo
char leggi_input_char()
{
  char b[100]; // Buffer per memorizzare l'input (100 caratteri max)

  // Legge una linea intera da stdin in modo sicuro
  if (fgets(b, sizeof(b), stdin))
  {
    // Rimuove il carattere di newline inserito automaticamente da fgets
    b[strcspn(b, "\n")] = 0;

    // Se l'utente ha premuto solo invio (input vuoto), restituisce 0
    if (strlen(b) == 0)
      return 0;

    // Se l'utente ha inserito solo uno spazio, lo restituisce
    if (strcmp(b, " ") == 0)
      return ' ';

    // Restituisce il primo carattere convertito a minuscolo
    return tolower(b[0]);
  }

  // Se fgets fallisce, restituisce 0
  return 0;
}

void mostra_menu_principale(NodoSalvataggio **lista, Giocatore *g)
{
  char in;
  const char *k_code = "wwssadadba ";
  int k_idx = 0;
  int cheat = 0;

  do
  {
    pulisci_schermo();
    printf("=== CDungeon ===\n\n");

    printf("1. Nuova Partita\n2. Carica Salvataggio\n");
    if (cheat)
      printf("3. Trucchi\n4. Esci\n");
    else
      printf("3. Esci\n\n");

    printf("Seleziona una delle opzioni del menu [1-%d]: ", cheat ? 4 : 3);

    in = leggi_input_char();
    if (isdigit(in))
    {
      // Converto il carattere in un intero
      int s = in - '0';

      // Gestione delle opzioni del menu
      if (s == 1)
      {
        inizializza_giocatore(g);
        mostra_menu_villaggio(g, lista);
      }
      else if (s == 2)
      {
        mostra_menu_salvataggi(g, lista);
      }
      else if (cheat && s == 3)
        gestisci_trucchi(g, lista);
      else
        return;
    }
    else
    {
      if (in == k_code[k_idx])
      {
        k_idx++;
        if (k_idx == strlen(k_code))
        {
          cheat = 1;
          k_idx = 0;
          printf("Trucchi Attivi!\n");
          getchar();
        }
      }
      else
      {
        k_idx = (in == 'w') ? 1 : 0;
      }
    }
  } while (1);
}

void mostra_menu_salvataggi(Giocatore *g, NodoSalvataggio **lista)
{
  stampa_salvataggi(*lista);
  printf("ID: ");
  int id = leggi_intero();
  if (id)
  {
    NodoSalvataggio *salv = carica_salvataggio(*lista, id);
    if (salv)
    {
      printf("\nScegli operazione:\n");
      printf("1. Carica\n2. Elimina\n0. Annulla\nScelta: ");
      int op = leggi_intero();
      if (op == 1)
      {
        *g = salv->dati_giocatore;
        printf("Salvataggio caricato.\n");
        getchar();
        mostra_menu_villaggio(g, lista);
      }
      else if (op == 2)
      {
        elimina_salvataggio(lista, id);
        getchar(); // Attendi invio per leggere messaggio
      }
    }
    else
    {
      printf("Salvataggio non trovato.\n");
      getchar();
      // mostra_menu_salvataggi(g, lista);
    }
  }
}

void mostra_menu_villaggio(Giocatore *g, NodoSalvataggio **lista)
{
  do
  {
    pulisci_schermo();
    printf("=== Menù Villaggio ===\nHP: %d/%d | Monete: %d\n", g->punti_vita, g->max_punti_vita, g->monete);

    printf("\n1. Intraprendi una missione\n2. Riposati\n3. Inventario\n4. Salva la partita\n5. Esci\n\n");

    printf("Seleziona una delle opzioni del menù [1-5]: ");

    // Gestione delle opzioni del menu
    int s = leggi_intero();
    switch (s)
    {
    case 1:
      mostra_menu_missione(g);
      break;
    case 2:
      g->punti_vita = g->max_punti_vita;
      printf("Riposato.\n");
      getchar();
      break;
    case 3:
      stampa_statistiche_giocatore(g);
      getchar();
      break;
    case 4:
      aggiungi_salvataggio(lista, g);
      getchar();
      break;
    case 5:
      return;
    }
  } while (1);
}

void mostra_menu_missione(Giocatore *g)
{
  do
  {
    pulisci_schermo();
    printf("=== Menù di Selezione Missioni ===\n\n");

    // Flag di controllo di quali missioni sono completate
    int f1 = g->missione_palude;
    int f2 = g->missione_magione;
    int f3 = g->missione_grotta;

    if (!f1)
      printf("1. Palude Putrescente\n");
    if (!f2)
      printf("2. Magione Infestata\n");
    if (!f3)
      printf("3. Grotta di Cristallo\n");
    if (f1 && f2 && f3)
      printf("4. Castello del Signore Oscuro (Boss Finale)\n");

    printf("0. Indietro\n\n");

    if (!f1 || !f2 || !f3)
      printf("Seleziona una delle opzioni del menu [1-3]: ");
    else if (f1 && f2 && f3)
      printf("Seleziona una delle opzioni del menu [4]: ");

    int s = leggi_intero();
    if (s == 0)
      return;

    // Esegui la missione selezionata
    if (s == 1 && !f1)
    {
      if (esegui_missione(g, 1, "Palude"))
        g->missione_palude = 1;
      else if (g->punti_vita <= 0)
        return;
    }
    else if (s == 2 && !f2)
    {
      if (esegui_missione(g, 2, "Magione"))
        g->missione_magione = 1;
      else if (g->punti_vita <= 0)
        return;
    }
    else if (s == 3 && !f3)
    {
      if (esegui_missione(g, 3, "Grotta"))
        g->missione_grotta = 1;
      else if (g->punti_vita <= 0)
        return;
    }
    else if (s == 4 && f1 && f2 && f3)
    {
      if (combattimento_boss_finale(g))
      {
        printf("\nHAI VINTO IL GIOCO!\n");
        getchar();
        return;
      }
      else
      {
        printf("\nGAME OVER.\n");
        g->punti_vita = 0;
        getchar();
        return;
      }
    }
  } while (1);
}

void mostra_negozio(Giocatore *g)
{
  do
  {
    pulisci_schermo();
    printf("=== Negozio (Monete: %d) ===\n", g->monete);
    printf("Oggetto \t| Descrizione \t\t\t| Costo\n");
    printf("----------------|-------------------------------|-------\n");
    printf("1. Cura \t| Ripristina punti vita (1-6) \t| 4 monete\n");
    if (!g->ha_spada)
      printf("2. Spada \t| Aumenta attacco (+1) \t\t| 5 monete\n");
    if (!g->ha_armatura)
      printf("3. Armatura \t| Riduce danno subito (-1) \t| 10 monete\n");
    printf("----------------|-------------------------------|-------\n");
    printf("0. Esci\n\n");
    printf("Seleziona un oggetto da acquistare: ");

    // Gestione delle opzioni del menu
    int s = leggi_intero();
    if (s == 0)
      return;

    if (s == 1 && g->monete >= 4)
    {
      g->monete -= 4;
      
      int punti_ripristinati = lancia_dado(6);
      g->punti_vita += punti_ripristinati;
      if (g->punti_vita > g->max_punti_vita)
        g->punti_vita = g->max_punti_vita;
      printf("Ripristinati %d punti vita.\n", punti_ripristinati);
    }
    else if (s == 2 && g->monete >= 5)
    {
      if (!g->ha_spada)
      {
        g->monete -= 5;
        g->ha_spada = 1;
        g->numero_oggetti++;
        printf("Spada acquistata.\n");
      }
    }
    else if (s == 3 && g->monete >= 10)
    {
      if (!g->ha_armatura)
      {
        g->monete -= 10;
        g->ha_armatura = 1;
        g->numero_oggetti++;
        printf("Armatura acquistata.\n");
      }
    }
    else
      printf("Non hai abbastanza monete.\n");
    getchar();
  } while (1);
}

void gestisci_trucchi(Giocatore *g, NodoSalvataggio **lista)
{
  do
  {
    pulisci_schermo();
    stampa_salvataggi(*lista);
    printf("Inserisci ID salvataggio (0 per uscire): ");
    int id = leggi_intero();
    if (id == 0)
      return;

    NodoSalvataggio *salv = carica_salvataggio(*lista, id);
    if (!salv)
    {
      printf("Salvataggio non trovato.\n");
      getchar();
      continue;
    }

    // Copia i dati dal salvataggio per lavorarci
    *g = salv->dati_giocatore;

    printf("\n--- TRUCCHI (Salvataggio ID: %d) ---\n", id);
    printf("1. Max Monete (999)\n");
    printf("2. Max HP (999)\n");
    printf("3. Sblocca Tutte le Missioni\n");
    printf("4. Torna indietro\n");
    printf("Scelta: ");

    int s = leggi_intero();
    int modificato = 0;

    if (s == 1)
    {
      salv->dati_giocatore.monete = 999;
      modificato = 1;
      printf("Monete impostate a 999!\n");
    }
    else if (s == 2)
    {
      salv->dati_giocatore.max_punti_vita = 999;
      salv->dati_giocatore.punti_vita = 999;
      modificato = 1;
      printf("HP impostati a 999!\n");
    }
    else if (s == 3)
    {
      salv->dati_giocatore.missione_palude = 1;
      salv->dati_giocatore.missione_magione = 1;
      salv->dati_giocatore.missione_grotta = 1;
      modificato = 1;
      printf("Tutte le missioni sbloccate!\n");
    }
    else if (s == 4)
    {
      continue;
    }

    if (modificato)
    {
      salva_tutto_su_file(*lista);
      printf("Salvataggio aggiornato su file.\n");
      // Aggiorna anche g per riflettere le modifiche se l'utente carica subito
      *g = salv->dati_giocatore;
    }
    getchar();

  } while (1);
}
