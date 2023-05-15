#include "testy.h"
#include "funkcje_pomocnicze.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Dijkstra.h"
#include "Bellman-Ford.h"
#include <iostream>
using namespace std;

int main()
{
    int tryb;

        cout << endl << "Damian Zawolski 260353 SDiZO Projekt 2:" << endl;
        cout << "Wybierz tryb programu:" << endl;
        cout << "1. Testowanie automatyczne" << endl;
        cout << "2. Testowanie reczne" << endl;
        cin >> tryb;
        if (tryb == 1) {
            cout<<"";
        }
        else if (tryb == 2) {
        string nazwa_pliku;
        int wybor;
        int wybor1;
        int wybor2;
        int wybor3;
        int wybor4;
        cout << "Podaj nazwe pliku: ";
        cin >> nazwa_pliku;
            bool Bellman_Ford_ustawiony = false;
            bool Dijkstra_ustawiony = false;
            bool Kruskal_ustawiony = false;
            bool Prim_ustawiony = false;

            do {
                Bellman_Ford_ustawiony = false;
                Dijkstra_ustawiony = false;
                Kruskal_ustawiony = false;
                Prim_ustawiony = false;

                cout << "---------------------" << endl;
                cout << "Menu wyboru:" << endl;
                cout << "1. Bellman Ford" << endl;
                cout << "2. Dijkstra" << endl;
                cout << "3. Kruskal" << endl;
                cout << "4. Prim" << endl;
                cout << "9. Wyjscie" << endl;
                cout << "---------------------" << endl;
                cout << "Wybierz opcje: ";
                cin >> wybor;

                if (wybor== 1){
                    do {
                        //Bellman Ford

                        if (wybor1 == 9) {
                            cout << "Powrot" << endl;
                            break;
                        } else {
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                        }

                    }while(wybor1 != 9);}
                else if (wybor== 2){
                    do{
                        // Dijkstra
                        if (wybor2 == 9){
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor2 != 9);}
                else if (wybor== 3){
                    do{
                        // Kruskal
                        if (wybor3 == 9){
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor3 != 9);}
                else if (wybor== 4){
                    do{
                        // Prim
                        if (wybor4 == 9){
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor4 != 9);}
                else if (wybor == 9){

                    cout << "Konczenie pracy programu" << endl;
                    break;}
                else{
                    cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                }
            } while(wybor != 9);}
        }