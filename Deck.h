#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>

#include "Carte.h"

class Deck
{
    public:
        Deck();
        virtual ~Deck();

        std::string Getnom() { return m_nom; }
        void Setnom(std::string val) { m_nom = val; }
        bool Getjouable() { return m_jouable; }
        void Setjouable(bool val) { m_jouable = val; }

    protected:

    private:
        std::string m_nom;
        std::vector<Carte> m_tableau;
        bool m_jouable;
};

#endif // DECK_H
