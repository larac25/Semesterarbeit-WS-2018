#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "text.h"

enum zustandtxt zustandtxt;

void CLtext::parseTxt(ifstream &textDatei){

    for (zaehler=0,zustandtxt=inID;;)
        {
        textDatei.get(zeichen);
        if (textDatei.eof()) break;
       switch(zeichen)
          {
       case ' ':
          if (zustandtxt == inID)
             {
             zustandtxt = inGroesse;
             puffer[zaehler] = '\0';
             kleidungsID[anzahlProdukt] = new char[zaehler+1];
             strcpy(kleidungsID[anzahlProdukt],puffer);
             //cout << "ID(puffer): " << puffer;
             cout << "ID: " << kleidungsID[anzahlProdukt];
             zaehler = 0;
             }
         else if (zustandtxt == inGroesse)
          {
              zustandtxt = inAnzahl;
              puffer[zaehler] = '\0';
              kleidungsGroesse[anzahlProdukt] = new char[zaehler+1];
              strcpy(kleidungsGroesse[anzahlProdukt],puffer);
              //cout << " Groesse: " << puffer;
              cout << " Groesse: " << kleidungsGroesse[anzahlProdukt];
              zaehler = 0;
          }
           break;

       case'\n':
           zustandtxt = inID;
           puffer[zaehler] = '\0';
           kleidungsBestand[anzahlProdukt] = new char[zaehler+1];
           strcpy(kleidungsBestand[anzahlProdukt],puffer);
           //cout << " Anzahl: " << puffer << endl;
           cout << " Anzahl: " << kleidungsBestand[anzahlProdukt] << endl;
           zaehler = 0;
           anzahlProdukt++;
           break;

       default:
             puffer[zaehler] = zeichen;
             zaehler++;
          break;
          }
       }

    /*cout << "kleidungsID[0]: " << kleidungsID[0];
    cout << "kleidungsID[5]: " << kleidungsID[5];
    cout << "kleidungsID[2]: " << kleidungsID[2];*/ //test

}
