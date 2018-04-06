#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "token.h"

ClToken::ClToken()
{
*tokenName='\0';
tokenChild=NULL;
tokenSibling=NULL;
tokenInhalt=new char[1];
*tokenInhalt='\0';
}

int  ClToken::getToken(
ifstream              &datei)
{
int zaehler;
enum zustand zustand;
char zeichen;
char puffer[100];
ClToken *child;

cleanToken();

for (zaehler=0;;)
    {
    datei.get(zeichen);
    if (datei.eof())
       {
       if (*tokenName == '\0' && tokenChild == NULL && tokenInhalt == NULL)
          return fillToken(0);
       return fillToken(1);
       }
    switch(zeichen)
       {
    case '<':
       datei.get(zeichen);
       if (zeichen=='/')
          {
          zustand = istEndTag;
          if (zaehler!=0)
             {
             puffer[zaehler]='\0';
             tokenInhalt = new char[zaehler+1];
             strcpy(tokenInhalt,puffer);
             }
          }
       else
          {
          datei.putback(zeichen);
          if (*tokenName!='\0')
             {
             datei.putback('<');
         if (tokenChild==NULL)
            {
                tokenChild=new ClToken;
                tokenChild->getToken(datei);
        }
         else
            {
        for (child=tokenChild;;child=child->tokenSibling)
            {
            if (child->tokenSibling==NULL)
               {
               child->tokenSibling=new ClToken;
               child->tokenSibling->getToken(datei);
               break;
               }
            }
        }
             }
          else zustand=istStartTag;
          }
       zaehler=0;
       break;
    case '>':
       puffer[zaehler]='\0';
       if (zustand==istEndTag) return fillToken(1);
       if (zustand==istStartTag)
          {
          att.getAttList(puffer);
          strcpy(tokenName,puffer);
          }
       zaehler=0;
       break;
    case '\n':
       break;
    default:
       puffer[zaehler]=zeichen;
       zaehler++;
       break;
       }
    }
}

int ClToken::fillToken(
int                    mode)
{
if (*tokenName=='\0')
   strcpy(tokenName,"Unbekanntes Element");
if (tokenInhalt==NULL)
   {
   tokenInhalt=new char[1];
   *tokenInhalt='\0';
   }

return mode;
}

void ClToken::cleanToken(void)
{
*tokenName='\0';
if (tokenChild!=NULL)
   {
   delete tokenChild;
   tokenChild=NULL;
   }
if (tokenInhalt!=NULL)
   {
   delete tokenInhalt;
   tokenInhalt=NULL;
   }
}

void ClToken::druckeXml(CLtext txtDaten) //drucke Funktion um nur xml zu lesen und auszugeben
{

cout << "<" << name();

        if (att.zahlAtt() > 0)
           {
           for (int i=0;i<att.zahlAtt();i++)
               {
               cout << " " << att.zeigeAttName(i) << "="
                    << '"' << att.zeigeAttWert(i) << '"';

               }
           }

       cout << "> ";

cout << inhalt();

if (tokenChild!=NULL) tokenChild->druckeXml(txtDaten);


cout << " </" << name() << ">" << endl;


if (tokenSibling!=NULL) tokenSibling->druckeXml(txtDaten);


}

void ClToken::druckeToken(CLtext txtDaten, string nameNeu) //drucke Funktion um Dateien zu konvertieren
{


// Hier habe ich die Datenübergabe getestet
/*cout << "kleidungsID[0]: " << txtDaten.getKleidungsID(0);
cout << "kleidungsID[5]: " << txtDaten.getKleidungsID(5);
cout << "kleidungsID[2]: " << txtDaten.getKleidungsID(2);  */


ofstream neueDatei;

neueDatei.open(nameNeu, ios::app);

neueDatei << "<" << name();

        if (att.zahlAtt() > 0)
           {
           for (int i=0;i<att.zahlAtt();i++)
               {
               neueDatei << " " << att.zeigeAttName(i) << "="
                    << '"' << att.zeigeAttWert(i) << '"' << ">" << endl;



               for(int j=0;j<=5;j++)
               {
                   if(strcmp(att.zeigeAttWert(i), txtDaten.getKleidungsID(j))==0) //ich vergleiche die ID's im XML Dokument und im txt Dokument, um die txt Daten an der richtigen Stelle einzufügen
                   {
                       neueDatei << "<Metadaten> " << endl;
                       neueDatei << "<Groesse> " << txtDaten.getKleidungsGroesse(j) << " </Groesse>" << endl;
                       neueDatei << "<Bestand> " << txtDaten.getKleidungsBestand(j) << " </Bestand>" << endl;
                       neueDatei << "</Metadaten>" << endl;
                   }
               }


               }
           }

neueDatei << "> ";
neueDatei << inhalt();
if (tokenChild!=NULL) tokenChild->druckeToken(txtDaten, nameNeu);


neueDatei << " </" << name() << ">" << endl;


if (tokenSibling!=NULL) tokenSibling->druckeToken(txtDaten, nameNeu);

neueDatei.close();

}

//--------------------------------------------------------------------------
// TEST SUCHFUNKTION


void ClToken::suche(CLtext txtDaten, string search) //Suchfunktion
{

    if (tokenChild!=NULL) tokenChild->suche(txtDaten, search);

    if (tokenSibling!=NULL) tokenSibling->suche(txtDaten, search);


    //cout << search << endl; // Hier habe ich getestet, ob die Usereingabe ankommt


    char gesucht[30];
    strcpy(gesucht, search.c_str());  // Hier habe ich den string in ein char array umgewandelt

    //cout << gesucht << endl;

    if(strcmp(inhalt(),gesucht)==0) // Ich vergleiche den Suchbegriff mit inhalt (tokenInhalt)
    {

        cout << "<" << name();

        if (att.zahlAtt() > 0)
           {
           for (int i=0;i<att.zahlAtt();i++)
               {
               cout << " " << att.zeigeAttName(i) << "="
                    << '"' << att.zeigeAttWert(i) << '"';

               }
           }

       cout << "> ";

cout << inhalt();

cout << " </" << name() << ">" << endl;


    }
}

