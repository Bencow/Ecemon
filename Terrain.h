#ifndef TERRAIN_H
#define TERRAIN_H

#include <stack>
#include <vector>
#include <deque>

#include "Carte.h"
#include "Style.h"
#include "Special.h"
#include "Musicien.h"
#include "Player.h"

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

    /// Ce que j'ai rajout�
    void remplirPioche(Carte* unecarte); /// On s'en fou
    Carte* PiocherCarte();
    int verificationJeu(); /// A am�liorer absolument, doit contenir tous les cas possibles !!!!
    void DisplayTerrain() const; // Affichage du terrain

    void MusicienAttaque(Terrain* cible); // Pour attaquer la cible et avoir le num�ro  de l'attaque.
    void Setlife(int hitpoints);
    void SetlifePlayer(int hitpoints); // On enl�ve de la vie au player, est appel� dans le setlife ci-dessus
    bool GetpresenceMusicien()const; // Pour savoir si il y a un musicien pr�sent
    int musicienCapaciteAttaquer(); /// A compl�ter
    void effetCarteSpecial(); // Effet de la carte sp�cial, � compl�ter

    void melangerPioche();
    void JouerNormalement(Carte* carteTempon);

    void TourDeJeu();
    void finTourDeJeu();

    void SetCondition() // on attribue � m_condition la valeur verificationJeu()
    {
        m_condition=verificationJeu();
    }
    int Getcondition()
    {
        return m_condition;
    }

protected:

private:
    std::deque<Carte*> m_pioche; // J'ai ms en pointeur pour le remplissage dans la m�thode remplirpioche tu vas comprendre
    std::stack<Carte*> m_cimetiere;
    std::vector<Style*> m_styles[4];///preciser les 4 styles

    int m_condition; // pour savoir si il peut continuer � jouer

    Player* m_joueur; /// Pour qu'on ait un joueur, je n'arrive pas � acc�der � cet objet dans les m�thodes de terrain.cpp
    Carte* m_enjeu;
    Special* m_specialePersistante;
    Musicien* m_musicienActif;
    Terrain* m_ennemi;

};

#endif // TERRAIN_H
