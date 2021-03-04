/*
	g++ ch12_exercises.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch12_exercises `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
try{
	//-------------------------------------------	1	-------------------------------------------
	int ablak_mag = 800;
	int ablak_szel = 1600;

	Simple_window win{Point{100,100}, ablak_szel, ablak_mag, "ch12 exercises"};
	

	Polygon poly1;
    
    poly1.add(Point(700,650));
    poly1.add(Point(700,400));
    poly1.add(Point(550,400));
    poly1.add(Point(550,650));
    poly1.set_color(Color::red);
    win.attach(poly1);
    win.set_label("ch12 exercises");
    win.wait_for_button();

    Rectangle rectangle1 {Point{350,333}, 100, 50};
    rectangle1.set_color(Color::blue);
    win.attach(rectangle1);
    win.set_label("ch12_ex1");
    win.wait_for_button();
    //-------------------------------------------	1	-------------------------------------------



    //-------------------------------------------	2	-------------------------------------------
    Rectangle rectangle2 {Point{400,400}, 100, 30};
    win.attach(rectangle2);
    win.set_label("ch12_ex2");
    win.wait_for_button();

    Text text2 {Point{425,420}, "Howdy!"};
    win.attach(text2);
    win.set_label("ch12_ex2");
    win.wait_for_button();
    //-------------------------------------------	2	-------------------------------------------


    //-------------------------------------------	3	-------------------------------------------
    
    Open_polyline v_betu; // 30, 150
    v_betu.add(Point(220,400));
    v_betu.add(Point(250,550));
    v_betu.add(Point(280,400));
    v_betu.set_color(Color::green);
    v_betu.set_style(Line_style(Line_style::solid,4));
    win.attach(v_betu);

    Closed_polyline b_betu;
    b_betu.add(Point(300,400));
    b_betu.add(Point(350,400));
    b_betu.add(Point(370,425));
    b_betu.add(Point(370,450));
    b_betu.add(Point(350,475));
    b_betu.add(Point(300,475));
    b_betu.add(Point(350,475));
    b_betu.add(Point(375,500));
    b_betu.add(Point(375,525));
    b_betu.add(Point(350,550));
    b_betu.add(Point(300,550));
    b_betu.set_color(Color::yellow);
    b_betu.set_style(Line_style(Line_style::solid,4));
    win.attach(b_betu);
    win.set_label("ch12_ex3");
    win.wait_for_button();
    
    //-------------------------------------------	3	-------------------------------------------



    //-------------------------------------------	4	-------------------------------------------
    Lines grid;
    int grid_max = 300;
    int grid_size = 100;
    for (int i = grid_size; i<=grid_max; i+=grid_size)
    {
        grid.add(Point(i,0),Point(i,grid_max));
        grid.add(Point(0,i),Point(grid_max,i));
    }
    win.attach(grid);
    
    Vector_ref<Rectangle> vr1;
    for (int i = 0; i < 3; ++i)
    {
    	vr1.push_back(new Rectangle(Point{i*grid_size, i*grid_size}, grid_size, grid_size));
    	vr1[vr1.size()-1].set_fill_color(Color::red);
    	win.attach( vr1[vr1.size() -1] );
    }

    Vector_ref<Rectangle> vr2;
    for (int i = 0; i < 2; ++i)
    {
    	vr2.push_back(new Rectangle(Point{i*grid_size+grid_size, i*grid_size}, grid_size, grid_size));
    	vr2[vr2.size()-1].set_fill_color(Color::white);
    	win.attach( vr2[vr2.size() -1] );
    }

    Vector_ref<Rectangle> vr3;
    for (int i = 0; i < 2; ++i)
    {
    	vr3.push_back(new Rectangle(Point{i*grid_size, i*grid_size+grid_size}, grid_size, grid_size));
    	vr3[vr3.size()-1].set_fill_color(Color::white);
    	win.attach( vr3[vr3.size() -1] );
    }

    Vector_ref<Rectangle> vr4;
    for (int i = 0; i < 1; ++i)
    {
    	vr4.push_back(new Rectangle(Point{i*grid_size, i*grid_size+grid_size*2}, grid_size, grid_size));
    	vr4[vr4.size()-1].set_fill_color(Color::red);
    	win.attach( vr4[vr4.size() -1] );
    }
    Vector_ref<Rectangle> vr5;
    for (int i = 0; i < 1; ++i)
    {
    	vr5.push_back(new Rectangle(Point{i*grid_size+grid_size*2, i*grid_size}, grid_size, grid_size));
    	vr5[vr5.size()-1].set_fill_color(Color::red);
    	win.attach( vr5[vr5.size() -1] );
    }
	win.set_label("ch12_ex4");
    win.wait_for_button();
    //-------------------------------------------	4	-------------------------------------------


    //-------------------------------------------	5	-------------------------------------------
    
    int xmax = (x_max()/4)*3;
    int ymax = (y_max()/3)*2;
	Rectangle rect(Point(217,63),xmax,ymax);
    rect.set_color(Color::red);
    rect.set_style(Line_style(Line_style::solid,15));
    win.attach(rect);

    win.wait_for_button();
    //-------------------------------------------	5	-------------------------------------------


    //-------------------------------------------	6	-------------------------------------------
    Rectangle rectangle6(Point{100,100},2000,1000);
    win.attach(rectangle6);
    win.set_label("ch12_ex6");
    win.wait_for_button();
    //-------------------------------------------	6	-------------------------------------------





    //-------------------------------------------	7	-------------------------------------------
    int haz_magassag = 200;
    int haz_szelesseg = 400;
    Rectangle haztest {Point{800,300},haz_szelesseg, haz_magassag};
    win.attach(haztest);


    Polygon hazteto;
    hazteto.add(Point(800,300));
    hazteto.add(Point(1000,150));
    hazteto.add(Point(1200,300));
    win.attach(hazteto);


    int ajto_magassag = 150;
    int ajto_szelesseg = 100;
    Rectangle ajto {Point {950,350}, ajto_szelesseg, ajto_magassag};
    win.attach(ajto);
    Circle kilincs {Point{1025,435}, 7};
    win.attach(kilincs);


    int ablakok_magassag = 40;
    int ablakok_szelesseg = 40;
    Rectangle ablak1_1 {Point{820,335},ablakok_szelesseg,ablakok_magassag};		win.attach(ablak1_1);
    Rectangle ablak1_2 {Point{860,335},ablakok_szelesseg,ablakok_magassag};		win.attach(ablak1_2);
    Rectangle ablak1_3 {Point{820,375},ablakok_szelesseg,ablakok_magassag};		win.attach(ablak1_3);
    Rectangle ablak1_4 {Point{860,375},ablakok_szelesseg,ablakok_magassag};		win.attach(ablak1_4);
    Rectangle ablak2_1 {Point{1100,335},ablakok_szelesseg,ablakok_magassag};	win.attach(ablak2_1);
    Rectangle ablak2_2 {Point{1100,375},ablakok_szelesseg,ablakok_magassag};	win.attach(ablak2_2);
    Rectangle ablak2_3 {Point{1140,335},ablakok_szelesseg,ablakok_magassag};	win.attach(ablak2_3);
    Rectangle ablak2_4 {Point{1140,375},ablakok_szelesseg,ablakok_magassag};	win.attach(ablak2_4);


    Rectangle kemeny {Point{1100,160}, 50, 125};
    win.attach(kemeny);


    win.set_label("ch12_ex7");
    win.wait_for_button();
    //-------------------------------------------	7	-------------------------------------------



    
    //-------------------------------------------	8	-------------------------------------------
    Circle c1(Point(300,300),220);
    c1.set_style(Line_style(Line_style::solid,25));
    c1.set_color(Color::blue);
    win.attach(c1);

    Circle c2(Point(650,300),220);
    c2.set_style(Line_style(Line_style::solid,25));
    win.attach(c2);

    Circle c3(Point(1000,300),220);
    c3.set_style(Line_style(Line_style::solid,25));
    c3.set_color(Color::red);
    win.attach(c3);

    Circle c4(Point(475,500),220);
    c4.set_style(Line_style(Line_style::solid,25));
    c4.set_color(Color::yellow);
    win.attach(c4);

    Circle c5(Point(825,500),220);
    c5.set_style(Line_style(Line_style::solid,25));
    c5.set_color(Color::green);
    win.attach(c5);
    win.set_label("ch12_ex8");
    win.wait_for_button();
    //-------------------------------------------	8	-------------------------------------------


    //-------------------------------------------	9	-------------------------------------------
    Image pic(Point(100,100),"zsoze.jpg");
    win.attach(pic);
    win.set_label("ch12_ex9");
    win.wait_for_button();
    //-------------------------------------------	9	-------------------------------------------

}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){ 
	cerr << "Van valami baj" << endl;
	return 2;
}
