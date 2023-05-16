#include "Bellman-Ford.h"
#include <iostream>
#include <fstream>
#include <limits.h>
#include <stdio.h>
using namespace std;

// Algorytm Bellmana-Forda
void bellmanFord(int** graph, int size, int start) {
    int* distance = new int[size];
    int* parent = new int[size];
    bool* visited = new bool[size];

    for (int i = 0; i < size; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    // Odleglosc od zrodla do zrodla jest rowna 0
    distance[start] = 0;
    // Szukamy najkrotszej sciezki
    for (int i = 0; i < size - 1; i++) {
        int u = minDistanceBellman(distance, visited, size);
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {  // Sprawdzamy czy wierzcholek nie zostal odwiedzony, czy istnieje krawedz miedzy wierzcholkami, czy odleglosc od zrodla nie jest nieskonczona i czy odleglosc od zrodla + waga krawedzi jest mniejsza od obecnej odleglosci
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolutionBellman(distance, parent, size, start);
}

void printSolutionBellman(int* distance, int* parent, int size, int start){
    // Wypisanie wynikow
    cout << "Wierzcholek \t Odleglosc od zrodla \t Sciezka" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t" << distance[i] << "\t\t\t" << start;
        printPathBellman(parent, i);
        cout << endl;
    }
}

void printPathBellman(int* parent, int j) {
    // Wypisanie sciezki
    if (parent[j] == -1) {
        return;
    }
    printPathBellman(parent, parent[j]);
    cout << " -> " << j;
}

void run_Bellman() {
    // Wczytanie grafu z pliku
    ifstream file;
    file.open("graph.txt");
    // Sprawdzenie czy plik istnieje
    if (!file) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int size;
    file >> size;
    // Zalokowanie pamieci
    int** graph = new int*[size];
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
    int start;
    cout << "Podaj wierzcholek startowy: ";
    cin >> start;
    // Wywolanie algorytmu
    bellmanFord(graph, size, start);
    // Zwolnienie pamieci
    for (int i = 0; i < size; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

int minDistanceBellman(int* distance, bool* visited, int size) {
    // Znajduje wierzcholek o najmniejszej odleglosci od zrodla
    int min = INT_MAX;
    int minIndex;
    // Przeszukuje tablice odleglosci
    for (int i = 0; i < size; i++) {
        if (!visited[i] && distance[i] <= min) {
            min = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}