//////////// sortowanie babelkowe //////////////
#include <iostream>
using namespace std;

// funkcja ktora wykonuje to wyszukiwanie
void babelkowe(int tab[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (tab[j] > tab[j + 1]) {

                swap(tab[j], tab[j + 1]); // zamieniamy miejscami liczby jezeli sa w zlej kolejnosci
            }
        }
    }
}


////////////// sortowanie koktajlowe //////////////

// funkcja zamienia wartosci dwoch zmiennych 
void zamien(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funkcja robiaca sortowanie 
void koktajlowe(int tab[], int n) {

    bool zamiana = true;

    int bottom = 0; // dolny indeks zakresu

    int top = n - 1; // gorny indeks zakresu

    while (zamiana) {

        zamiana = false;

        // przeszukuje od lewej do prawej 
        for (int i = bottom; i < top; i++) {

            if (tab[i] > tab[i + 1]) {

                zamien(tab[i], tab[i + 1]);

                zamiana = true;
            }
        }
        --top; //ogranicza zasieg poszukiwania 

        // przeszukuje od prawej do lewej
        for (int i = top; i > bottom; i--) {

            if (tab[i] < tab[i - 1]) {

                zamien(tab[i], tab[i - 1]);

                zamiana = true;
            }
        }
        ++bottom; // znowu ogranicza zasieg poszukiwania 
    }
}


//////////// sortowanie szybkie /////////////

// funckcjas ta zamienia wartosci tym dwom zmiennym
void zamien(int &a, int &b) {

    int temp = a;

    a = b;

    b = temp;
}

// implementujemy sortowanie 
void szybkie(int *tablica, int lewy, int prawy) {

    // Wybieramy liczbe ktora jest na srodku  jako pivot.
    int pivot = tablica[(lewy + prawy) / 2];

    int i = lewy;

    int j = prawy;

    // dzielimy tablice na dwie czesci wokol pivota
    while (i <= j) {

        // przesuwamy wskaznik i w prawo, dopoki liczba nie  jest mniejsza od pivota.
        while (tablica[i] < pivot) i++;

        // przesuwamy wskaznik j w lewo, dopoki liczba jest wieksza od pivota.
        while (tablica[j] > pivot) j--;

        // Jesli wskazniki i i j nie minely sie , zamieniamy liczby  miejscami.
        if (i <= j) {

            zamien(tablica[i], tablica[j]);

            i++;

            j--;
        }
    }

    // rekurencyjnie sortujemy obie czesci tablicy 
    if (lewy < j) szybkie(tablica, lewy, j);

    if (i < prawy) szybkie(tablica, i, prawy);
}

/////////// sortowanie przez wstawianie ///////////////

// Funkcja  ta sortuje tablice za pomoca  sortowania 
void wstawianie(int n, int *tab) {

    int pom, j;

    // iterujemy przez liczby, zaczynajac od drugiej liczby.
    for (int i = 1; i < n; i++) {

        // zapamietuje  wartosc aktualnej liczby.
        pom = tab[i];

        // przesuwamy wskaznik j w lewo, porownujac ten z poprzednimi liczbami.
        j = i - 1;

        // dopoki wskaznik j nie wyjdzie poza zakres i wartosc poprzedniej liczby jest on  wiekszy od pom

        // przesuwamy liczby w prawo.
        while (j >= 0 && tab[j] > pom) {

            tab[j + 1] = tab[j];

            j--;
        }

        // wstawiamy zapamietana wartosc pom na dobre miejsce.
        tab[j + 1] = pom;
    }
}

/////////// sortowanie przez scalanie //////////////

// Funkcja scalanie wykonuje ten algorytm dla dwoch posortowanych podtablici zamieni je w jedna posortowana tablice
void scalanie(int tab[], int lewo, int srodek, int prawo) {

    // obliczamy rozmiary podtablic.
    int a1 = srodek - lewo + 1;
    int b2 = prawo - srodek;

    // tworzymy dynamiczne tablice dla lewej i prawej podtablicy.
    int* lewyTab = new int[a1];
    int* prawyTab = new int[b2];

    // kopiujemy elementy z tablicy glownej do tablic pomocniczych.
    for (int i = 0; i < a1; i++) {
        lewyTab[i] = tab[lewo + i];
    }
    for (int j = 0; j < b2; j++) {
        prawyTab[j] = tab[srodek + 1 + j];
    }

    // scalamy tablice pomocnicze w jedna posortowana tablice 
    int i = 0;
    int j = 0;
    int k = lewo;

    while (i < a1 && j < b2) {
        if (lewyTab[i] <= prawyTab[j]) {
            tab[k] = lewyTab[i];
            i++;
        } else {
            tab[k] = prawyTab[j];
            j++;
        }
        k++;
    }

    // wstawiamy pozostale liczby z lewej i prawej tablicy.
    while (i < a1) {
        tab[k] = lewyTab[i];
        i++;
        k++;
    }
    while (j < b2) {
        tab[k] = prawyTab[j];
        j++;
        k++;
    }

    // zwalniamy pamiec dla tablic pomocniczych.
    delete[] lewyTab;
    delete[] prawyTab;
}

// funkcja scalanieSort wykonuje to sortowanie na calej tablicy.
void scalanieSort(int tab[], int lewo, int prawo) {
    if (lewo < prawo) {

        // obliczamy srodek tej tablicy.
        int srodek = lewo + (prawo - lewo) / 2;

        // rekurencyjnie sortujemy lewa i prawa czesc tablicy.
        scalanieSort(tab, lewo, srodek);
        scalanieSort(tab, srodek + 1, prawo);

        // scalamy posortowane podtablice.
        scalanie(tab, lewo, srodek, prawo);
    }
}

int main() {
    // uzycie sortowania babelkowego
    const int rozmiar = 12;

    int tab[rozmiar] = {5, 2, 9, 1, 5, 6, 26, 12, 8, 1, 32, 19};

    cout << "przed sortowaniem: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    babelkowe(tab, rozmiar);

    cout << "po sortowaniu: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    // uzycie sortowania koktajlowego
    int tab[rozmiar] = {5, 2, 9, 1, 5, 6, 42, 21, 4, 65, 11, 3};

    cout << "przed sortowaniem: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    koktajlowe(tab2, rozmiar);

    cout << "po sortowaniu: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    // uzycie sortowania szybkiego 
    int tab[rozmiar] = {5, 2, 9, 1, 7, 6, 3, 21, 18, 14, 54, 10};

    cout << "tablica przed: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    szybkie(tab, 0, rozmiar - 1);

    cout << "tablica po: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    // uzycie sortowania przez wstawianie
    int n;

    cout << "podaj wielkosc: ";

    cin >> n;

    int *tab = new int[n];

    for (int i = 0; i < n; i++) {

        cout << "Podaj " << i + 1 << " element: ";

        cin >> tab[i];
    }

    cout << "przed sortowaniem: ";

    for (int i = 0; i < n; i++) {

        cout << tab[i] << " ";
    }

    wstawianie(n, tab);

    cout << "po sortowaniu: ";

    for (int i = 0; i < n; i++) {

        cout << tab[i] << " ";
    }

    delete[] tab; 

    // uzycie sortowania przez scalanie
    int tab[rozmiar] = {12, 23, 4, 3, 56, 78, 9, 10, 66, 7, 22, 19};

    scalanieSort(tab, 0, rozmiar - 1);

    cout << "Posortowane: ";

    for (int i = 0; i < rozmiar; i++) {

        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
