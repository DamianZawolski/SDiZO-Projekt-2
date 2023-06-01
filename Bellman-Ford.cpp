#include "Bellman-Ford.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Bellmana-Forda
void bellmanFord(int** graf, int rozmiar, int start) {
    int* dystans = new int[rozmiar];
    int* rodzic = new int[rozmiar];
    bool* odwiedzone = new bool[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        dystans[i] = INT_MAX;
        rodzic[i] = -1;
        odwiedzone[i] = false;
    }
    // Odleglosc od zrodla do zrodla jest rowna 0
    dystans[start] = 0;
    // Szukamy najkrotszej sciezki
    for (int i = 0; i < rozmiar - 1; i++) {
        int u = minimalnyDystans(dystans, odwiedzone, rozmiar);
        odwiedzone[u] = true;

        for (int v = 0; v < rozmiar; v++) {
            if (!odwiedzone[v] && graf[u][v] && dystans[u] != INT_MAX && dystans[u] + graf[u][v] < dystans[v]) {  // Sprawdzamy czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od zrodla nie jest nieskonczona i czy odleglosc od zrodla + waga krawedzi jest mniejsza od obecnej odleglosci
                dystans[v] = dystans[u] + graf[u][v];
                rodzic[v] = u;
            }
        }
    }

    wypiszRozwiazanie(dystans, rodzic, rozmiar, start);
}

void wypiszRozwiazanie(int* dystans, int* rodzic, int rozmiar, int start){
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

void uruchom_Bellmana() {
    // Wczytanie grafu z pliku
    ifstream plik;
    plik.open("graf.txt");
    // Sprawdzenie czy plik istnieje
    if (!plik) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int rozmiar;
    plik >> rozmiar;
    // Zalokowanie pamieci
    int** graf = new int*[rozmiar];
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
    int start;
    cout << "Podaj wierzcholek startowy: ";
    cin >> start;
    // Wywolanie algorytmu
    bellmanFord(graf, rozmiar, start);
    // Zwolnienie pamieci
    for (int i = 0; i < rozmiar; i++) {
        delete[] graf[i];
    }
    delete[] graf;
}

int minimalnyDystans(int* dystans, bool* odwiedzone, int rozmiar) {
    // Znajduje wierzcholek o najmniejszej odleglosci od zrodla
    int min = INT_MAX;
    int minIndeks;
    // Przeszukuje tablice odleglosci
    for (int i = 0; i < rozmiar; i++) {
        if (!odwiedzone[i] && dystans[i] <= min) {
            min = dystans[i];
            minIndeks = i;
        }
    }

    return minIndeks;
}