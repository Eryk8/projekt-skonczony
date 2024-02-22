/////////// wyszukiwanie liniowe ///////////
#include <iostream>
using namespace std;

// funkcja robiaca wyszukiwanie liniowe
int liniowe(int tab[], int rozmiar, int klucz) {

    for (int i = 0; i < rozmiar; i++) {

        if (tab[i] == klucz) {

            return i; // znalazlo liczbe i zwracamy indeks
        }
    }
    return -1; // liczbe nie znaleziono
}

//////// wyszukiwanie liniowe z wartownikiem ///////

// funkcja robiaca wyszukiwanie 
int liniowe_wartownik(int tab[], int rozmiar, int klucz) {
    tab[rozmiar] = klucz; // dodanie wartownika na koniec tablicy 

    for (int i = 0; ; i++) {
        if (tab[i] == klucz) {
            return i; // znalazlo liczbe i zwracamy indeks
        }
    }
}

///////// algorytm wyszukiwania skokowe /////////

// deklaracja funkcji  i ona szuka liczby w tablicy
void skokowe(int tab[], int n, int liczba);

// definicja funkcji ktora ma  nam  szukac  liczby w tablicy
void skokowe(int tab[], int n, int liczba) {
    int l, p, s;

    l = 0; // Lewy indeks
    p = n - 1; // Prawy indeks

    while (true) {
        if (l > p) {
            cout << "nie ma takiej liczby w tablicy." << endl;
            break;
        }

        s = (l + p) / 2; // srodkowy indeks

        if (tab[s] == liczba) {
            cout << "Znaleziono liczbe " << liczba << " pod indeksem " << s + 1 << endl;
            break;
        } else if (tab[s] < liczba)
            l = s + 1; // szukamy po prawej stronie
        else
            p = s - 1; // szukamy po lewej stronie
    }
}

////////// algorytm wyszukiwania binarnego /////////////

// funkcja ktora odpowiada za wyszukiwanie binarne
int binarne(int tab[], int n, int cel) {
    
    int lewo = 0; // Lewy indeks
    
    int prawo = n - 1; // Prawy indeks

    while (lewo <= prawo) { //wykonuje sie dopoki lewy indeks nie przekroczy prawego
    
        int srodek = lewo + (prawo - lewo) / 2; // srodkowy indeks

        if (tab[srodek] == cel)
        
            return srodek; // jezeli znalazlo liczbe zwracamy ten indeks
            
        else if (tab[srodek] < cel)
        
            lewo = srodek + 1; // szukamy po prawej stronie
            
        else
            prawo = srodek - 1;  // szukamy po lewej stronie
    }

    return -1; // nie ma takiej liczby
}

//////////// algorytm wyszukiwania interpolacyjnego //////////////

// funkcja robiaca  wyszukiwanie 
int interpolacyjne(int tab[], int rozmiar, int klucz) {
    
    int a = 0; // indeks zakresu dolnego
    
    int b = rozmiar - 1; // indeks zakresu gornego

    while (tab[a] <= klucz && klucz <= tab[b]) {
        
        // wyliczanie pozycji p 
        int p = a + ((klucz - tab[a]) * (b - a)) / (tab[b] - tab[a]);

        if (tab[p] == klucz)
        
            return p; // znalazlo liczbe i zwracamy indeks
            
        else if (klucz < tab[p])
        
            b = p - 1; // szukamy po lewej polowie
        else
            a = p + 1; // szukamy po prawej polowie
    }

    return -1; // liczby nie znalazlo
}

int main {
    // przyklad  wyszukiwania liniowego
    const int rozmiar = 12;
    int tab[rozmiar] = {4, 2, 8, 6, 5, 1, 12, 7, 32, 21, 18, 55};
    int klucz = 6;

    int pozycja = liniowe(tab, rozmiar, klucz); // wywolanie tej funkcji 

    if (pozycja != -1) {
        cout << "liczba " << klucz << " jest na pozycji:  " << pozycja << endl;
    } else {
        cout << "liczba " << klucz << " nie ma tego w tablicy." << endl;
    }

    return 0;




//  przyklad wyszukiwania liniowego  z wartownikiem
    const int rozmiar = 12;
    int tab[] = {66, 2, 8, 6, 5, 1, 21, 44, 7, 19, 37, 1};
    int klucz = 6;

    int pozycja = liniowe_wartownik(tab, rozmiar, klucz); // wywolanie tej funkcji wyszukiwania 

    if (pozycja != -1) {
        cout << "Liczba " << klucz << " jest na pozycji " << pozycja << endl;
    } else {
        cout << "Liczba " << klucz << " nie ma tego w tablicy." << endl;
    }

    return 0;




// przyklad  wyszukiwania binarnego
    
    const int rozmiar = 12; // dajemy rozmiar tablicy 
    
    int tab[rozmiar] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 22, 1}; 
    
    int cel = 23; // szukana liczba

    int wynik = binarne(tab, rozmiar, cel); // wywolujemy funkcje wyszukiwania binarnego

    if (wynik != -1)
        cout << "liczba " << cel << " jest pod indeksem: " << wynik << endl;
    else
        cout << "liczba " << cel << " nie ma" << endl;

    return 0;



//  przyklad wyszukiwania interpolacyjnego 
    const int rozmiar = 12;
    
    int tab[] = {1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 22, 43}; // przyklad posortowanej tablicy 
    
    int klucz = 10; // szukana liczba

    int pozycja = interpolacyjne(tab, rozmiar, klucz);

    if (pozycja != -1)
    
        cout << "liczba " << klucz << " jest na pozycji " << pozycja << endl;
    else
        cout << "liczba " << klucz << " nie ma takiej liczby w tablicy ." << endl;

    return 0;



// przyklad  wyszukiwania skokowego
    int tab[6] = {7, 9, 13, 23, 89, 666}; 
    
    int liczba, n = 6;

    // wyswietlamy zawartosc tej tablicy 
    cout << "zawartosc tablicy:";
    for (int i = 0; i < n; i++)
        cout << "tablica[" << i + 1 << "] = " << tab[i] << endl;

    // bierzemy  liczbe od uzytkownika
    cout << "Podaj liczbe: ";
    cin >> liczba;

    // wywolujemy funkcje , ktora szuka liczby w tablicy
    skokowe(tab, n, liczba);

    return 0;

}



