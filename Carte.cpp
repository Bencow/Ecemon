#include "Carte.h"

#include <iostream>

using namespace std;

Carte::Carte()
{
    //ctor
}
void Carte::display()
{
    cout << "Nom de la carte: " << Carte::Getname()<< endl
    <<"Type de la carte: " << Carte::Getdescription() << endl;
}
Carte::~Carte()
{
    //dtor
}
