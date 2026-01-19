# [CT0441] INTRODUZIONE ALLA PROGRAMMAZIONE

# (CTR3) - a.a. 2025/

# Progetto

## December 9, 2025

Questo documento contiene le linee guida per la realizzazione del progetto.

## 1 Il Progetto

Il progetto consiste nello sviluppo di un videogioco che segua una semplice trama di avventura e com-
battimento di un gioco di ruolo con generazione procedurale dei dungeons (https://it.wikipedia.
org/wiki/Dungeon). Il giocatore interpreter`a i panni di un eroe coraggioso, inviato dal capo del vil-
laggio per contrastare l’avanzata dell’armata delle tenebre e porre fine al dominio del temibile Signore
Oscuro. Durante il gioco, il protagonista dovr`a esplorare ambienti ostili, affrontare potenti nemici, e
raccogliere oggetti o potenziamenti utili alla sua missione. L’obiettivo finale `e raggiungere il castello
del Signore Oscuro e sconfiggerlo in uno scontro epico!

## 2 Menu Iniziale di Gioco

Il menu di gioco dovr`a far scegliere al giocatore una delle seguenti azioni:

1. Nuova Partita: permette di iniziare una nuova avventura da zero.
2. Carica Salvataggio: permette di continuare una partita salvata in precedenza.
3. Trucchi (opzione nascosta): permette di modificare le statistiche del giocatore e sbloccare la
    missione finale.


```
Esempio di schermata
Menu Principale:
```
1. Nuova partita
2. Carica Salvataggio
Seleziona una delle opzioni del menu [1-2]:

### 2.1 Nuova Partita

Inizier`a una nuova partita dove all’avvio verr`a creato l’eroe della storia, che inizier`a con 20 punti
vita, 0 monete, 0 oggetti, 0 missioni completate. Vedi la Sezione 3 per lo svolgimento e le
regole del gioco.

### 2.2 Carica Salvataggio

I caricamenti permettono a un giocatore di riprendere il gioco da uno dei punti precedentemente salvati.
In questo menu verr`a visualizzata la lista di salvataggi (i salvataggi sono ”illimitati” e non sovrascrivi-
bili). I salvataggi dovranno inoltre contenere le seguenti informazioni: data e ora del salvataggio, punti
vita del personaggio, monete del personaggio, numero di oggetti, e missioni completate.
Una volta selezionato un salvataggio sar`a possibile caricare la partita precedentemente salvata
oppure decidere di eliminare il salvataggio.
Esempio di schermata
Carica Salvataggio:

1. 11 -10 -2025 15:03:29 , 19 P. VITA , 20 MONETE , 3 OGGETTI , 1 MISSIONI COMPLETATE
2. 21 -09 -2025 11:49:58 , 2 P. VITA , 1 MONETE , 1 OGGETTI , 2 MISSIONI COMPLETATE
Seleziona un salvaggio [1-2]: 1
Seleziona un opzione per il salvataggio 1:
1. Carica
2. Elimina
Seleziona opzione [1 -2]:
Se si seleziona Carica, la partita verr`a caricata e riapparir`a il Menu del Villaggio con le statistiche,
oggetti e missioni completate riguardanti il salvataggio caricato.
Se si seleziona Elimina, prima di eliminare il salvataggio sar`a visualizzato un messaggio di avviso
del tipo ”Sei sicuro di voler eliminare definitivamente il salvataggio? [Si/No]”.

### 2.3 Trucchi

L’opzione trucchi `e inizialmente nascosta agli utenti. Per renderla visibile `e necessario inserire da
tastiera il famoso codice Konami! Codice Konami (variante wasd): w w s s a d a d b a [Spazio] (vedi
https://it.wikipedia.org/wiki/Codice_Konami)
Hint: Riguardo questa funzionalit`a, `e stato affrontato un problema simile nel es. 1 della lezione
04/12/2025 di esercitazioni.
Esempio di schermata per visualizzare il menu dei trucchi
Menu Principale:

1. Nuova partita
2. Carica Salvataggio
Seleziona una delle opzioni del menu [1-2]: w
Seleziona una delle opzioni del menu [1-2]: w
Seleziona una delle opzioni del menu [1-2]: s
Seleziona una delle opzioni del menu [1-2]: s
Seleziona una delle opzioni del menu [1-2]: a
Seleziona una delle opzioni del menu [1-2]: d
Seleziona una delle opzioni del menu [1-2]: a
Seleziona una delle opzioni del menu [1-2]: d
Seleziona una delle opzioni del menu [1-2]: b
Seleziona una delle opzioni del menu [1-2]: a
Seleziona una delle opzioni del menu [1-2]: (space character)
Menu Principale:
1. Nuova partita
2. Carica Salvataggio


3. Trucchi
Seleziona una delle opzioni del menu [1-3]: 3

Selezionando questa opzione si potr`a selezionare un salvataggio e modificare punti vita del personaggio,
monete del personaggio, e sbloccare la missione finale Castello del Signore Oscuro.

## 3 Svolgimento del Gioco

Il giocatore ad ogni nuova partita o caricamento di partita, parte dal Menu del Villaggio:

1. Intraprendi una missione: vedi Sezione 3.
2. Riposati : ripristina tutti i Punti vita del giocatore (riporta a 20 Punti vita il personaggio)
3. Inventario: `e possibile visualizzare i Punti vita del personaggio, le Monete e gli oggetti in suo
    possesso.
4. Salva la partita: vedi Sezione 3.
5. Esci : vedi Sezione 3.

```
Esempio del menu in gioco
Menu del Villaggio:
```
1. Intraprendi una missione
2. Riposati
3. Inventario
4. Salva la partita
5. Esci
Seleziona una delle opzioni del menu [1-5]:

### 3.1 Intraprendi una missione

Prima di poter accedere al castello del Signore Oscuro, `e necessario completare 3 missioni in 3 dungeons
diversi:

1. Palude Putrescente - Missione: Sconfiggi 3 Generale Orco del Signore Oscuro.
2. Magione Infestata - Missione: Recupera la chiave del Castello del Signore Oscuro, e sconfiggi
    un Vampiro Superiore.
3. Grotta di Cristallo - Missione: Recupera la spada del’Eroe.

```
Esempio del menu in gioco
Menu di Selezione Missione:
```
1. Palude Putrescente
2. Magione Infestata
3. Grotta di Cristallo
Seleziona una delle opzioni del menu [1-3]:
Ogni volta che una di queste missioni verr`a completata, verr`a rimossa dal menu di selezione delle
missioni. Quando tutte verranno completate, apparir`a la missione finale per il Castello del
Signore Oscuro:
4. Castello del Signore Oscuro - Missione Finale: Sconfiggi il Signore Oscuro.


3.1.1 Svolgimento all’interno di una Missione

All’interno della missione `e presente il seguente Menu di Missione, dove viene indicata la missione da
compiere, i dati relativi al suo completamento, e le opzioni disponibili:

1. Esplora stanza del Dungeon: permette di progredire all’interno del Dungeon, e combattere nemici
    ai fini delle missioni.
2. Negozio: permette di acquistare oggetti utili. Vedi Tabella 1 per gli oggetti acquistabili.
3. Inventario: `e possibile visualizzare i Punti vita del personaggio, le Monete e gli oggetti in suo
    possesso.
4. Torna al Villaggio: richiede di aver soddisfatto i criteri della missione, oppure il pagamento di
    50 Monete (paga per completare la missione), per tornare al Menu del Villaggio.

```
Table 1: Negozio
Oggetto Descrizione Monete
Pozione Curativa Ripristina fino a 6 Punti Vita (lancia un dado a 6 facce) 4
Spada +1 all’attacco dell’eroe (acquistabile una volta sola) 5
Armatura -1 al danno del nemico/trappola (acquistabile una volta sola) 10
```
```
Esempio di menu di missione per Palude Putrescente
```
```
Obiettivo: Eliminare 3 Generale Orco.
Stato di avanzamento: Eliminati 1 su 3 Generale Orco.
Menu di Missione:
```
1. Esplora stanza del Dungeon
2. Negozio
3. Inventario
4. Torna al Villaggio (Paga 50 Monete)
Seleziona una delle opzioni del menu [1-4]:

Creazione del Dungeon e delle Stanze Una volta selezionata una missione verr`a generato in
modo automatico e procedurale un dungeon, che possa soddisfare i requisiti per la missione. Fino
ad un massimo di 10 stanze. Ogni stanza viene scelta casualmente lanciando un dado a 6 facce, e
selezionando il valore corrispondente dalla colonna Tiro Dado in base alla tabella della relativa missione
: Tabella 2 (Palude Putrescente), Tabella 3 (Magione Infestata), e Tabella 4 (Grotta di Cristallo). N.B.
Essendo una scelta casuale, una stanza dello stesso tipo potrebbe apparire pi`u volte! Nel caso non
si sia raggiunto casualmente il requisito della missione prima delle 10 stanze, queste condizioni vanno
forzate.
Esempio con Palude Putresecente. L’obiettivo `e Eliminare 3 Generale Orco.
Se viene generato il seguente Dungeon casualmente va bene:
Dungeon:
Stanza 1: Goblin // generato casualmente (risultato del dado: 2)
Stanza 2: Generale Orco // generato casualmente (risultato del dado: 6)
Stanza 3: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 4: Generale Orco // generato casualmente (risultato del dado: 6)
Stanza 5: Generale Orco // generato casualmente (risultato del dado: 6)
perch`e ha meno di 10 stanze, e contiene 3 Generale Orco che permettono di soddisfare la missione.
Supponiamo invece di avere generato solo stanze on Cane Selvaggi.
Dungeon:
Stanza 1: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 2: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 3: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 4: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 5: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 6: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 7: Cane Selvaggio // generato casualmente (risultato del dado: 1)


arrivati alla stanza 7, dopo dovr`o forzare la condizione che permettono di soddisfare la missione.
Cio`e aggiungere i 3 Generale Orco.

```
Dungeon:
Stanza 1: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 2: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 3: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 4: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 5: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 6: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 7: Cane Selvaggio // generato casualmente (risultato del dado: 1)
Stanza 8: Generale Orco // forzato , non generato casualmente
Stanza 9: Generale Orco // forzato , non generato casualmente
Stanza 10: Generale Orco // forzato , non generato casualmente
```
Esplora stanza del Dungeon Quando il giocatore entra in una stanza essa pu`o essere vuota,
contenere, una trappola, oppure un combattimento.
Nel caso di una stanza vuota, non succede nulla, e si torner`a nella schermata del Menu di Missione,
spostanto il puntatore alla stanza successiva.
Nel caso delle trappole, si subisce l’effetto malevolo indicato nella tabella corrispettiva, e si torner`a
nella schermata del Menu di Mission, spostanto il puntatore alla stanza successiva.
In caso di combattimento con un nemico, lanciare un dado a 6 facce, questo sar`a il valore di
attacco dell’eroe, se il risultato `e pi`u alto del numero nella colonna Colpo Fatale, allora il nemico
sar`a sconfitto, si ricever`a il corrispettivo premio in monete, e si torner`a nella schermata del Menu di
Missione, spostanto il puntatore alla stanza successiva. In caso contrario, se il numero del dado `e pi`u
basso, l’eroe ricever`a un danno pari a quello indicato dalla tabella. A questo punto si ritirer`a il dado
e lo scontro andr`a avanti fino a quando il nemico oppure il personaggio del giocatore verr`a sconfitto
(punti vita azzerati). In questo ultimo caso, se il personaggio del giocatore verr`a sconfitto verr`a
visualizzata una schermata di GAME OVER (es: ”Sei stato sconfitto!”) e verr`a visualizzato il
Menu Iniziale di Gioco.
Esempio di combattimento con Scheletro (Palude Putrescente), dove l’eroe parte con 20 punti vita.

L’eroe incontra un Scheletro e inizia il combattimento.

```
Viene lanciato un dado per stabilire l’attacco dell ’eroe
Il risultato: 1.
Attacco non sufficiente per sconfiggere lo scheletro (1 < Colpo Fatale =2).
Lo scheletro infligge 2 danni all ’eroe. L’eroe rimane con 18 punti vita.
Viene lanciato un dado per stabilire l’attacco dell ’eroe
Il risultato: 4.
Lo scheletro viene sconfitto (4 > 2). L’eroe rimane con 18 punti vita , e riceve 4 monete.
```
Table 2: Dungeon - Palude Putrescente. * il valore `e 5 se si `e in possesso della spada dell’Eroe.° il
valore dipende dal risultato di un dado a 6 facce.
Tiro Dado Stanza Tipologia Colpo Fatale Danno Monete
1 Cane Selvaggio Combattimento 2 1 -
2 Goblin Combattimento 3 2 2
3 Scheletro Combattimento 4 2 4
4 Orco Combattimento 3 4 6
5 Acquitrino Velenoso Trappola - 1-6° -
6 Generale Orco Combattimento 6* 3 12

3.1.2 Svolgimento all’interno della Missione Finale

La missione finale `e diversa da quelle precedenti.


```
Table 3: Dungeon - Magione Infestata. * ottieni anche la chiave del Castello del Signore Oscuro
Tiro Dado Stanza Tipologia Colpo Fatale Danno Monete
1 Botola Buia Trappola - 3 -
2 Pipistrello Combattimento 2 2 1
3 Zombie Combattimento 3 2 2
4 Fantasma Combattimento 5 2 4
5 Vampiro Superiore Combattimento 4 4 7
6 Demone Custode Combattimento 4 6 10*
```
Table 4: Dungeon - Grotta di Cristallo. * lancia una moneta, se esce testa ottieni le monete, altrimenti
subisci il danno.° il valore dipende dal risultato di un dado a 6 facce.† prima di infliggere il danno,
il Drago chiede al giocatore di riconoscere ([Si/No]) se un numero intero (generato casualmente tra
1 e 500) appartiene o meno alla sequenza di Padovan (https://en.wikipedia.org/wiki/Padovan_
sequence), in caso di risposta corretta il danno `e pari a 0. ’ ottieni anche la spada dell’eroe. La spada
dell’eroe `e un oggetto permette di fare +2 all’attacco dell’eroe (se gi`a equipaggiata va a sostituire
Spada)
Tiro Dado Stanza Tipologia Colpo Fatale Danno Monete
1 Stanza Vuota - - - -
2 Cristalli Cadenti Trappola - 2 -
3 Ponte Pericolante Trappola - - -
4 Forziere Misterioso Trappola - 2* 10*
5 Rupe scoscesa Trappola - 1-6° -
6 Drago Antico Combattimento 5 10 † 12’

Il combattimento con il Signore Oscuro, avviene come il gioco del Rock-paper-scissors (vedi regole
https://it.wikipedia.org/wiki/Rock-paper-scissors_(giochi)). Dove per`o la roccia corrispon-
der`a ad uno scudo, la carta and una magia, e le forbici alla spada. Il giocatore dovr`a vincere 3 su 5
round per sconfiggere il Signore Oscuro.
Esempio di schermata
Scontro Finale | Round 2 su 5 | Eroe 1 - Signore Oscuro 1.
Mosse disponibili

1. Scudo
2. Magia
3. Spada
Seleziona una delle opzioni del menu [1-3]: 1
Il Signore Oscuro nel frattempo ha scelto la Spada.

L’eroe para e si difende dalla Spada del Signaore Oscuro. L’eroe si aggiudica il Round.

In caso di sconfitta dell’eroe da parte del Signore Oscuro, avverr`a un GAME OVER e si torner`a al
Menu Iniziale di Gioco
In caso di vittoria del personaggio, il Signore Oscuro sar`a sconfitto, e il gioco terminer`a con una
scritta di vittoria (es: ”Congratulazioni hai vinto!”).

### 3.2 Salva la partita

Selezionando questa opzione dal Menu del Villaggio `e possibile salvare la partita, aggiungendo il
salvataggio alla lista dei salvataggi, in modo che possa essere ricaricato successivamente dal Menu
Iniziale di Gioco.

### 3.3 Esci

Selezionando questa opzione dal Menu del Villaggio tornare al Menu Iniziale di Gioco.
Nel caso in cui il giocatore corrente richieda di uscire, `e richiesto che venga visualizzato un messaggio
di avvertenza e che esso venga confermato (es: ”Stai uscendo dal gioco ricordati di salvare
la partita per non perdere i tuoi progressi. Sei sicuro di voler procedere? [Si/No]”).


Nota: i salvataggi possono essere gestiti in ”memoria”, senza la necessit`a di scrivere/leggere su file
(non trattato nel corso di IaP).

## 4 FAQ - Regole del Gioco

- Quanti sono i punti vita massimi dell’eroe? Il massimo `e 20 punti vita.
- Cosa significa salvataggi ”illimitati”? Non `e previsto un numero definito di salvataggi, per
    tanto `e fortemente consigliata una lista dinamica per gestire i salvataggi all’interno del gioco.
- Posso evitare una trappola oppure un combattimento? Non `e possibile evitare una
    trappola oppure un combattimento.
- La salute dell’eroe viene ripristinata automaticamente quando esce da una stanza?
    No, l unico modo `e usare pozioni oppure riposare al villaggio.
- Cosa significa che la Spada da +1 all’attacco? Dopo il lancio del dado per attaccare viene
    aggiunto 1 al risultato.

### 4.1 FAQ - Implementazione

- Va utilizzata una struttura dati specifica per implementare il gioco? No, `e lasciato agli
    studenti l’onere di decidere come e quali strutture dati utilizzare.
- Sono permessi tool per la generazione del codice e testo (es. AI, LLMs... )? No,
    l’uso `e severamente vietato. Qualora vi sia evidenza oppure anche solo il sospetto che siano
    stati utilizzati strumenti non consentiti, il progetto o il report non verranno valutati.
- Sono permesse librerie di terze parti e/o interfaccie grafiche?E possibile implementare`
    l’intero gioco utilizzando semplicemente la standard library di C, usando le funzioni di lettura
    dei tasti come scanf, getc o getchar e le funzioni di stampa come printf. Coloro che vogliono
    cimentarsi nell’uso di librerie esterne per dare una veste grafica ed interazioni col giocatore pi`u
    accattivanti e fluide possono farlo, tuttavia sar`a propria responsabilit`a occuparsi degli aspetti di
    portabilit`a e compatibilit`a. Il programma deve compilare e funzionare correttamente su sistemi
    Linux e Windows; in caso contrario, `e necessario documentare e motivare opportunamente la
    scelta nella relazione che accompagner`a il progetto ed in sede d’esame.
- Sono permessi comandi di sistema per pulire il terminale (es. System("clear"))?
    S`ı, tuttavia queste funzioni non sono state trattate a lezione. Pertanto spetta agli studenti
    comprenderne il funzionamento e l’utilizzo. Inoltre, `e loro responsabilit`a occuparsi degli aspetti
    di portabilit`a e compatibilit`a tra i diversi sistemi operativi.
- Sono permessi comandi per leggere e scrivere su file per gestire il salvataggio/carica-
    mento S`ı, sono permesse. Tuttavia, il loro utilizzo non `e richiesto poich ́e l’argomento non `e stato
    trattato a lezione. E quindi possibile implementare il salvataggio/caricamento direttamente in`
    memoria, sebbene i dati andranno persi al termine dell’esecuzione del programma (Questo non
    andr`a a incidere negativamente sul punteggio finale).
- Ho problemi con l’inserimento del codice Konami, come posso risolvere? Nel es. 1
    della lezione 04/12/2025 di esercitazioni, `e stato affrontato e risolto un problema simile. Le
    principali problematiche sono tipicamente l’acquisizione dello [SPAZIO] e che l’input buffer va a
    registrare il tasto [INVIO] quando si va a inserire un carattere.
- Posso aggiungere funzionalit`a/varianti al gioco? S`ı, tuttavia, `e necessario includere an-
    che una versione che rispetti le specifiche fornite. La mancata realizzazione di questa versione
    comporter`a una penalizzazione, anzich ́e l’assegnazione di eventuali punti extra.


## 5 Consegna

Quando? Il progetto deve essere consegnato rispettando le deadline notificate e presenti su Moodle.
Le deadline per la consegna, sono tipicamente impostate 1/2 settimane prima della data dell’esame, per
permettere al docente di prendere approfondita visione dei progetti consegnati. E’ sempre obbligatorio
iscriversi all’appello di “Esercizi” del prof. Olivieri per sostenere la discussione del progetto.
Dove? Il docente abiliter`a la consegna tramite Moodle secondo le scadenze previste.
Cosa? Dovrete consegnare un unico file zip contenente:

1. Una relazione scritta al massimo di 3 pagine, che descriva la struttura del vostro progetto,
    l’organizzazione del lavoro tra i componenti del gruppo, le principali difficolt`a incontrate. Re-
    lazioni pi`u lunghe verranno penalizzate. L’uso di tool per la generazione testuale (es. AI, LLMs,
   ... ) `e severamente vietato. Qualora vi sia evidenza oppure anche solo il sospetto che siano stati
    utilizzati strumenti non consentiti, la relazione non verr`a valutata.
2. Il codice sorgente del progetto in linguaggio C99; il progetto dovr`a compilare opportunamente con
    il compilatore GCC. Inoltre, dovr`a essere fornita la linea di comando per la compilazione
    del progetto tramite terminale Linux (Ubuntu), oppure opzionalmente fornire un Make-
    file (vedi ad esempio: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
    oppure https://www.gnu.org/software/make/manual/make.html).
3. Documentazione delle funzioni, dei tipi e dei file generate con Doxygen (vedi ad esempio: https:
    //www.doxygen.nl/manual/docblocks.html).

## 6 Valutazione

Il progetto `e da svolgere in gruppi di max 4 studenti. La composizione dei gruppi `e libera. In casi
eccezionali (es. studenti lavoratori,... ), il progetto potr`a essere sviluppato anche individualmente se
concordato con il prof. Olivieri.
Il progetto sar`a valutato in trentesimi e andr`a a pesare il 30% del voto finale. Il progetto dovr`a
essere sufficiente (un voto maggiore o uguale a 18) per poter verbalizzare il voto finale.
Il progetto verr`a valutato indicativamente come segue:

Progetto di Gruppo

- progetto sufficiente, se permette di avviare una partita, implementa almeno 2 delle 3 missioni,
    implementa la logica del negozio, implementa la missione finale e il combattimento finale.
- progetto buono, se implementa il precedente punto, tutte e 3 le missioni, implementa l’opzione
    di salvataggio e caricamento, ed il menu per i trucchi; Vanno gestiti anchecasi specialicome
    l’inserimento di mosse o valori non validi;
- progetto ottimo, se implementa correttamente i precedenti punti, la sequenza di Padovan viene
    implementata con funzioni ricorsive, e viene fornita una documentazioneDoxygenesaustiva
    del progetto;

N.B.:Le valutazioni terranno anche conto della qualit`a e correttezza dell’implementazione come
anche la completezza delle regole e vincoli di gioco.
Importante: Il progetto `e di gruppo, ma la valutazione `e individuale. Questo significa che i compo-
nenti di un gruppo potrebbero ricevere un voto diverso. Inoltre, tutti i membri del gruppo devono
conoscere ogni riga del codice!

Progetto Individuale (ad esempio per studenti lavoratori)

- progetto sufficiente, se permette di avviare una partita, implementa almeno 1 delle 3 missioni,
    implementa la logica del negozio, implementa la missione finale e il combattimento finale.
- progetto buono, se implementa il precedente punto, almeno 2 delle 3 missioni, ed il menu per i
    trucchi; Vanno gestiti anchecasi specialicome l’inserimento di mosse o valori non validi;


- progetto ottimo, se implementa correttamente i precedenti punti, tutte e 3 le missioni, l’opzione
    di salvataggio e caricamento, la sequenza di Padovan viene implementata con funzioni ricorsive,
    e viene fornita una documentazioneDoxygenesaustiva del progetto;


