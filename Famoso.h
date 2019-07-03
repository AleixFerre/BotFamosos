#ifndef FAMOSO_H
#define FAMOSO_H
#include <iostream>

using namespace std;


class Famoso {

    public:
        Famoso();
        Famoso(string _nom);

        void set_nom(string _nom);

        string get_nom() const;

        bool operator>=(Famoso f)const;
        bool operator==(Famoso f)const;

    private:
        string nom;
};

#endif // FAMOSO_H
