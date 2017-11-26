#include "Attack.h"

#include <vector>
#include <iostream>

Attack::Attack()
{
    //ctor
}
void Attack::CoupAttaqueEnergie(int tableauDesAttaques[4])
{
    /// On aura quatre cases remplient de int correspondant aux différents coûts en énergies de l'attaque
    /// la case 1 correspondant au coût en énergie rock, etc...
    for(int i=0; i<4; i++)
    {
        m_coutAttaque[i] = tableauDesAttaques[i];
    }
}
Attack::~Attack()
{
    //dtor
}

void Attack::setCoutAttaques(int tab[4])
{
    for(int i = 0 ; i < 4 ; i++)
    {
        m_coutAttaque[i] = tab[i];
    }
}

int Attack::getAttaque(int i)
{
    return m_coutAttaque[i];
}
