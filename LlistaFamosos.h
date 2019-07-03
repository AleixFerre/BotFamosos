#ifndef LLISTAFAMOSOS_H
#define LLISTAFAMOSOS_H
#include <Famoso.h>
#include <iostream>

using namespace std;

class LlistaFamosos {
    public:
        //******CONSTRUCTORS - DESTRUCTOR******
        LlistaFamosos();
        LlistaFamosos(const LlistaFamosos &o);
        ~LlistaFamosos();

        //******OPERADORS******
        LlistaFamosos &operator=(const LlistaFamosos &o);

        //******CONSULTORS******
        bool existeix(Famoso e) const;
        bool buida() const;
        void llistar() const;
        int mida() const;
        Famoso get_by_pos(int id) const;

        ////******MODIFICADORS******
        void inserir(Famoso e);
        void esborrar(Famoso e);

    private:
        //Inv: els nodes estan ordenats creixentment segons la dada
        struct Node {
            Famoso dada;
            Node *seg;
        };
        Node *a_inici;
        int a_n;

        void copiar(const LlistaFamosos &o);
        void alliberar();
};

#endif // LLISTAFAMOSOS_H
