#include "Prim.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Prima

void prim(int** graph, int size, int start) {
    // Zmienne pomocnicze
    int* distance = new int[size];
    int* parent = new int[size];
    bool* visited = new bool[size];
    // Inicjalizacja
    for (int i = 0; i < size; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    // Ustawienie wierzcholka startowego
    distance[start] = 0;
    // Szukanie najkrotszej sciezki
    for (int i = 0; i < size - 1; i++) {
        int u = minDistance(distance, visited, size);
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && graph[u][v] < distance[v]) { // Sprawdzenie czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od wierzcholka startowego nie jest nieskonczona, czy odleglosc od wierzcholka startowego do wierzcholka v jest mniejsza od obecnej odleglosci
                distance[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(distance, parent, size, start);
}

void printSolution(int* distance, int* parent, int size, int start) {
    // Wypisanie wynikow
    cout << "Wierzcholek \t Odleglosc od zrodla \t Sciezka" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t" << distance[i] << "\t\t\t" << start;
        printPath(parent, i);
        cout << endl;
    }
}

void printPath(int* parent, int j) {
    // Wypisanie sciezki
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void run_Prim() {
    // Otwarcie pliku
    ifstream file;
    file.open("graph.txt");

    if (!file) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int size;
    file >> size;
    // Inicjalizacja grafu
    int** graph = new int* [size];
    for (int i = 0; i < size; i++) {
        graph[i] = new int[size];
    }
    //  Wczytanie grafu z pliku
    for (int i = 0; i < size; i++) {
        graph[i][i] = 0;
        for (int j = i + 1; j < size; j++) {
            file >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
    prim(graph, size, 0);
}

int minDistance(int* distance, bool* visited, int size) {
    // Zmienne pomocnicze
    int min = INT_MAX;
    int min_index;
    // Szukanie najmniejszej odleglosci
    for (int i = 0; i < size; i++) {
        if (visited[i] == false && distance[i] <= min) {    // Sprawdzenie czy wierzcholek nie zostal odwiedzony, czy odleglosc od wierzcholka startowego jest mniejsza od obecnej odleglosci
            min = distance[i];
            min_index = i;
        }
    }

    return min_index;
}
