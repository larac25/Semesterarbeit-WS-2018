#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "dtd.h"

struct element
   {
   int zahl;
   char name[64];
   char tags[10][64];
   } ;

void CLdtd::verarbeite(ifstream& datei)
{
char zeichen, letztes;
char puffer[100];
int zaehler;
enum zustanddtd zustanddtd = noise;
struct element *jetzt;
for (datei.get(zeichen);!datei.eof();datei.get(zeichen))
    {
    switch(zeichen)
       {
    case '<':
       zustanddtd=direktive;
       zaehler=0;
       jetzt=new struct element;
       jetzt->zahl=0;
       break;
    case '>':
       if (zustanddtd!=noise)
          {
      if (letztes!=' ')
         {
             puffer[zaehler]='\0';
             strcpy(jetzt->tags[jetzt->zahl],puffer);
         jetzt->zahl++;
         }
          CLdtd::druckeelement(jetzt);
      }
       zustanddtd=noise;
       break;
    case ' ':
       if (letztes==' ') continue;
       puffer[zaehler]='\0';
       zaehler=0;
       switch(zustanddtd)
          {
       case direktive:
          if (strcmp(puffer,"!ELEMENT"))
         {
         cout << endl << "Diese Direktive verstehe ich nicht: " << puffer;
         zustanddtd=noise;
         }
      else zustanddtd=element;
          break;
       case element:
          strcpy(jetzt->name,puffer);
      zustanddtd=abhaengig;
          break;
       case abhaengig:
          strcpy(jetzt->tags[jetzt->zahl],puffer);
      jetzt->zahl++;
          break;
      }
       break;
    default:
       if (zustanddtd!=noise) puffer[zaehler] = zeichen;
       zaehler++;
       break;
       }
    letztes=zeichen;
    }
cout << endl;
}
void CLdtd::druckeelement(
struct element    *jetzt)
{
cout << endl << "Element " << jetzt->name << " enthält die Tags: ";
for (int i=0;i<jetzt->zahl;i++)
    {
    if (i>0) cout << ", ";
    cout << jetzt->tags[i];
    }
cout << ".";
}
