#include "std_lib_facilities.h"


class B {
public: // a class private-ra csinálja meg alapból viszont ezt el kell érni máshol ezért kell
	virtual void pvf() = 0;
};


class B1 : public B {
public:
	virtual void  vf() {cout << "B1::vf()" << endl; }
	void f() { cout << "B1::f()" << endl; }
	void pvf() override {cout << "B1::pvf()" << endl; }
	;
};


class D1 : public B1 {
public:
	void vf() override {cout << "D1::vf()" << endl; }
	void f() {cout << "D1::f()" << endl; }
	void pvf() override {cout << "D1::pvf()" << endl; }
	;
};


class D2 : public D1 {
public:
	void pvf() override {cout << "D2::pvf()" << endl; }
	;
};


class B2 {
public:
	virtual void pvf() = 0;
};


struct D21 : B2 { // struct miatt nem kell public mert ez alapból úgy csinálja meg
	void pvf() override {cout << szoveg << endl; }
private:
	string szoveg = "D21::pvf()";
};


struct D22 : B2 {
	void pvf() override {cout << szam << endl; }
private:
	int szam = 21;
};


void f(B2& b2_ref)
{
	b2_ref.pvf();
}

int main()
try{

	B1 b1;
	D1 d1;
	B1& b1_ref = d1;
	D2 d2;
	D21 d21;
	D22 d22;

	cout << "------------------- 1. feladat: -------------------\n";
	b1.vf();
	b1.f();
	b1.pvf();

	cout << "------------------- 2. feladat: -------------------\n";
	d1.vf();
	d1.f();
	d1.pvf();

	cout << "------------------- 3. feladat: -------------------\n";
	b1_ref.vf();
	b1_ref.f();
	b1_ref.pvf();

	cout << "------------------- 4. feladat: -------------------\n";
	d2.vf();
	d2.f();
	d2.pvf();


	cout << "------------------- 5. feladat: -------------------\n";
	f(d21);
	f(d22);



	return 0;

}catch(exception& e) {
	cerr << e.what() << endl;
}catch(...) {
	cerr << "Vannak gondok! Csak tudnám hogy hol :(" << endl;
}