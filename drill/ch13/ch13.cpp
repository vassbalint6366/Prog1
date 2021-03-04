/*
	g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{

	//---------------------1---------------------
	int ablak_szelesseg = 800;
	int ablak_magassag = 1000;

	Simple_window win{Point{100,100},
			ablak_szelesseg, ablak_magassag, "Ch13"};
	//---------------------1---------------------



	//---------------------2---------------------
	Lines grid;
    int grid_max = 800;
    int grid_size = 100;
    for (int i = grid_size; i<=grid_max; i+=grid_size) {
        grid.add(Point(i,0),Point(i,grid_max));
        grid.add(Point(0,i),Point(grid_max,i));
    }
    win.attach(grid);
    //---------------------2---------------------



    //---------------------3---------------------
    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i)
    {
    	vr.push_back(new Rectangle(Point{i*grid_size, i*grid_size}, grid_size, grid_size));
    	vr[vr.size()-1].set_fill_color(Color::red);
    	win.attach( vr[vr.size() -1] );
    }
    //---------------------3---------------------



    //---------------------4---------------------
    int kep_meret200 = 200;

    Image pic1(Point(600,200),"badge.jpg");
    pic1.set_mask(Point(0,200), kep_meret200, kep_meret200);
    win.attach(pic1);

    Image pic2(Point(200,600),"badge.jpg");
    pic2.set_mask(Point(0,200), kep_meret200, kep_meret200);
    win.attach(pic2);

    Image pic3(Point(400,100),"badge.jpg");
    pic3.set_mask(Point(0,200), kep_meret200, kep_meret200);
    win.attach(pic3);

    win.wait_for_button();
    //---------------------4---------------------



    //---------------------5---------------------
    /*
    int leptetes = 100;
    int kep_meret100 = 100;

    for (int i = 0; i<=700; i+=leptetes)
    {
    	for (int j = 0; j<=700; j+=leptetes)
    	{
    		
    		Image pic_round(Point(i,j),"badge.jpg");
    		pic_round.set_mask(Point(200,0),kep_meret100,kep_meret100);
    		win.attach(pic_round);

    		win.set_label("Ch13");

    		win.wait_for_button();
    	}
    }
    */
    
    int kep_meret100=100;
    Image pic_round(Point{0,0},"badge.jpg");
    pic_round.set_mask(Point(200,0),kep_meret100,kep_meret100);
    win.attach(pic_round);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		win.set_label("Ch13");
    		win.wait_for_button();
    		if (j < 7) pic_round.move(100,0);
    		else pic_round.move(-700,100);
    	}
    }

    //---------------------5---------------------
}