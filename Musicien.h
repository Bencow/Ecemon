#ifndef MUSICIEN_H
#define MUSICIEN_H

#include "Carte.h"
//#include "Attack"
#include <vector>
#include <iostream>

class Musicien : public Carte
{
    public:
        Musicien();
        virtual ~Musicien();

        int GetLP() { return m_LP; }
        void SetLP(int val) { m_LP = val; }

    protected:

    private:
        int m_LP;
        //std::vector<Attack> m_attacks;
};

#endif // MUSICIEN_H
