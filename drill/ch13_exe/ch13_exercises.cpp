/*
    g++ -w -Wall ch13_exercises.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13_exercises `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
try{
	using namespace Graph_lib;

	
	int ablak_szelesseg = 1300;
	int ablak_magassag = 825;

	Simple_window win{Point{100,100},
			ablak_szelesseg, ablak_magassag, "ch13_exe"};
	//----------------------------------1----------------------------------
	Graph_lib::Arc arc(Point{100,100},100, 110, 100, 200);
	arc.set_angle1(0);
	arc.set_angle2(180);
	arc.set_angles(-75,5);
	arc.set_style(Line_style(Line_style::dashdot,5));
	win.attach(arc);
    win.set_label("feladat: 1");
    win.wait_for_button();
	//----------------------------------1----------------------------------



	//----------------------------------2----------------------------------
	Box box(Point{150,300},150, 80, 15);
		// elhelyezkedés szél, mag, levágás
	box.set_fill_color(Color::green);
	win.attach(box);
    win.set_label("feladat: 2");
    win.wait_for_button();
    //----------------------------------2----------------------------------



	//----------------------------------3----------------------------------
	Arrow arrow(Point{100,300}, Point{200,700});
		// 2 megadott pont között húz egy nyilat
	win.attach(arrow);
    win.set_label("feladat: 3");
    win.wait_for_button();
	//----------------------------------3----------------------------------



	//----------------------------------6----------------------------------
	//------------------ B O X ------------------
	Box box1(Point{600,100}, 120, 50, 10);
	win.attach(box1);
	box1.set_fill_color(Color::red);

	Box box2(Point{450,250}, 120, 50, 10);
	win.attach(box2);
	box2.set_fill_color(Color::yellow);

	Box box3(Point{750,250}, 120, 50, 10);
	win.attach(box3);
	box3.set_fill_color(Color::yellow);

	//----------------- T E X T -----------------

	Text text1 {Point{620,130}, "IP cimek:"};
	text1.set_font_size(15);
	win.attach(text1);

	Text text2 {Point{470,280}, "IPv4 cim"};
	text2.set_font_size(15);
	win.attach(text2);

	Text text3 {Point{770,280}, "IPv6 cim"};
	text3.set_font_size(15);
	win.attach(text3);

	//---------------- A R R O W ----------------

	Arrow arrow1(Point{660,150}, Point{510,248});
	win.attach(arrow1);

	Arrow arrow2(Point{660,150}, Point{810,248});
	win.attach(arrow2);

    win.set_label("feladat: 6");
    win.wait_for_button();
    //----------------------------------6----------------------------------



    //----------------------------------7----------------------------------
    Vector_ref<Rectangle> vr;
    int meret = 75; // négyzet mérete

    for(int sor = 0; sor < 4; ++sor)
    {
        for(int oszlop = 0; oszlop < 6; ++oszlop)
        {
            vr.push_back(new Rectangle {Point{700+meret*oszlop, 500+meret*sor}, meret, meret});
            int i = vr.size()-1;
            if(i == 0) vr[i].set_fill_color(Color::white);
            if(i == 1) vr[i].set_fill_color(Color::white);
            if(i == 2) vr[i].set_fill_color(Color::white);
            if(i == 3) vr[i].set_fill_color(Color::white);
            if(i == 4) vr[i].set_fill_color(Color::white);
            if(i == 5) vr[i].set_fill_color(Color::white);

            if(i == 6) vr[i].set_fill_color(Color::yellow);
            if(i == 7) vr[i].set_fill_color(Color::red);
            if(i == 8) vr[i].set_fill_color(Color::magenta);
            if(i == 9) vr[i].set_fill_color(Color::blue);
            if(i == 10) vr[i].set_fill_color(Color::cyan);
            if(i == 11) vr[i].set_fill_color(Color::green);

            if(i == 12) vr[i].set_fill_color(Color::dark_yellow);
            if(i == 13) vr[i].set_fill_color(Color::dark_red);
            if(i == 14) vr[i].set_fill_color(Color::dark_magenta);
            if(i == 15) vr[i].set_fill_color(Color::dark_blue);
            if(i == 16) vr[i].set_fill_color(Color::dark_cyan);
            if(i == 17) vr[i].set_fill_color(Color::dark_green);

            if(i == 18) vr[i].set_fill_color(Color::black);
            if(i == 19) vr[i].set_fill_color(Color::black);
            if(i == 20) vr[i].set_fill_color(Color::black);
            if(i == 21) vr[i].set_fill_color(Color::black);
            if(i == 22) vr[i].set_fill_color(Color::black);
            if(i == 23) vr[i].set_fill_color(Color::black);

            win.attach(vr[i]);
        }
    }

    win.set_label("feladat: 7");
    win.wait_for_button();
    //----------------------------------7----------------------------------
 
}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Gondok vannak\n";
	return 2;
}