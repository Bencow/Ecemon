#include <iostream>
#include "Carte.h"
#include "Terrain.h"


using namespace std;

int main()
{
    /// Tout ça c'est juste pour tester ma méthode vérificationJeu

    Carte* first= new Musicien();
    Carte* second= new Musicien();
    Carte* third= new Musicien();
    Carte* fourth= new Musicien();

    Terrain premier;
    Terrain deuxieme;

    premier.remplirPioche(first);
    premier.remplirPioche(second);

    deuxieme.remplirPioche(third);
    deuxieme.remplirPioche(fourth);

    premier.SetCondition();
    cout << endl;
    deuxieme.SetCondition();


    premier.DisplayTerrain();
    deuxieme.DisplayTerrain();
    cout << "La condition joueur 1: " << premier.Getcondition() << endl;
    cout << "La condition joueur 2: " << deuxieme.Getcondition() << endl;

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
