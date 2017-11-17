#include <iostream>

#include "Deck.h"

using namespace std;

Deck::Deck() : m_nom(""), m_jouable(false)
{
    //ctor
}

Deck::Deck(std::string nom) : m_nom(nom), m_jouable(false)
{

}

Deck::~Deck()
{
    //dtor
}

void Deck::afficherInfos()const
{
    cout << m_nom << endl;
    cout << m_tableau.size() << " cartes" << endl;
    if(m_jouable)
        cout << "jouable" << endl;
    else
        cout << "pas jouable" <<endl;
    ///Afficher le tableau de cartes !!!
}
