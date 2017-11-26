#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <vector>

class Attack
{
    public:
        Attack();
        virtual ~Attack();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }
        void CoupAttaqueEnergie(int tableauDesAttaques[4]); // Reçois un vecteur envoyé depuis le main, rempli le nombre
                                                                        // D'énergies nécéssaires
        void setCoutAttaques(int tab[4]);
        int getAttaque(int i);

        /// Faire une fonction retournant un vecteur de coût en énergie de l'attaque.
    protected:

    private:
        std::string m_name;
        int m_coutAttaque[4]; /// Attribut contenant dans chaque case le nombre d'énergies nécéssaire à l'attaque
        int m_HP;
};

#endif // ATTACK_H
