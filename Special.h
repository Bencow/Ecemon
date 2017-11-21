#ifndef SPECIAL_H
#define SPECIAL_H

#include "Carte.h"
#include <iostream>


class Special : public Carte
{
    public:
        Special();
        virtual ~Special();

        virtual int GetType(){return 2;} // retourne
        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        std::string Getdescription() { return m_description; }
        void Setdescription(std::string val) { m_description = val; }

    protected:

    private:
        std::string m_name;
        std::string m_description;
};

#endif // SPECIAL_H
