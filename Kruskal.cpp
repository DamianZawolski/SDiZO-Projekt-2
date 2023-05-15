#include "Kruskal.h"
#include <iostream>
#include <fstream>

using namespace std;

// Algorytm Kruskala

void kruskal(int** graph, int size) {
    // Zmienne pomocnicze
    int* parent = new int[size];
    int min;
    int a, b;
    int u, v;
    int noOfEdges = 1;
    int total = 0;
    int** tree = new int* [size];
    for (int i = 0; i < size; i++) {
        tree[i] = new int[size];
    }
    // Inicjalizacja
    for (int i = 0; i < size; i++) {
        parent[i] = 0;
        for (int j = 0; j < size; j++) {
            tree[i][j] = 0;
        }
    }
    
    while (noOfEdges < size) {
        min = INT_MAX;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u]) {
            u = parent[u];
        }

        while (parent[v]) {
            v = parent[v];
        }

        if (u != v) {
            noOfEdges++;
            total += min;
            tree[a][b] = min;
            tree[b][a] = min;
            parent[v] = u;
        }

        graph[a][b] = graph[b][a] = INT_MAX;
    }

    printSolution(tree, size, total);
}

void printSolution(int** tree, int size, int total) {
    // Wypisanie wyniku
    cout << "Krawedz \t Waga" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (tree[i][j] != 0) {
                cout << i << " - " << j << "\t\t" << tree[i][j] << endl;
            }
        }
    }
    cout << "Suma wag: " << total << endl;
}

void run_Kruskal() {
    // Wczytanie grafu z pliku
    ifstream file;
    file.open("graph.txt");

    if (!file) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    // Zmienne pomocnicze
    int size;
    file >> size;

    int** graph = new int* [size];
    for (int i = 0; i < size; i++) {
        graph[i] = new int[size];
    }
    
    for (int i = 0; i < size; i++) {
        graph[i][i] = 0;
        for (int j = i + 1; j < size; j++) {
            file >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    kruskal(graph, size);
}
