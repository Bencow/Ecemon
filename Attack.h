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
        void CoupAttaqueEnergie(std::vector<int>& tableauDesAttaques); // Re�ois un vecteur envoy� depuis le main, rempli le nombre
                                                                        // D'�nergies n�c�ssaires

        /// Faire une fonction retournant un vecteur de co�t en �nergie de l'attaque.
    protected:

    private:
        std::string m_name;
        std::vector<int> m_coutAttaque; /// Attribut contenant dans chaque case le nombre d'�nergies n�c�ssaire � l'attaque
        int m_HP;
};

#endif // ATTACK_H
