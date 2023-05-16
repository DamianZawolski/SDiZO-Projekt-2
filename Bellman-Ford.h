
#ifndef SDIZO_PROJEKT_2_BELLMAN_FORD_H
#define SDIZO_PROJEKT_2_BELLMAN_FORD_H

#endif //SDIZO_PROJEKT_2_BELLMAN_FORD_H

void bellmanFord(int** graph, int size, int start);
void printSolutionBellman(int* distance, int* parent, int size, int start);
void printPathBellman(int* parent, int j);
void run_Bellman();
int minDistanceBellmanFord(int* distance, bool* visited, int size);