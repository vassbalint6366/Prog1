#include "std_lib_facilities.h"

template<typename T>
struct S {
private:
    T val;
public:
    S(T vall = T()) : val(vall) {}//értékadás
    
    T& get();//nincs másolás
    T get() const { return val; }//átmásolja az értéket
    //getter függvény kell ha privát tagot akarunk meghívni

    T operator=(const T&);
};

template<typename T> T& S<T>::get() { return val; }

template<typename T> T S<T>::operator=(const T& ujval) { val = ujval; } //setter fv csak operátorral

template<typename T>
istream& operator>>(istream& is, S<T>& tt){
    is >> tt.get();
    return is;
}

template<typename T> void read_val(T& v) { cin >> v; }

int main()
try {
    S<int> szam {50};
    S<char> betu {'q'};
    S<double> nemegesz {123.456};
    S<string> szoveg {"Szöveg"};
    S<vector<int>> vektor { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };

    cout << szam.get() << " " << betu.get() << " " << nemegesz.get() << " " << szoveg.get() << endl; // így elérjük a private részt
    vector<int> feltoltesvektor = vektor.get();
    for (auto v : feltoltesvektor) cout << v << " ";
    cout << "\n\n";

    S<int> masik {25};
    cout << "Szám: " << szam.get() << endl;
    szam = masik; // felülírjuk az 50-et 25-re
    cout << "Új szám: " << szam.get() << endl;

    S<int> sajatszam;
    S<double> sajatnemegesz;
    S<string> sajatszoveg;
    S<char> sajatkarakter;
    cout << "Adj meg egy számot, nem egész számot, szöveget és egy karaktert!\n";
    read_val(sajatszam); read_val(sajatnemegesz); read_val(sajatszoveg); read_val(sajatkarakter);
    cout <<
        "Számod: "<< sajatszam.get() <<
        ", nem egész számod: " << sajatnemegesz.get() <<
        ", szöveged: " << sajatszoveg.get() <<
        ", karaktered: " << sajatkarakter.get() << endl;

    return 0;
} catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Something went wrong!" << endl;
    return 2;
}