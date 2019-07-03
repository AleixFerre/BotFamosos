#include "Famoso.h"

Famoso::Famoso() {
    nom = "";
}

Famoso::Famoso(string _nom) {
    nom = _nom;
}

string Famoso::get_nom() const {
    return nom;
}

void Famoso::set_nom(string _nom) {
    nom = _nom;
}


bool Famoso::operator>=(Famoso f)const{
    return nom>=f.nom;
}

bool Famoso::operator==(Famoso f)const{
    return nom==f.nom;
}
