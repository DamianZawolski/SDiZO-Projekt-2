#include "Prim.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Prima

void prim(int** graf, int rozmiar, int start) {
    // Zmienne pomocnicze
    int* dystans = new int[rozmiar];
    int* rodzic = new int[rozmiar];
    bool* odwiedzone = new bool[rozmiar];
    // Inicjalizacja
    for (int i = 0; i < rozmiar; i++) {
        dystans[i] = INT_MAX;
        rodzic[i] = -1;
        odwiedzone[i] = false;
    }
    // Ustawienie wierzcholka startowego
    dystans[start] = 0;
    // Szukanie najkrotszej sciezki
    for (int i = 0; i < rozmiar - 1; i++) {
        int u = minimalnyDystans(dystans, odwiedzone, rozmiar);
        odwiedzone[u] = true;

        for (int v = 0; v < rozmiar; v++) {
            if (!odwiedzone[v] && graf[u][v] && dystans[u] != INT_MAX && graf[u][v] < dystans[v]) { // Sprawdzenie czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od wierzcholka startowego nie jest nieskonczona, czy odleglosc od wierzcholka startowego do wierzcholka v jest mniejsza od obecnej odleglosci
                dystans[v] = graf[u][v];
                rodzic[v] = u;
            }
        }
    }

    wypiszRozwiazanie(dystans, rodzic, rozmiar, start);
}

void wypiszRozwiazanie(int* dystans, int* rodzic, int rozmiar, int start) {
    // Wypisanie wynikow
    cout << "Wierzcholek \t Odleglosc od zrodla \t Sciezka" << endl;
    for (int i = 0; i < rozmiar; i++) {
        cout << i << "\t\t" << dystans[i] << "\t\t\t" << start;
        wypiszSciezke(rodzic, i);
        cout << endl;
    }
}

void wypiszSciezke(int* rodzic, int j) {
    // Wypisanie sciezki
    if (rodzic[j] == -1) {
        return;
    }
    wypiszSciezke(rodzic, rodzic[j]);
    cout << " -> " << j;
}

void uruchom_Prima() {
    // Otwarcie pliku
    ifstream plik;
    plik.open("graf.txt");

    if (!plik) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int rozmiar;
    plik >> rozmiar;
    // Inicjalizacja grafu
    int** graf = new int* [rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        graf[i] = new int[rozmiar];
    }
    //  Wczytanie grafu z pliku
    for (int i = 0; i < rozmiar; i++) {
        graf[i][i] = 0;
        for (int j = i + 1; j < rozmiar; j++) {
            plik >> graf[i][j];
            graf[j][i] = graf[i][j];
        }
    }
    prim(graf, rozmiar, 0);
}

int minimalnyDystans(int* dystans, bool* odwiedzone, int rozmiar) {
    // Zmienne pomocnicze
    int min = INT_MAX;
    int min_indeks;
    // Szukanie najmniejszej odleglosci
    for (int i = 0; i < rozmiar; i++) {
        if (odwiedzone[i] == false && dystans[i] <= min) {    // Sprawdzenie czy wierzcholek nie zostal odwiedzony, czy odleglosc od wierzcholka startowego jest mniejsza od obecnej odleglosci
            min = dystans[i];
            min_indeks = i;
        }
    }

    return min_indeks;
}
