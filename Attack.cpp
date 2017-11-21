#include "Attack.h"

Attack::Attack()
{
    //ctor
}
voi Attack::CoupAttaqueEnergie(vector<int>& tableauDesAttaques)
{
    /// On aura quatre cases remplient de int correspondant aux différents coûts en énergies de l'attaque
    /// la case 1 correspondant au coût en énergie rock, etc...
    for(int i=0; i<4; i++)
    {
        m_coutAttaque.push_back(tableauDesAttaques[i])
    }
}
Attack::~Attack()
{
    //dtor
}
