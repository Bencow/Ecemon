//Bonjour !
#include <iostream>
#include <vector>

#include "main.h"
#include "Carte.h"
#include "Joueur.h"

using namespace std;

void ajouterJoueur(vector<Joueur> tousLesJoueurs)
{
 //Joueur nouveau();



 //tousLesJoueurs.push_back(nouveau);
 ///si on sauvegarde à la fin pas besoin de rentrer dans les joueurs
}
void afficherTouslesJoueurs(vector<Joueur> tousLesJoueurs)
{

    for(unsigned int i = 0 ; i < tousLesJoueurs.size() ; i ++)
    {
        ///A faire avec Allegro plus tard
        //cout << i+1 << tousLesJoueurs[i] << endl;
    }
}

void afficherToutesLesCartes(vector<Carte*> toutesLesCartes)
{
    for(unsigned int i = 0 ; i < toutesLesCartes.size() ; i ++)
    {
        ///A faire avec Allegro plus tard
        cout << "taille du vecteur : " << toutesLesCartes.size() << endl;
    }
}



void menuPrincipal()
{
    vector<Carte*> toutesLesCartes;
    vector<Joueur> tousLesJoueurs;

    int choix(0);
    int choixJoueur(-1);

    ///MARC à toi de jouer : charger tous les fichiers dans ces deux vecteurs
    //chargerToutesLesCartes();
    //chargerTousLesJoueurs();

    while(!(choix >= 1 && choix <= 5))//Tant qu'on ne choisit pas une action valide (différente de quitter)
    {
        while(choix != 5)
        {
            cout << "== Menu Principal ==" << endl
                 << "Que Voulez-Vous faire" << endl
                 << "1. Ajouter un joueur " <<endl
                 << "2. Gerer un joueur " <<endl
                 << "3. Jouer une partie" <<endl
                 << "4. Acceder au parametres" << endl
                 << "5. Quitter" << endl;
            cin >> choix;

            switch(choix)
            {
            case 1://Ajouter un joueur
                ajouterJoueur(tousLesJoueurs);///MARC implementer cette fonction
                break;
            case 2://Gerer un joueur
                ///Ajouter Blindage
                while(!(choix >= 1 && choix <= tousLesJoueurs.size()))
                {
                    cout << "Voici la liste de tous les joueurs enregistres" << endl
                         << "Selectionnez-en un ou entrez 0 pour quitter" << endl;
                    afficherTouslesJoueurs(tousLesJoueurs);
                    cin >> choixJoueur;
                    if(choixJoueur != 0)
                    {
                        ///Le menu pour gérer un joueur est dans joueur.cpp
                        tousLesJoueurs[choixJoueur+1].gererJoueur(toutesLesCartes);
                    }
                //sinon on retourne au menu
                }
                break;

            case 3://Jouer une partie

                ///Jouer(); //!!! Mathieu au Boulot !!!
                break;

            case 4:// Acceder aux paramètres
                ///On verra ça plus tard ! #bonusZou
                break;
            case 5://Quitter
                cout << "Au revoir 1" << endl;
                ///MARC S
                break;
            default://sinon
                cout << "Veuillez entrer un des choix proposes" << endl;
                break;

            }
        }
    }
}









int main()
{
    menuPrincipal();
    return 0;
}
