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
        virtual ~Musicien();

        virtual int GetType(){return 1;}
        int GetLP() { return m_LP; }
        int GetHP(); // On retournera la valeur approprié
        void SetLP(int val) { m_LP = val; }
        void modifvie(int val){m_LP-=val;} // On enlève de la vie au musicien


    protected:

    private:
        int m_LP;
        Attack* m_attaque1; // J'en déclare deuxx car ça ne marche pas avec le vecteur
        Attack* m_attaque2;
};

#endif // MUSICIEN_H
