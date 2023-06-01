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
                        cout << "---------------------" << endl;
                        cout << "Menu wyboru:" << endl;
                        cout << "1. Wczytaj z pliku" << endl;
                        cout << "2. Wyswietl graf" << endl;
                        cout << "3. Wyswietl macierz sasiedztwa" << endl;
                        cout << "4. Wyswietl macierz incydencji" << endl;
                        cout << "5. Wyswietl liste sasiedztwa" << endl;
                        cout << "6. Wyswietl liste incydencji" << endl;
                        cout << "7. Wyswietl liste krawedzi" << endl;
                        cout << "8. Wyswietl liste wierzcholkow" << endl;
                        cout << "9. Powrot" << endl;
                        cout << "---------------------" << endl;

                        cout << "Wybierz opcje: ";
                        cin >> wybor1;

                        if (wybor1 ==1){
                            Bellman_Ford_ustawiony = true;
                            cout << "Wczytywanie z pliku" << endl;
                            cout << "Podaj nazwe pliku: ";
                            cin >> nazwa_pliku;
                            cout << "Wczytywanie z pliku: " << nazwa_pliku << endl;
                            cout << "Wczytywanie zakonczone" << endl;
                        }
                        else if (wybor1 == 2){
                            if (Bellman_Ford_ustawiony == true){
                                cout << "Wyswietlanie grafu" << endl;
                                cout << "Wyswietlanie zakonczone" << endl;
                            }
                            else{
                                cout << "Najpierw wczytaj plik" << endl;
                            }
                        }
                        else if (wybor1 == 3)
                        {
                            if (Bellman_Ford_ustawiony == true)
                            {
                                cout << "Wyswietlanie macierzy sasiedztwa" << endl;
                                cout << "Wyswietlanie zakonczone" << endl;
                            }
                            else
                            {
                                cout << "Najpierw wczytaj plik" << endl;
                            }
                        }
                        else if (wybor1 == 4)
                        {
                            if (Bellman_Ford_ustawiony == true)
                            {
                                cout << "Wyswietlanie macierzy incydencji" << endl;
                                cout << "Wyswietlanie zakonczone" << endl;
                            }
                            else
                            {
                                cout << "Najpierw wczytaj plik" << endl;
                            }
                        }
                        else if(wybor1 == 5){
                            
                        }
                        
                        else if (wybor1 == 9) {
                            cout << "Powrot" << endl;
                            break;
                        } else {
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                        }

                    }while(wybor1 != 9);}
                else if (wybor== 2){
                    do{
                        // Dijkstra                        
                        cout<<"---------------------"<<endl;
                        cout<<"Menu wyboru:"<<endl;
                        cout<<"1. Wczytaj z pliku"<<endl;
                        cout<<"2. Wyswietl graf"<<endl;
                        cout<<"3. Wyswietl macierz sasiedztwa"<<endl;
                        cout<<"4. Wyswietl macierz incydencji"<<endl;
                        cout<<"5. Wyswietl liste sasiedztwa"<<endl;
                        cout<<"6. Wyswietl liste incydencji"<<endl;
                        cout<<"7. Wyswietl liste krawedzi"<<endl;
                        cout<<"8. Wyswietl liste wierzcholkow"<<endl;
                        cout<<"9. Powrot"<<endl;
                        cout<<"---------------------"<<endl;

                        cout<<"Wybierz opcje: ";
                        cin>>wybor2;

                        if (wybor2 == 1){
                            // Wczytaj z pliku
                            Dijkstra_ustawiony = true;
                            cout<<"Wczytywanie z pliku"<<endl;
                            cout<<"Podaj nazwe pliku: ";
                            cin>>nazwa_pliku;
                            cout<<"Wczytywanie z pliku: "<<nazwa_pliku<<endl;
                            cout<<"Wczytywanie zakonczone"<<endl;
                        }
                        else if(wybor2 == 2){
                            // Wyswietl graf
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie grafu"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 3){
                            // Wyswietl macierz sasiedztwa
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie macierzy sasiedztwa"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 4){
                            // Wyswietl macierz incydencji
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie macierzy incydencji"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 5){
                            // Wyswietl liste sasiedztwa
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie listy sasiedztwa"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 6){
                            // Wyswietl liste incydencji
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie listy incydencji"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 7){
                            // Wyswietl liste krawedzi
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie listy krawedzi"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }
                        }
                        else if (wybor2 == 8){
                            // Wyswietl liste wierzcholkow
                            if (Dijkstra_ustawiony == true){
                                cout<<"Wyswietlanie listy wierzcholkow"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor2 == 9){
                            // Powrot
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor2 != 9);}
                else if (wybor== 3){
                    do{
                        // Kruskal
                        cout<<"---------------------"<<endl;
                        cout<<"Menu wyboru:"<<endl;
                        cout<<"1. Wczytaj z pliku"<<endl;
                        cout<<"2. Wyswietl graf"<<endl;
                        cout<<"3. Wyswietl macierz sasiedztwa"<<endl;
                        cout<<"4. Wyswietl macierz incydencji"<<endl;
                        cout<<"5. Wyswietl liste sasiedztwa"<<endl;
                        cout<<"6. Wyswietl liste incydencji"<<endl;
                        cout<<"7. Wyswietl liste krawedzi"<<endl;
                        cout<<"8. Wyswietl liste wierzcholkow"<<endl;
                        cout<<"9. Powrot"<<endl;
                        cout<<"---------------------"<<endl;

                        cout<<"Wybierz opcje: ";
                        cin>>wybor3;

                        if (wybor3 == 1){

                        }
                        else if (wybor3 == 2){

                        }
                        else if (wybor3 == 3){

                        }
                        else if (wybor3 == 4){

                        }
                        else if (wybor3 == 5){

                        }
                        else if (wybor3 == 6){

                        }
                        else if (wybor3 == 7){

                        }
                        else if (wybor3 == 8){

                        }
                        else if (wybor3 == 9){
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor3 != 9);}
                else if (wybor== 4){
                    do{
                        // Prim
                        cout<<"---------------------"<<endl;
                        cout<<"Menu wyboru:"<<endl;
                        cout<<"1. Wczytaj z pliku"<<endl;
                        cout<<"2. Wyswietl graf"<<endl;
                        cout<<"3. Wyswietl macierz sasiedztwa"<<endl;
                        cout<<"4. Wyswietl macierz incydencji"<<endl;
                        cout<<"5. Wyswietl liste sasiedztwa"<<endl;
                        cout<<"6. Wyswietl liste incydencji"<<endl;
                        cout<<"7. Wyswietl liste krawedzi"<<endl;
                        cout<<"8. Wyswietl liste wierzcholkow"<<endl;
                        cout<<"9. Powrot"<<endl;
                        cout<<"---------------------"<<endl;

                        cout<<"Wybierz opcje: ";
                        cin>>wybor4;

                        if (wybor4 == 1){
                            // Wczytaj z pliku
                            cout<<"Podaj nazwe pliku: ";
                            cin>>nazwa_pliku;
                            cout<<"Wczytywanie z pliku: "<<nazwa_pliku<<endl;
                            cout<<"Wczytywanie zakonczone"<<endl;
                            Prim_ustawiony = true;
                            }
                        else if (wybor4 == 2){
                            // Wyswietl graf
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie grafu"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 3){
                            // Wyswietl macierz sasiedztwa
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie macierzy sasiedztwa"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 4){
                            // Wyswietl macierz incydencji
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie macierzy incydencji"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 5){
                            // Wyswietl liste sasiedztwa
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie listy sasiedztwa"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 6){
                            // Wyswietl liste incydencji
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie listy incydencji"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 7){
                            // Wyswietl liste krawedzi
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie listy krawedzi"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }}
                        else if (wybor4 == 8){
                            // Wyswietl liste wierzcholkow
                            if (Prim_ustawiony == true){
                                cout<<"Wyswietlanie listy wierzcholkow"<<endl;
                                cout<<"Wyswietlanie zakonczone"<<endl;
                            }
                            else{
                                cout<<"Najpierw wczytaj plik"<<endl;
                            }

                        }
                        if (wybor4 == 9){
                            cout << "Powrot" << endl;
                            break;}
                        else{
                            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}

                while(wybor4 != 9);}
                else if (wybor == 9){
                    // Koniec programu
                    cout << "Konczenie pracy programu" << endl;
                    break;}
                else{
                    cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                }
            } while(wybor != 9);}
                        }