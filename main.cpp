/*

BOT DE GUERRA MUNDIAL/MATAR FAMOSOS
en C++

by Aleix Ferré
Basat en el bot de Twitter.

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <LlistaFamosos.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void quants_queden( int midaVius, int midaMorts ) {
    cout << "Queden " << midaVius << " famosos vius." << endl
         << "Queden " << midaMorts << " famosos morts." << endl
         << "---------------------------------" << endl;
}

void entrarFamosos (ifstream& fitxer, LlistaFamosos& llistaF) {
    string nom;
    do {
        //cout << "Entra el famós: [# per acabar]" << endl;
        getline(fitxer, nom);
        Famoso f;
        f.set_nom(nom);
        llistaF.inserir(f);
    } while ( !fitxer.eof() );

    if (llistaF.mida() == 0) {
        cout << "NO POTS INICIAR EL JOC AMB CAP FAMÓS!" << endl;
        exit(1);
    }
}


void matarFamos ( LlistaFamosos& llistaVius, LlistaFamosos& llistaMorts ) {

    // Algorisme de matar a un famós
    int famos1ID = rand() % llistaVius.mida(); // Ataca
    int famos2ID = rand() % llistaVius.mida(); // Mor

    while (famos1ID == famos2ID) {
        famos2ID = rand() % llistaVius.mida();
    }

    Famoso f1 = llistaVius.get_by_pos(famos1ID);
    Famoso f2 = llistaVius.get_by_pos(famos2ID);

    cout << f1.get_nom() << " ha matat a " << f2.get_nom() << endl;

    llistaVius.esborrar(f2);
    llistaMorts.inserir(f2);

    quants_queden(llistaVius.mida(), llistaMorts.mida());

}

void reviureFamos(LlistaFamosos& llistaVius, LlistaFamosos& llistaMorts) {

    int famosID = rand() % llistaMorts.mida(); // Reviu
    Famoso f = llistaMorts.get_by_pos(famosID);

    cout << "El famós " << f.get_nom() << " ha resucitat!" << endl;

    llistaVius.inserir(f);
    llistaMorts.esborrar(f);

    quants_queden(llistaVius.mida(), llistaMorts.mida());
}


int main() {
#ifdef _WIN32
SetConsoleOutputCP( CP_UTF8 );
SetConsoleCP( CP_UTF8 );
#endif

    ifstream fitxer;
    cout << "Esculleix un fitxer de dades:" << endl
         << "Famosos [A] o Paisos[B]" << endl;
    string car;
    cin >> car;
    if (car == "A")
        fitxer.open("Famosos.txt");
    else if (car == "B")
        fitxer.open("Paisos.txt");
    else {
        cout << "Introdueix bé el fitxer!" << endl;
        exit(2);
    }

    LlistaFamosos llistaVius;
    LlistaFamosos llistaMorts;

    int seed;
    cout << "Entra la seed:" << endl;
    cin >> seed;
    srand(seed);


    // Entrem els famosos en una llista de Famosos
    entrarFamosos(fitxer, llistaVius);


    // Dinamicament es van matant entre si fins que només en queda un
    while ( llistaVius.mida() > 1 ) {

        // Hi ha un 20% que algú revisqui
        if ( rand()%10 > 8 and llistaMorts.mida() > 0 ) {
            reviureFamos(llistaVius, llistaMorts);
        } else {
            // Mata gent
            matarFamos(llistaVius, llistaMorts);
        }
    }


    // Fi del joc
    cout << llistaVius.get_by_pos(0).get_nom() << " ha guanyat la Guerra Mundial!" << endl;

    return 0;
}
