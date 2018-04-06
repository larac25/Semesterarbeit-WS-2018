#pragma once
#include "att.h"
#include "text.h"

class ClToken
   {
public:
   ClToken();
   char *name() { return tokenName; }
   ClToken *child() { return tokenChild; }
   char *inhalt() { return tokenInhalt; }
   void druckeToken(CLtext txtDaten, string nameNeu); //drucke Funktion zum konvertieren der Daten
   void druckeXml(CLtext txtDaten); // drucke Funktion vom XML Parser
   void suche(CLtext txtDaten, string search); // TEST SUCHFUNKTION
   int getToken(ifstream &datei);
   ClattToken att;

private:
   void cleanToken();
   int fillToken(int mode);
   char tokenName[64];
   ClToken *tokenChild;
   ClToken *tokenSibling;
   char *tokenInhalt;
   } ;

enum zustand { istStartTag, istEndTag } ;


//ich habe mich an dem token Header aus der Vorlesung orientiert und diesen dann eigenständig weiterentwickelt und angepasst.
