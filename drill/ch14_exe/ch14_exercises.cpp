/*
    g++ -w -Wall ch14_exercises.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch14_exercises `fltk-config --ldflags --use-images`
*/
// 1, 11-14 feladat


#include "Simple_window.h"
#include "Graph.h"

int main()
try{
	using namespace Graph_lib;
	
	int ablak_szelesseg = 1300;
	int ablak_magassag = 800;

	Simple_window win{Point{100,100},
			ablak_szelesseg, ablak_magassag, "ch14_exe"};

    //----------------------------------1----------------------------------
    Smiley mosolygosfej(Point(250,150),75);
    //        elhelyezkedés, méret
    mosolygosfej.set_fill_color(Color::yellow); // smile kitöltési színe
    mosolygosfej.set_color(Color::blue); //szem, száj, és a körvonal színe
    //mosolygosfej.move(-180,50); //így kell mozgatni
    //mosolygosfej.set_radius(120); //így kell változtatni a méretét
    mosolygosfej.set_style(Line_style(Line_style::dot,3));
    win.attach(mosolygosfej);
    win.wait_for_button();


    Frowny szomorufej(Point(700,150),100);
    szomorufej.set_fill_color(Color::red);
    win.attach(szomorufej);
    win.wait_for_button();


    Hat_smiley mosolygosfejsapka(Point(250,600),175);
    mosolygosfejsapka.set_fill_color(Color::yellow);
    mosolygosfejsapka.set_color(Color::dark_green);
    mosolygosfejsapka.set_style(Line_style(Line_style::solid,5));
    win.attach(mosolygosfejsapka);
    win.wait_for_button();


    Hat_frowny szomorufejsapka(Point(700,600),190);
    szomorufejsapka.set_style(Line_style(Line_style::solid,5));
    szomorufejsapka.set_fill_color(Color::yellow);
    win.attach(szomorufejsapka);
    win.wait_for_button();

    //LECSATOLÁS:
    win.detach(mosolygosfej);
    win.detach(szomorufej);
    win.detach(mosolygosfejsapka);
    win.detach(szomorufejsapka);
    //----------------------------------1----------------------------------



	//----------------------------------11----------------------------------
	Binary_tree bt(Point(600,50),6,"");
    win.attach(bt);
    win.set_label("feladat: 11");
    win.wait_for_button();

    // ÍGY KELL MOZGATNI
    /*
    bt.move(50,50);
    bt.move(-50,-50);
    win.wait_for_button();
	*/

    win.detach(bt);
    //----------------------------------11----------------------------------



    //----------------------------------12----------------------------------
    Binary_tree_squares bts(Point(600,50),6,"");
    win.attach(bts);
    win.set_label("feladat: 12");
    win.wait_for_button();

    win.detach(bts);
    //----------------------------------12----------------------------------



    //----------------------------------13----------------------------------
    Binary_tree bt2(Point(600,50),6,"ad"); //arrow up
    win.attach(bt2);
    win.set_label("feladat: 13.1");
    win.wait_for_button();

    win.detach(bt2);

    Binary_tree bt3(Point(600,50),6,"au"); //arrow down
    win.attach(bt3);
    win.set_label("feladat: 13.2");
    win.wait_for_button();
    //----------------------------------13----------------------------------



    //----------------------------------14----------------------------------
    bt3.set_node_label("r","Root"); //az első mindegy hogy left vagy right
    bt3.set_node_label("lr","lr");
    bt3.set_node_label("lrl","lrl");
    bt3.set_node_label("lrlr","lrlr");
    bt3.set_node_label("lrlrl","lrlrl");
    bt3.set_node_label("lrlrlr","lrlrlr");
    bt3.set_node_label("lrrlr", "lrrlr");
    win.set_label("feladat: 14");
    win.wait_for_button();
    //----------------------------------14----------------------------------


}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Gondok vannak\n";
	return 2;
}