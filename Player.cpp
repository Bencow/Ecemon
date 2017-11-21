#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string nom1): m_vie(30), m_jouer(false), m_fin(false), m_tourFinPerso(true), m_nom(nom1)
{

}
void Player::modifVie(int degat)
{
    m_vie-=degat; // On enlève à la vie les pointts de dégâts
}
bool Player::verificationVie(bool valeur) // On envoie récupère une valeure qui nous informe si l'on veut forcer la mort du joueur.
{
    if (valeur)
        return true;
    else
    {
        return Getmort();
    }
}

bool Player::SetTourperso(bool modif)
{
    m_tourFinPerso=modif;
}
bool Player::Setjouer(bool modif)
{
    m_jouer=modif;
}
bool Player::Setfin(bool valeur)
{
    m_fin=verificationVie(valeur);
}
string Player::Setnom(string nom)
    {
        m_nom=nom;
    }
Player::~Player()
{
    //dtor
}
