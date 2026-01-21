#ifndef STANZA_H
#define STANZA_H

typedef enum {
  STANZA_NESSUNA,
  STANZA_NEMICO,
  STANZA_TRAPPOLA,
  STANZA_VUOTA
} TipoStanza;

typedef struct {
  char nome[32];
  TipoStanza tipo;
  int danno;
  int colpo_fatale;
  int ricompensa_monete;
  int is_boss;
} Stanza;

#endif
