/*
    g++ approximation.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o approximation `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


double fac(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        n--;
    }
    return r;
}


double term(double x, int n) { return pow(x,n)/fac(n); }


double expe(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += term(x, i);
    return sum;
}


int szamom = 0;
double expN(double x)
{
    return expe(x, szamom);
}

int main()
try {
    using namespace Graph_lib;

    constexpr int szelesseg = 600;
    constexpr int magassag = 600;
    Simple_window win(Point(50, 50), szelesseg, magassag, "Approximation");

    
    Axis x{Axis::x, Point{30, magassag/2}, szelesseg-60, 18, "one notch == 1"};
    Axis y{Axis::y, Point{szelesseg/2, magassag-30}, magassag-60, 12, "one notch == 1"};
    x.set_color(Color::red);
    y.set_color(Color::red);

    Point orig{szelesseg/2, magassag/2};
    
    const double x_scale = 10;
    const double y_scale = 10;
    Function real_exp{exp, -5, 5, orig, 200, x_scale, y_scale};
    real_exp.set_color(Color::blue);

    win.attach(x); win.attach(y);
    win.attach(real_exp);

    for (int n = 0; n < 6; ++n)
    {
        szamom = n;
        Function e{expN, -25, 25, orig, 200, x_scale, y_scale};
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
    return 0;
}catch (exception& e){
    cerr << e.what() << endl;
    return 1;
}catch (...){
    cerr << "Van valami baj!" << endl;
    return 2;
}