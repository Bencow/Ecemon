#ifndef MUSICIEN_H
#define MUSICIEN_H

#include "Carte.h"
#include "Attack.h"

#include <vector>
#include <iostream>


class Musicien : public Carte
{
    public:
        Musicien();
        Musicien(int tab_attaques[2][4]);///Marc rajoute les autres param�tres
        virtual ~Musicien();

        virtual int GetType(){return 1;}
        int GetLP() { return m_LP; }
        int GetHP(); // On retournera la valeur appropri�
        void SetLP(int val) { m_LP = val; }
        void modifvie(int val){m_LP-=val;} // On enl�ve de la vie au musicien

        void afficherCoutAttaque();

        //void attaquer(Terrain* ennemi);

    protected:

    private:
        int m_LP;
        Attack m_attaques[2];
};

#endif // MUSICIEN_H
