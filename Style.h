#ifndef STYLE_H
#define STYLE_H

#include "Carte.h"



class Style : public Carte
{
    public:
        Style();
        virtual ~Style();

        virtual int GetType(){return 3;}
        int returnStyle();

    protected:

    private:
        int m_style;/// 0,1,2,3 en fonction du type de carte énergie
};

#endif // STYLE_H
