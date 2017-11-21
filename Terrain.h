#ifndef TERRAIN_H
#define TERRAIN_H

#include "Carte.h"
#include "Special.h"
#include "Musicien.h"
#include "Style.h"
#include "Player.h"

#include <stack>
#include <vector>

class Terrain
{
public:
    Terrain();
    virtual ~Terrain();

    Carte *Getenjeu()
    {
        return m_enjeu;
    }
    void Setenjeu(Carte *val)
    {
        m_enjeu = val;
    }
    Special *GetspecialePersistante()
    {
        return m_specialePersistante;
    }
    void SetspecialePersistante(Special *val)
    {
        m_specialePersistante = val;
    }

    /// Ce que j'ai rajouté
    void remplirPioche(Carte* unecarte); /// On s'en fou
    Carte* PiocherCarte(int faconDePiocher);
    int verificationJeu(); /// A améliorer absolument, doit contenir tous les cas possibles !!!!
    void DisplayTerrain() const; // Affichage du terrain

    void MusicienAttaque(Terrain* cible); // Pour attaquer la cible et avoir le numéro  de l'attaque.
    void Setlife(int hitpoints);
    void SetlifePlayer(int hitpoints); // On enlève de la vie au player, est appelé dans le setlife ci-dessus
    bool GetpresenceMusicien()const; // Pour savoir si il y a un musicien présent
    int musicienCapaciteAttaquer(); /// A compléter
    void effetCarteSpecial(); // Effet de la carte spécial, à compléter

    void TourDeJeu();
    void finTourDeJeu();

    void SetCondition() // on attribue à m_condition la valeur verificationJeu()
    {
        m_condition=verificationJeu();
    }
    int Getcondition()
    {
        return m_condition;
    }

protected:

private:
    std::vector<Carte*> m_pioche; // J'ai ms en pointeur pour le remplissage dans la méthode remplirpioche tu vas comprendre
    std::stack<Carte*> m_cimetiere;
    std::vector<Style*> m_styles;
    int m_condition; // pour savoir si il peut continuer à jouer

    Player* m_joueur; /// Pour qu'on ait un joueur, je n'arrive pas à accéder à cet objet dans les méthodes de terrain.cpp
    Carte* m_enjeu;
    Special* m_specialePersistante;
    Musicien* m_musicienActif;
    Terrain* m_ennemi;

};

#endif // TERRAIN_H
