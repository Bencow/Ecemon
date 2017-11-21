#ifndef STYLE_H
#define STYLE_H

#include "Carte.h"


class Style : public Carte
{
    public:
        Style();
        virtual ~Style();

        virtual int GetType(){return 3;}
        void Settype(int val) { m_type = val; }
        int returnTypeEnergie();

    protected:

    private:
        int m_type;/// 1,2,3,4 en fonction du type de carte énergie
};

#endif // STYLE_H
