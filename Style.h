#ifndef STYLE_H
#define STYLE_H

#include "Carte.h"


class Style : public Carte
{
    public:
        Style();
        virtual ~Style();

        int Gettype() { return m_type; }
        void Settype(int val) { m_type = val; }

    protected:

    private:
        int m_type;
};

#endif // STYLE_H
