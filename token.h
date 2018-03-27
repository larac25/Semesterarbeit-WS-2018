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
   void druckeToken(CLtext txtDaten);
   int getToken(ifstream &datei);
   ClattToken att;
private:
   void cleanToken();
   //void druckeTokenEbene(int ebene);
   int fillToken(int mode);
   char tokenName[64];
   ClToken *tokenChild;
   ClToken *tokenSibling;
   char *tokenInhalt;
   } ;

enum zustand { istStartTag, istEndTag } ;
