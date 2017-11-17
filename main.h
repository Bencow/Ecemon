#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <vector>

#include "Joueur.h"
#include "Carte.h"

void ajouterJoueur(std::vector<Joueur> tousLesJoueurs);
void afficherTouslesJoueurs(std::vector<Joueur> tousLesJoueurs);
void afficherToutesLesCartes(std::vector<Carte*> toutesLesCartes);


void menuPrincipal();



#endif // MAIN_H_INCLUDED

