#include "Musicien.h"

using namespace std;

Musicien::Musicien()
{
    //ctor
}

Musicien::Musicien(int tab_attaques[2][4])
{
    for(int i = 0 ; i < 2 ; i++)
    {
        m_attaques[i].setCoutAttaques(tab_attaques[i]);
    }
}

int Musicien::GetHP()
{


    /// On récupérera l'attaque grâce à la struct attack
}
Musicien::~Musicien()
{
    //dtor
}

void Musicien::afficherCoutAttaque()
{
    int tab[4];

    for (int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            tab[j] = m_attaques[i].getAttaque(j);
        }

        cout << "attaque: " << i << endl;

        for(int j = 0 ; j < 4 ; j++)
        {
            cout << tab[j] << " ";
        }
        cout << endl;
    }
}


