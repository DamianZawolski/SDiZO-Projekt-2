#include "Dijkstra.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Dijkstry

void dijkstra(int** graph, int size, int start) {
    int* distance = new int[size];
    int* parent = new int[size];
    bool* visited = new bool[size];
    // Inicjalizacja tablic
    for (int i = 0; i < size; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    
    distance[start] = 0;
    // Szukanie najkrotszej sciezki
    for (int i = 0; i < size - 1; i++) {
        int u = minDistance(distance, visited, size);
        visited[u] = true;
        // Aktualizacja tablic
        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && graph[u][v] < distance[v]) { // Warunek sprawdzajacy czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od zrodla nie jest nieskonczona i czy odleglosc od zrodla jest mniejsza od poprzedniej
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
    if (parent[j] == -1) { // Warunek zakonczenia rekurencji
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void run_Dijkstra() {
    // Wczytanie grafu z pliku
    ifstream file;
    file.open("graph.txt");

    if (!file) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Wczytanie rozmiaru grafu
    int size;
    file >> size;
    // Stworzenie grafu
    int** graph = new int* [size];
    for (int i = 0; i < size; i++) {
        graph[i] = new int[size];
    }
    // Wczytanie grafu
    for (int i = 0; i < size; i++) {
        graph[i][i] = 0;
        for (int j = i + 1; j < size; j++) {
            file >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
    // Wywolanie algorytmu
    dijkstra(graph, size, 0);

    for (int i = 0; i < size; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

int minDistance(int* distance, bool* visited, int size) {
    // Znalezienie najmniejszej odleglosci
    int min = INT_MAX;
    int min_index;
    // Przeszukanie tablicy odleglosci
    for (int i = 0; i < size; i++) {
        if (visited[i] == false && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }

    return min_index;
}
