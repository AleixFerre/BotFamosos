#include "LlistaFamosos.h"

LlistaFamosos::LlistaFamosos() {
// Pre:--; Post: llista buida
    a_inici = NULL;
    a_n = 0;
}
LlistaFamosos::LlistaFamosos(const LlistaFamosos &o) {
// Pre:--; Post: la llista és còpia de o
    a_inici = NULL;
    a_n = 0;
    copiar(o);
}

bool LlistaFamosos::existeix(Famoso e) const {
// Pre:--; Post: ens diu si e existeix a la llista
    Node *p = a_inici;
    bool fiCerca = false;
    bool trobat = false;
    while ((p!=NULL) && (!fiCerca)) {
        if (p->dada >= e) {
            fiCerca= true;
            trobat = p->dada == e;
        } else
            p = p->seg;
    }
    return trobat;
}

bool LlistaFamosos::buida() const {
// Pre:--; Post: ens diu si la llista és buida
    return a_inici == NULL;
}

void LlistaFamosos::copiar(const LlistaFamosos &o) {
// Pre: llista buida; Post: aquesta llista és còpia de o
    Node *ant, *p, *q;
    if(!o.buida()) {
        p = o.a_inici;
        q = new Node;
        a_inici = ant = q;
        q->dada= p->dada;
        q->seg= NULL;
        p = p->seg;
        while (p != NULL) {
            q= new Node;
            q->dada= p->dada;
            q->seg=NULL;
            ant->seg=q;
            ant= q;
            p = p->seg;
            a_n++;
        }
    }
}

LlistaFamosos::~LlistaFamosos() {
// Pre: --; Post: objecte destruït
    alliberar();
}

void LlistaFamosos::alliberar() {
// Pre: --; Post: llista buida
    Node *p;
    while ( a_inici != NULL ) {
        p = a_inici;
        a_inici = a_inici->seg;
        delete p;
    }
}

LlistaFamosos& LlistaFamosos::operator=(const LlistaFamosos &o) {
// Pre: -- ; Post: aquesta llista és còpia de o
// COST: O(n)
    if (this != &o) {
        alliberar();
        copiar(o);
    }
    return *this;
}

void LlistaFamosos::llistar() const {
// Pre: --
// Post: Llista mostrada pel canal de sortida cout (1)
    Node *p= a_inici;
    while ( p != NULL ) { // Fins que no s'acabi la llista
        cout << p->dada.get_nom() << endl;
        p = p->seg;
    }
    cout << endl;
}

void LlistaFamosos::inserir(Famoso e) {
// Pre: e valida
// Post: e inserida a la llista (this)
    Node *p, *ant, *nou;
    bool fiCerca= false;
    bool trobat= false;
    ant = NULL;
    p = a_inici;
    while((p!=NULL) && (!fiCerca)) {
        if (p->dada >= e) {
            if (p->dada == e){  // Si l'element ja existeix no cal inserir-lo.
                trobat = true;
            }
            fiCerca = true;     // En el cas de que no existeixi, tenim el punter a lloc i parem la cerca
        } else {
            ant = p;
            p = p->seg;
        }
    }
    if (!trobat) {
        nou=new Node;
        nou->dada=e;
        nou->seg=p;
        if(ant==NULL) { // Al principi
            a_inici = nou;
            a_inici->seg = nou->seg;
        } else { // En qualsevol altre lloc de la llista (inclos l'ultim, ja que p és NULL)
            ant->seg = nou;
            nou->seg = p;
        }
        a_n++;
    }
}


void LlistaFamosos::esborrar(Famoso e) {
// Pre: e valida
// Post: e esborrada de la llista ordenada, si existeix
    Node *p, *ant;
    bool fiCerca = false;
    bool trobat = false;
    p = a_inici;
    ant = NULL;
    while((p!=NULL) && (!fiCerca)){
        if (p->dada >= e) {
            if (p->dada == e){  // Si l'element ja existeix no cal inserir-lo.
                trobat = true;
            }
            fiCerca = true;     // En el cas de que no existeixi, tenim el punter a lloc i parem la cerca
        } else {
            ant = p;
            p = p->seg;
        }
    }
    if (trobat) { // Si el que busquem està a la llista, cal esborrar-lo
        if (p == a_inici){  // Esborro el primer
            a_inici = a_inici->seg;
            delete p;
        } else {
            ant->seg = p->seg;
            delete p;
        }
        a_n--;
    }
}


int LlistaFamosos::mida() const {
    return a_n;
}


Famoso LlistaFamosos::get_by_pos(int id) const {
    Node* p = a_inici;

    for (int i=0; i<id; i++) {
        p = p->seg;
    }

    return p->dada;
}



