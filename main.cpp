#include <iostream>
using namespace std;
#include "token.h"
#include <fstream>


int main()

{
    cout << "Parse txt" << endl;
    ifstream textDatei;
    CLtext txt;
    textDatei.open("lagerbestand.txt");
    //txt.parseTxt(textDatei);


    ifstream eingabe;
    ClToken *token;
    eingabe.open("modekatalog.xml");
    token=new ClToken;



    if (token->getToken(eingabe)!=0) token->druckeToken(txt);


    eingabe.close();
    textDatei.close();
}




//gehört zum XML Parser
/*{
ifstream eingabe;
ClToken token;
eingabe.open("modekatalog.xml");
for (;;)
    {
    if (token.getToken(eingabe)==0) break;
    cout << "Token: " << token.start() << " - " << token.inhalt() << " - " << token.end() << endl;
    for (int i=0;i<token.att.zahlAtt();i++)
        cout << "Attribut " << token.att.zeigeAttName(i) << " hat den Wert "
             << token.att.zeigeAttWert(i) << endl;
    }
eingabe.close();
}

//gehört zum DTD Parser
{
ifstream eingabe;
CLdtd dtd;
char dateiname[80];
cout << "DTD-Dateiname: " << endl;
cin >> dateiname;
eingabe.open(dateiname);
if (!eingabe)
   {
   cout << "Die Datei konnte nicht geöffnet werden." << endl;
   return 1;
   }
dtd.verarbeite(eingabe);
eingabe.close();
}
*/
