#pragma once

class CLdtd
{
private:

    void verarbeite(ifstream& datei);
    void druckeelement(struct element *jetzt);

public:

};

enum zustanddtd {direktive, element, abhaengig, noise};
