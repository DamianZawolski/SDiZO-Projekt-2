#include "Dijkstra.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Dijkstry

void dijkstra(int** graf, int rozmiar, int start) {
    int* dystans = new int[rozmiar];
    int* rodzic = new int[rozmiar];
    bool* odwiedzone = new bool[rozmiar];
    // Inicjalizacja tablic
    for (int i = 0; i < rozmiar; i++) {
        dystans[i] = INT_MAX;
        rodzic[i] = -1;
        odwiedzone[i] = false;
    }
    
    dystans[start] = 0;
    // Szukanie najkrotszej sciezki
    for (int i = 0; i < rozmiar - 1; i++) {
        int u = minimalnyDystans(dystans, odwiedzone, rozmiar);
        odwiedzone[u] = true;
        // Aktualizacja tablic
        for (int v = 0; v < rozmiar; v++) {
            if (!odwiedzone[v] && graf[u][v] && dystans[u] != INT_MAX && graf[u][v] < dystans[v]) { // Warunek sprawdzajacy czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od zrodla nie jest nieskonczona i czy odleglosc od zrodla jest mniejsza od poprzedniej
                dystans[v] = graf[u][v];
                rodzic[v] = u;
            }
        }
    }

    wypiszRozwiazanie(dystans, rodzic, rozmiar, start);
}

void wypiszRozwiazanie(int* rozmiar, int* rodzic, int rozmiar, int start) {
    // Wypisanie wynikow
    cout << "Wierzcholek \t Odleglosc od zrodla \t Sciezka" << endl;
    for (int i = 0; i < rozmiar; i++) {
        cout << i << "\t\t" << rozmiar[i] << "\t\t\t" << start;
        wypiszSciezke(rodzic, i);
        cout << endl;
    }
}

void wypiszSciezke(int* rodzic, int j) {
    // Wypisanie sciezki
    if (rodzic[j] == -1) { // Warunek zakonczenia rekurencji
        return;
    }
    wypiszSciezke(rodzic, rodzic[j]);
    cout << " -> " << j;
}

void uruchom_Dijkstre() {
    // Wczytanie grafu z pliku
    ifstream plik;
    plik.open("graf.txt");
    // Struktura pliku graf.txt- pierwsza linia to rozmiar grafu, a kolejne linie to macierz sasiedztwa

    if (!plik) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Wczytanie rozmiaru grafu
    int rozmiar;
    plik >> rozmiar;
    // Stworzenie grafu
    int** graf = new int* [rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        graf[i] = new int[rozmiar];
    }
    // Wczytanie grafu
    for (int i = 0; i < rozmiar; i++) {
        graf[i][i] = 0;
        for (int j = i + 1; j < rozmiar; j++) {
            plik >> graf[i][j];
            graf[j][i] = graf[i][j];
        }
    }
    // Wywolanie algorytmu
    dijkstra(graf, rozmiar, 0);

    for (int i = 0; i < rozmiar; i++) {
        delete[] graf[i];
    }
    delete[] graf;
}

int minimalnyDystans(int* dystans, bool* odwiedzone, int rozmiar) {
    // Znalezienie najmniejszej odleglosci
    int min = INT_MAX;
    int min_indeks;
    // Przeszukanie tablicy odleglosci
    for (int i = 0; i < rozmiar; i++) {
        if (odwiedzone[i] == false && dystans[i] <= min) {
            min = dystans[i];
            min_indeks = i;
        }
    }

    return min_indeks;
}
