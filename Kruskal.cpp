#include "Kruskal.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Kruskala

void kruskal(int** graf, int rozmiar) {
    // Zmienne pomocnicze
    int* rodzic = new int[rozmiar];
    int min;
    int a, b;
    int u, v;
    int iloscKrawedzi = 1;
    int total = 0;
    int** drzewo = new int* [rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        drzewo[i] = new int[rozmiar];
    }
    // Inicjalizacja
    for (int i = 0; i < rozmiar; i++) {
        rodzic[i] = 0;
        for (int j = 0; j < rozmiar; j++) {
            drzewo[i][j] = 0;
        }
    }
    
    while (iloscKrawedzi < rozmiar) {
        min = INT_MAX;
        for (int i = 0; i < rozmiar; i++) {
            for (int j = i; j < rozmiar; j++) {
                if (graf[i][j] < min) {
                    min = graf[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (rodzic[u]) {
            u = rodzic[u];
        }

        while (rodzic[v]) {
            v = rodzic[v];
        }

        if (u != v) {
            iloscKrawedzi++;
            total += min;
            drzewo[a][b] = min;
            drzewo[b][a] = min;
            rodzic[v] = u;
        }

        graf[a][b] = graf[b][a] = INT_MAX;
    }

    wypiszRozwiazanie(drzewo, rozmiar, total);
}

void wypiszRozwiazanie(int** drzewo, int rozmiar, int total) {
    // Wypisanie wyniku
    cout << "Krawedz \t Waga" << endl;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = i; j < rozmiar; j++) {
            if (drzewo[i][j] != 0) {
                cout << i << " - " << j << "\t\t" << drzewo[i][j] << endl;
            }
        }
    }
    cout << "Suma wag: " << total << endl;
}

void uruchom_Kruskala() {
    // Wczytanie grafu z pliku
    ifstream plik;
    plik.open("graf.txt");

    if (!plik) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int rozmiar;
    plik >> rozmiar;

    int** graf = new int* [rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        graf[i] = new int[rozmiar];
    }
    
    for (int i = 0; i < rozmiar; i++) {
        graf[i][i] = 0;
        for (int j = i + 1; j < rozmiar; j++) {
            plik >> graf[i][j];
            graf[j][i] = graf[i][j];
        }
    }

    kruskal(graf, rozmiar);
}
