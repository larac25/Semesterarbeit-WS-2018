class CLtext{

public:

    int parseTxt(ifstream &textDatei);
    char *getKleidungsID(int anzahlDatensatz) {return kleidungsID[anzahlDatensatz];}
    char *getKleidungsGroesse(int anzahlDatensatz) {return kleidungsGroesse[anzahlDatensatz];}
    char *getKleidungsBestand(int anzahlDatensatz) {return kleidungsBestand[anzahlDatensatz];}
    int getAnzahlProdukt() {return anzahlProdukt;}
    void druckeTxt();

private:

    char zeichen;
    char puffer [100];
    int zaehler;
    char *kleidungsID [50];
    char *kleidungsGroesse [50];
    char *kleidungsBestand [50];
    int anzahlProdukt;

};

enum zustandtxt {inID, inGroesse, inAnzahl};


// den txt Parser habe ich komplett eigenständig entwickelt.
