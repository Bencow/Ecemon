#ifndef TERRAIN_H
#define TERRAIN_H

#include "Carte.h"
#include "Special.h"
#include "Musicien.h"
#include "Style.h"

#include <stack>
#include <vector>



class Terrain
{
    public:
        Terrain();
        virtual ~Terrain();

        Carte *Getenjeu() { return m_enjeu; }
        void Setenjeu(Carte *val) { m_enjeu = val; }
        Special *GetspecialePersistante() { return m_specialePersistante; }
        void SetspecialePersistante(Special *val) { m_specialePersistante = val; }



    protected:

    private:
        std::vector<Carte> m_pioche;
        std::stack<Carte> m_cimetiere;
        std::vector<Style> m_styles;

        Carte *m_enjeu;
        Special *m_specialePersistante;
        Musicien *m_musicienActif;

};

#endif // TERRAIN_H
