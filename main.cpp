#include <iostream>
using namespace std;
#include "token.h"
#include <fstream>
#include <string.h>

int aktiv;
char auswahl;
string dateiname;
string suchbegriff;


int main()

{

    aktiv = 1;
    while (aktiv==1) {

    ifstream textDatei;
    CLtext txt;
    textDatei.open("lagerbestand.txt");
    txt.parseTxt(textDatei);
    textDatei.close();

    ifstream eingabe;
    ClToken *token;
    eingabe.open("modekatalog.xml");
    token=new ClToken;



    cout << "--------------------------------------" << endl;
    cout << "Herzlich Willkommen in unserem Onlineshop für Mode! Was möchten Sie als nächstes tun?" << endl;
    cout << "--------------------------------------" << endl;
    cout << "(t) Textdatei auslesen" << endl;
    cout << "(x) XML auslesen" << endl;
    cout << "(c) Dateien konvertieren" << endl;
    cout << "(s) Suchen" << endl;
    cout << "(h) Hilfe" << endl;
    cout << "(e) exit" << endl;
    cin >> auswahl;

    switch(auswahl)
         {

      case 't':
            txt.druckeTxt();
         break;

      case 'x':
            if (token->getToken(eingabe)!=0) token->druckeXml(txt);
            eingabe.close();
         break;

      case 'c':
          cout << "Wie soll die neue Datei heißen?" << endl;
          cin >> dateiname;
          if (token->getToken(eingabe)!=0) token->druckeToken(txt, dateiname);
          cout << "Ihre Datei wurde erstellt." << endl;
       break;

      case 's':
            cout << "Wonach möchten Sie suchen?" << endl;
            cin >> suchbegriff;
            if (token->getToken(eingabe)!=0) token->suche(txt, suchbegriff);
            break;

      case 'h':
            cout << "In diesem Programm können Sie verschiedene Optionen wählen. Wenn Sie die Textdatei auslesen möchten, dann drücken Sie (t). Wenn Sie die XML Datei lesen möchten, dann drücken Sie (x). Wenn Sie die Daten aus der XML und der Textdatei in eine gemeinsame XML Datei konvertieren möchten, dann drücken Sie (c). Eine Suchfunktion wird durch das auswählen von (s) bereitgestellt. Durch das Drücken von (e) wird das Programm beendet." << endl;
         break;

      case 'e':
            cout << "Sie haben das Programm beendet." << endl;
            aktiv=0;
         break;

      default:
         cout << "Was meinen Sie mit '" << auswahl << endl << "'?" << endl;
         }

}


}






