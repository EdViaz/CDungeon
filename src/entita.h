#ifndef ENTITA_H
#define ENTITA_H

typedef enum {
    ENTITA_NESSUNA,
    ENTITA_NEMICO,
    ENTITA_TRAPPOLA,
    ENTITA_VUOTA
} TipoEntita;

typedef struct {
    char nome[32];
    TipoEntita tipo;
    int danno;      // Per trappole o attacco nemico
    int punti_vita; // Per nemici
    int colpo_fatale; // Tiro di dado necessario per uccidere istantaneamente (o colpire)
    int ricompensa_monete;
    int e_boss;
} Entita;

#endif
