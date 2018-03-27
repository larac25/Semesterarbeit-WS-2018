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

void ClToken::druckeToken(CLtext txtDaten)
{


/*cout << "kleidungsID[0]: " << txtDaten.getKleidungsID(0);
cout << "kleidungsID[5]: " << txtDaten.getKleidungsID(5);
cout << "kleidungsID[2]: " << txtDaten.getKleidungsID(2);  *///Datenübergabe getestet


cout << "<" << name();
        if (att.zahlAtt() > 0)
           {
           for (int i=0;i<att.zahlAtt();i++)
               {
               cout << " " << att.zeigeAttName(i) << "="
                    << '"' << att.zeigeAttWert(i) << '"';
               }
           }
cout << "> " << endl;
cout << inhalt() << endl;


if (tokenChild!=NULL) tokenChild->druckeToken(txtDaten);


cout << "</" << name() << ">" << endl;


if (tokenSibling!=NULL) tokenSibling->druckeToken(txtDaten);


// wir versuchen die textdaten an der richtigen Stelle einzufügen
/*if (att.zahlAtt() > 0)
   {
    if(strcmp(att.zeigeAttWert(0), txtDaten.getKleidungsID(0)))
    {
        cout << "test";
    }

   }*/

}

