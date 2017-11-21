#include "Terrain.h"
#include <iostream>

using namespace std;

Terrain::Terrain():m_joueur(NULL), m_musicienActif(NULL) // Il n'y a pas de musicien posé initialement
{
    string nom1;
    nom1="Mozart";
    m_joueur= new Player(nom1);
    //ctor
}
Terrain::~Terrain()
{
    delete m_joueur;
    //dtor
}
void Terrain::remplirPioche(Carte* unecarte) /// Méthode pour tester mon code, du bullllshit !
{
    m_pioche.push_back(unecarte);
}
void Terrain::DisplayTerrain()const
{
    /// Ca va planter car m_musicienActif est NULL
    /// Ce qui n'arrivera pas puisque si il n'y a plus de carte musiciens, le jeu s'arrête.

    /// Problème avec le polymorphisme... ligne 88 de ce code

    cout << "Nom du joueur: " << m_joueur->Getnom() << endl;
    cout << "Vie du joueur: " << m_joueur->Getvie() << endl;
    cout << "Nom de la carte active: " << m_musicienActif->Getname() << endl;
    cout << "Vie de la carte active: " << m_musicienActif->GetLP() << endl;
}
void Terrain::effetCarteSpecial()
{
    /// La carte spéciale agit, à compléter rapidement.
    /// Fonctionne avec l'attribut m_specialePersistante.
}
int Terrain::musicienCapaciteAttaquer()
{
    int carteEnergie1(0);
    int carteEnergie2(0);
    int carteEnergie3(0);
    int carteEnergie4(0);

    for(int i=0; i<m_styles.size(); i++)
    {
        if(m_styles[i]->returnTypeEnergie()==1) // Si c'est une carte énergie de type 1
        ++carteEnergie1; // On incrémente le nombre d'énergies de type 1
        if(m_styles[i]->returnTypeEnergie()==2)
        ++carteEnergie2;
        if(m_styles[i]->returnTypeEnergie()==3)
        ++carteEnergie3;
        if(m_styles[i]->returnTypeEnergie()==4)
        ++carteEnergie4;
    }

    /// A compléter, renvoie un int en fonction de l'attaque qu'il peut faire, relation avec le nombre d'énergies
}
Carte* Terrain::PiocherCarte(int faconDePiocher)
{
    if(faconDePiocher==1)
    {
        ///On pioche normalement, doit retourner la carte piocher
        /// et décaler toutes les places de la piche d'une case...
    }
    else if(faconDePiocher==2)
    {
        /// Déroule et pioche jusqu'à tomber sur une créature
        /// On devrait utiliser une file, bcp plus simple
        /// Doit retourner la carte piocher
        /// et décaler toutes les places de la piche d'une case...
    }
}
void Terrain::TourDeJeu()
{
    Carte* carteTempon; // Carte tempon qui va servir pour récupérer la carte piocher et agir en fonction
    bool choixPlacerCarte(0);
    int typeDePiochage(0);
    bool voirCarteEnergie;

    m_joueur->Setfin(false); /// On actualise son état (mort ou vivant)
    m_joueur->Setjouer(false); /// Veut dire qu'il n'a pas encore joué
    m_joueur->SetTourperso(true); /// On met à true pour qu'il puisse effectuer une fois la boucle de jeu

while(m_joueur->GetTourPerso()&&!m_joueur->Getfin()) // Tant que le joueur peut jouer et qu'il ne passe pas son tour
    {
        SetCondition(); /// On regarde ce qu'il peut faire

        if(!m_joueur->Getjouer()) // Si il n'a pas encore joué
        {
            if(Getcondition()==1) /// On joue normalement
            {
                typeDePiochage=1; // Cas du piochage simple
                effetCarteSpecial(); // La carte spécial agît si il y en a une

                SetCondition();/// on vérifie si on est toujours dans la bonne condition(la carte spéciale peut tout changer)
                if(Getcondition()==1)
                {
                    carteTempon = PiocherCarte(typeDePiochage); /// Pioche une carte normalement, envoie le int adapté

                    if(carteTempon->GetType()==1) // Si c'est une carte créature
                    {
                        cout << "Voulez-vous remplacer la carte musicien ";
                        cout << "présente par celle-ci ou non? oui(1,2,3...), non(0)" << endl;
                        cin >> choixPlacerCarte;

                        if(choixPlacerCarte) // On remplace la carte
                        {
                            m_pioche->push_back(m_musicienActif); /// Faire un new ?
                            m_musicienActif=carteTempon; /// Ne marche pas car pas du même type, comment faire ?
                            MusicienAttaque(m_ennemi); // attaque de l'ennemi
                        }
                        if(!choixPlacerCarte) // On remet la carte tiré en dessous de la pioche
                        {
                            m_pioche->push_back(carteTempon);
                        }
                    }
                    if(carteTempon->GetType()==2) // Si c'est une carte spéciale
                    {
                        cout << "Voulez-vous remplacer la carte spéciale ";
                        cout << "présente par celle-ci ou non? oui(1,2,3...), non(0)" << endl;
                        cin >> choixPlacerCarte;

                        if(choixPlacerCarte)
                        {
                            /// On ajoute la carte au cimetière
                            m_specialePersistante=carteTempon;
                            effetCarteSpecial();
                        }
                        if(!choixPlacerCarte)
                        {
                            /// Va au cimetière ou non en fonction de la caractéristique
                            /// de la carte, méthode à implémenter

                            /// if elle ne va pas au cimetière, fait effet
                        }
                    }
                    if(carteTempon->GetType()==3)
                    {
                        m_styles->push_back(carteTempon); // On ajoute la style au tas d'énergie
                    }

                }

            }
            if(Getcondition()==2)
            {
                typeDePiochage=2;// Cas du piochage complexe
                effetCarteSpecial(); // La carte spécial agît si il y en a une
                carteTempon = PiocherCarte(typeDePiochage); /// Pioche jusqu'à avoir une créature
                m_musicienActif=carteTempon; // Le musicien prend la valeur de la carte pioché
                MusicienAttaque(m_ennemi); // attaque de l'ennemi
            }
            if(Getcondition()==3)
            {
                // il a perdu, donc on met fin à true
                m_joueur->Setfin(true);
            }
            if(Getcondition()==4) // Il n'a qu'une carte musicien sur le terrain
            {
                MusicienAttaque(m_ennemi); // attaque de l'ennemi
            }
            if(Getcondition()==5)
            {
                m_joueur->Setfin(true);
            }
            if(Getcondition()==6)
            {
                m_joueur->Setfin(true);
            }
        }

        m_joueur->Setjouer(true); /// On met la variable à true pour ne pas répéter la boucle de jeu
        finTourDeJeu(); /// Déroulement de la fin du jeu
    }
}
void Terrain::finTourDeJeu() /// Déroulement de la fin du jeu
{
    int voirCarteEnergie(0);

    cout << "Voulez-vous voir vos cartes energies ?" << endl;
    cin>> voirCarteEnergie;

    if(voirCarteEnergie)
    {
        /// Faire défiler les cartes...
    }
    if(!voirCarteEnergie) // Il ne peut rien faire d'autre alors il passe son tour
    {
        cout << "on passe à l'autre joueur!" << endl;
        m_joueur->SetTourperso(false);
    }
}
int Terrain::verificationJeu() /// Du coup il marche du feu de DIEUUUUUU
{
    int validation(0);
    bool resteCarteDeck(false); // Pour savoir si il reste des cartes dans le deck
    bool resteCreatureDeck(false);// Pour savoir si il reste des cartes créature dans le deck
    bool carteCreatureSurTerrain(false); // Pour savoir si il y a une créature sur le terrain

    for (int i=0; i< m_pioche.size(); i++)
    {
        if(m_pioche[i]->GetType()==1||m_pioche[i]->GetType()==2||m_pioche[i]->GetType()==3)
        {
            resteCarteDeck=true; // Si il y a une carte, on met à true carte
        }
        if(m_pioche[i]->GetType()==1)
        {
            resteCreatureDeck=true; // Même chose mais pour savoir si il ya des créatures
        }
    }
    carteCreatureSurTerrain=GetpresenceMusicien(); // On regarde si il y a une créature

    if (resteCarteDeck) /// Si il lui reste des cartes
    {
        if(carteCreatureSurTerrain)
        {
            cout << m_joueur->Getnom() << " joue, tout va bien" << endl;
            /// Pioche normalement
            return 1; // Il joue
        }
        if(!carteCreatureSurTerrain)
        {
            if(resteCreatureDeck)
            {
                return 2;
                ///Pioche jusqu'à avoir une créature
            }
            if(!resteCreatureDeck)
            {
                cout <<m_joueur->Getnom() <<" a des cartes dans son deck mais plus de creatures nulle part.";
                cout << "Il a donc perdu." << endl;
                return 3;
                /// Il a perdu.
            }
        }
    }
    else if(!resteCarteDeck)
    {
        if(carteCreatureSurTerrain)
        {
            if(musicienCapaciteAttaquer()==1||musicienCapaciteAttaquer()==2||musicienCapaciteAttaquer()==3)
            {
                cout << m_joueur->Getnom() << " attaque." << endl;
                return 4; /// Il continue car il lui reste une carte créture sur le terrain
            }
            if(!(musicienCapaciteAttaquer()==1&&musicienCapaciteAttaquer()==2&&musicienCapaciteAttaquer()==3))
            {
                cout << m_joueur->Getnom() <<" n'a plus de deck, et sa carte active de ne peux plus attaquer, il a perdu  " << endl;
                return 5;
            }
        }
        if(!carteCreatureSurTerrain)
        {
            cout << m_joueur->Getnom() <<" n'a plus aucune carte, il a perdu" << endl;
            return 6; /// Il a perdu car il n'a plus de cartes dans le deck et sur le terrain
        }
    }
    else
        return 0;
}
void Terrain::MusicienAttaque(Terrain* cible)
{
    int choixDeAttaque(0);

    if(cible->GetpresenceMusicien())// Si il y a un musicien adverse, on l'attaque
    {
        if(musicienCapaciteAttaquer()==1) /// Le joueur ne peut faire que l'attaque 1, pas le choix
            cible->Setlife(1/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
        if(musicienCapaciteAttaquer()==2) /// Le joueur ne peut faire que l'attaque 2, pas le choix
            cible->Setlife(1/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);

        if(musicienCapaciteAttaquer()==3)/// Le joueur peut faire les deux attaques
        {
            if(choixDeAttaque==1)
                cible->Setlife(1/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
            if(choixDeAttaque==2)
                cible->Setlife(1/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
        }
    }

}
void Terrain::Setlife(int hitpoints) /// On enlève de la vie au musicien
{
    int excesDegat(0);

    if(m_musicienActif->GetLP()>=hitpoints) // Si sa vie est supérieur aux HP
    {
        m_musicienActif->modifvie(hitpoints);
    }
    if(m_musicienActif->GetLP()<hitpoints) // Sinon...
    {
        excesDegat=hitpoints-m_musicienActif->GetLP();

        m_musicienActif->modifvie(m_musicienActif->GetLP()); // On met sa vie à zéro
        SetlifePlayer(excesDegat); // L'excès de dégât est infligé au player
    }
}
void Terrain::SetlifePlayer(int hitpoints) /// On modifie la vie du joueur, seulement si il y a un excès de dégât
{
    m_joueur->modifVie(hitpoints);
}
bool Terrain::GetpresenceMusicien() const
{
    if(m_musicienActif!=NULL)
    {
        return true; // Si il y a un musicien sur le plateau de jeu, alors on renvoie true
    }
    else
    {
        return false;
    }
}
