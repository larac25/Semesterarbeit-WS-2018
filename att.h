#pragma once

class ClattToken
   {
private:
   int anzahlAtt;
   char *attName[10];
   char *attValue[10];
public:
   int getAttList(char *eingabe);
   char *zeigeAttName(int id) {return attName[id];}
   char *zeigeAttWert(int id) {return attValue[id];}
   int zahlAtt() {return anzahlAtt;}
   };


//den Attribute Header habe ich aus der Vorlesung übernommen.
