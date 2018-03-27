class CLtext{

public:

    void parseTxt(ifstream &textDatei);
    char *getKleidungsID(int anzahlDatensatz) {return kleidungsID[anzahlDatensatz];}
    char *getKleidungsGroesse(int anzahlDatensatz) {return kleidungsGroesse[anzahlDatensatz];}
    char *getKleidungsBestand(int anzahlDatensatz) {return kleidungsBestand[anzahlDatensatz];}
    int getAnzahlProdukt() {return anzahlProdukt;}

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
