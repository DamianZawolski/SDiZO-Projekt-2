#include "funkcje_pomocnicze.h"
#include <iostream>
#include <fstream>
using namespace std;

int* wczytajDane(string nazwa_pliku) {
    static int liczby[1000000];
    ifstream plik;
    plik.open(nazwa_pliku);

    int liczbaLiczb;

    if (plik.is_open()) {

        plik >> liczbaLiczb;
        cout<<liczbaLiczb;
        for (int i = 0; i < liczbaLiczb; i++) {
            plik >> liczby[i];

            if(plik.fail())
            {
                cout << "Błąd odczytu danych" << endl;
                break;
            }
        }

        plik.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    }

    // wyświetlanie liczb
    cout << "Dane wejsciowe:" << endl;
    for (int i = 0; i < liczbaLiczb; i++) {
        cout<<" | "<<liczby[i];
    }
    cout<<" |"<<endl;
    return liczby;
}