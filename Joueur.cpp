#include <vector>
#include <iostream>

#include "Joueur.h"
#include "main.h"

using namespace std;

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::acheterCarte(Carte* nouvelle)
{
    m_collection.push_back(nouvelle);
    m_argent -= nouvelle->Getprix();
}

void Joueur::creerDeck(string nom)
{
    Deck nouveau(nom);
    m_decks.push_back(nouveau);
}

void Joueur::afficherTousLesDecks()const
{
    for(unsigned int i = 0 ; i < m_decks.size() ; i++)
    {
        cout << i << ". ";
        m_decks[i].afficherInfos();
    }
}



void Joueur::gererJoueur(vector<Carte*> toutesLesCartes)
{
    int choix(0), choixCarteAchetee(0);
    int choixDeck(-1);
    int argentAjoute(-1);
    string nomNouveauDeck;

    while(!(choix >= 1 && choix <= 5))//Tant qu'on ne choisit pas une action valide
    {
        while(choix != 5)
        {
            cout << "== Menu Joueur ==" << endl
                 << "Que voulez vous faire" << endl
                 << "1. Gerer votre argent" << endl
                 << "2. Acheter cartes" << endl
                 << "3. Creer un nouveau Deck" << endl
                 << "4. Gerer un deck existant" << endl
                 << "5. Revenir au menu principal" << endl;
            cin >> choix;

            switch(choix)
            {
            case 1:///Gerer votre argent
                while(argentAjoute != 0)
                {
                    cout << "Vous avez actuellement " << m_argent << " euros sur votre compte" <<endl
                         << "Voulez vous en ajoutez ?" << endl
                         << "Si oui, tappez le montant a ajouter" <<endl
                         << "Sinon, tappez 0 pour revenir au menu Joueur" <<endl;
                    cin >> argentAjoute;

                    if(argentAjoute != 0)
                    {
                        cout << "Vous avez desormais " << m_argent << " sur votre compte" << endl;
                    }
                }
                break;

            case 2:///Acheter cartes

                cout << "Voici les cartes disponibles dans le magasin" << endl;
                afficherToutesLesCartes(toutesLesCartes);
                cout << "voulez vous en acheter une ?" << endl
                     << "Si oui tappez le numero de la carte que vous voulez acheter" << endl
                     << "Sinon tappez 0 pour revenir au menu" << endl;
                cin >> choixCarteAchetee;

                acheterCarte(toutesLesCartes[choixCarteAchetee + 1]);//On ajoute 1 car la première case du vecteur est 0

                cout << toutesLesCartes[choixCarteAchetee + 1]->Getname() << " a bien ete ajoute a votre collection" << endl
                     << "Il vous reste maintenant " << m_argent << " euros sur votre compte" << endl;

                break;
            case 3:///Creer un nouveau Deck
                cout << "Comment voulez-vous appeler votre nouveau Deck" << endl;
                cin >> nomNouveauDeck;

                creerDeck(nomNouveauDeck);

                cout << "Vous avez ajoute le Deck " << nomNouveauDeck << " a votre collection" << endl;

                break;
            case 4:///Gerer un Deck Existant

                while(choixDeck != 0)
                {
                    cout << "Voici la liste de tous les decks que vous possedez" << endl;
                    afficherTousLesDecks();
                    cout << "Selectionnez-en un ou entrez 0 pour quitter" << endl;

                    cin >> choixDeck;

                    m_selection = &m_decks[choixDeck + 1]; //plus un car première case vecteur = 0
                }

                break;
            case 5:///Revenir au menu Principal
                break;
            }
        }
    }


}



