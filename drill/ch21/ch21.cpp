#include "std_lib_facilities.h"

struct Item
{								  // nev=n;  iid=i;  ertek=v;
	Item(string n, int i, double v): nev(n), iid(i), ertek(v) {}
	//konstruktor                   értékadás itt történik meg
	string nev;
	int iid;
	double ertek;
};

ostream& operator<<(ostream& os, const Item& i)
{
	os << i.nev << ' ' << i.iid << ' ' << i.ertek;
	return os;
}
	
template<typename Iter> // első és utolsó elemre mutató iterátor
void kiir(const Iter& elso, const Iter& utolso)
				//vi.begin()      vi.end()
{	//
	for (auto a = elso; a != utolso; ++a)
		//os 
		cout << *a << endl;
}		//  dereferencia

class SameNev
{
private:
	string nev;
public:
	SameNev(const string &s): nev{s} {}
						//nev{s} letárolja a nevet
	bool operator()(const Item& i) const { return i.nev == nev; }
	//megnézi hogy az Item-ben lévő név megegyezik-e a beérkezővel
};

class SameId
{
private:
	int id;
public:
	SameId(const int& idd): id(idd) {}
	bool operator()(const Item& i) const { return i.iid == id; }
};

void feladat1()
{//------------------------- V E C T O R -------------------------
	vector<Item> vi;
	string n;
	int id;
	double val;

	//bemeneti fájl lekezelése
	string filename = "ch21adatok1.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	//adatok beolvasása és a vektor feltöltése
	while (is >> n >> id >> val) { vi.push_back(Item{n, id, val}); }

	sort(vi.begin(), vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.nev < i2.nev; });
	sort(vi.begin(),vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.iid < i2.iid; });
	sort(vi.begin(),vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.ertek > i2.ertek; });

	cout << "Sorbarendezés után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;

	vi.insert(vi.end(), Item{"horse shoe", 99, 12.34});
	vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});
	cout << "\nInsert parancs után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;

	auto nev_torles = find_if(vi.begin(), vi.end(), SameNev("korte"));
	vi.erase(nev_torles);
	auto id_torles = find_if(vi.begin(), vi.end(), SameId(55));
	vi.erase(id_torles);
	cout << "\nErase parancs után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;
}//------------------------- V E C T O R -------------------------

bool RendezNev(const Item& item1, const Item& item2)
{
	return item1.nev < item2.nev;
}
bool RendezId(const Item& item1, const Item& item2)
{
	return item1.iid < item2.iid;
}
bool RendezErtekCsokk(const Item& item1, const Item& item2)
{
	return item1.ertek > item2.ertek;
}

void feladat2() // feladat1 csak a vektor (vi) helyett listával (li)
{//--------------------------- L I S T ---------------------------
	list<Item> li;
	string n;
	int id;
	double val;

	//bemeneti fájl lekezelése
	string filename = "ch21adatok1.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	//adatok beolvasása és a lista feltöltése
	while (is >> n >> id >> val) { li.push_back(Item{n, id, val}); }

	// 2.feladat
	li.sort(RendezNev);
	// 3.feladat
	li.sort(RendezId);
	// 4.feladat
	li.sort(RendezErtekCsokk);

	cout << "Sorbarendezés után:\n";
	kiir(li.begin(), li.end());
	cout << endl;

	li.insert(li.end(), Item{"horse shoe", 99, 12.34});
	li.insert(li.end(), Item{"Canon S400", 9988, 499.95});
	cout << "\nInsert parancs után:\n";
	kiir(li.begin(), li.end());
	cout << endl;

	auto nev_torles = find_if(li.begin(), li.end(), SameNev("korte"));
	li.erase(nev_torles);
	auto id_torles = find_if(li.begin(), li.end(), SameId(55));
	li.erase(id_torles);
	cout << "\nErase parancs után:\n";
	kiir(li.begin(), li.end());
	cout << endl;
}//--------------------------- L I S T ---------------------------


void map_beolavsas(map<string, int>& m)
{
	string szoveg;
	int szam;
	cin >> szoveg >> szam;
	m.insert({szoveg, szam});
}

template<typename T1, typename T2>
void kiir_map(const map<T1, T2> mapp)
{
	//for each
	for (const auto& e : mapp) cout << e.first << ' ' << e.second << endl;
}

double map_osszead(const map<string, int>& mapp)
{
	int sum = 0;
	for (const auto& e : mapp) sum += e.second;
	return sum;
}

void feladat3()
{//---------------------------- M A P ----------------------------
	map<string, int> msi;
				//string, int
	// map mindig az első oszlop szerint rakja sorrendbe
	msi.insert({"kocka", 12});
	msi.insert({"telefon", 33});
	msi.insert({"laptop", 83});
	msi.insert({"haromszog", 4});
	msi.insert({"negyszog", 92});
	msi.insert({"otszog", 62});
	msi.insert({"hatszog", 45});
	msi.insert({"asztal", 81});
	msi.insert({"szek", 11});
	msi.insert({"villany", 24});

	cout << "A map (msi) elemei:\n";
	kiir_map(msi);
	cout << endl;

	msi.erase(msi.begin(), msi.end());
	// AZÉRT VAN KOMMENTBE TÉVE MERT IDEGESÍTŐ VOLT
	// MINDIG BEÍRNI ENNYI ADATOT
	/*
	cout << "Adj meg 10 pár szót (string) és számot hozzá (szam)" << endl;
	constexpr int darab = 10;
	for (int i = 0; i < darab; ++i) map_beolavsas(msi);
	cout << endl;
	
	cout << "A map elemei:\n";
	kiir_map(msi);
	cout << endl;

	cout << "Map számai összeadva: " << map_osszead(msi) << endl;

	map<int, string> mis;
	for (const auto& m : msi) mis.insert({m.second, m.first});

	cout << "A map (mis) elemei:\n";
	kiir_map(mis);
	cout << endl;
	*/
}//---------------------------- M A P ----------------------------

void feladat4()
{//-------------------- M O R E - V E C T O R --------------------
	string filename = "ch21adatok2.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	vector<double> vd;
	double adatok;
	while (is >> adatok) { vd.push_back(adatok); }

	cout << "Elemei a vd-nek:\n";
	kiir(vd.begin(), vd.end());
	cout << endl;

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	// mettől, meddig és hová copyzza

	cout << "\n  vd\tvi\n";
	for (int i = 0; i < vi.size(); ++i) cout << vd[i] << ' ' << vi[i] << endl;
	cout << endl;

	double vdsum;
	for (int i = 0; i < vd.size(); ++i)
		vdsum=vdsum+vd[i];
	cout << "vd összeadva: " << vdsum << endl;

	double visum;
	for (int i = 0; i < vi.size(); ++i)
		visum=visum+vi[i];

	// mivel vd double és vi int így ha vd-ből vonom ki vi-t akkor
	// pozitív számot fogok kapni ( a különséget a 2 között)
	// ( int lefelé kerekít )
	double kulonbseg = vdsum - visum;
	cout << "A vd és vi közötti különbség:\t" << kulonbseg << endl;

	// reverse függvény megfordítja az elemeket
	reverse(vd.begin(), vd.end());
	cout << "Az elemek megfordítva (vd):\n";
	kiir(vd.begin(),vd.end());
	cout << endl;

	//átlag kiszámítása ( double kell mert a vd double )
	// összes elem elosztva a vektor elemszámával
	double atlag = vdsum/vd.size();
	cout << "A vd átlaga: " << atlag << endl;

	vector<double> vd2;
	for (int i = 0; i < vd.size(); ++i)
		if(vd[i]<atlag) vd2.push_back(vd[i]);
	cout << "\nvd2 elemei ( vd2 elemei < vd átlaga ):\n";
	kiir(vd2.begin(), vd2.end());
	cout << endl;

	sort(vd.begin(), vd.end());
	cout << "A vd elemi sorbarendezve:\n";
	kiir(vd.begin(), vd.end());
}//-------------------- M O R E - V E C T O R --------------------

//---------------------------- M A I N ----------------------------
int main()
try{
	cout<<"-------------------- V E C T O R --------------------\n\n";
	feladat1();
	cout<<"---------------------- L I S T ----------------------\n\n";
	feladat2();
	cout<<"----------------------- M A P -----------------------\n\n";
	feladat3();
	cout<<"--------------- M O R E - V E C T O R ---------------\n\n";
	feladat4();
	return 0;

}catch(exception& e){
	cerr << "Hibák: " << e.what() << endl;
}catch(...){
	cerr << "Gondok vannak!" << endl;
}