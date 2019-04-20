/*
Description: A very simple C++ tic-tac-toe game. (Graphics lib required)
*/

#include "ccc_win.h"
int ccc_win_main()
{
	string play = "y";
	bool game = true;
	do
	{
		Point a(-3.0, 7.0), b(-3.0, -7.0), c(3.0, 7.0), d(3.0, -7.0); 
		Point e(-7.0, 3.0), f(7.0, 3.0), g(-7.0, -3.0), h(7.0, -3.0); 
		Line leftline(a, b), rightline(c, d), highline(e, f), lowline(g, h); 
		cwin << leftline << rightline << highline << lowline; 

		for (int i = 0; i <= 8; i++) 
		{
			Point mouse = cwin.get_mouse("Tic Tac Toe"); 
			double x_input = mouse.get_x();
			double y_input = mouse.get_y(); 

			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8) 
			{
				Point anchor1(x_input + 1.2, y_input + 1.2);
				Point anchor2(x_input - 1.2, y_input - 1.2);
				Point anchor3(x_input - 1.2, y_input + 1.2);
				Point anchor4(x_input + 1.2, y_input - 1.2);
				Line drawx1(anchor1, anchor2);
				Line drawx2(anchor3, anchor4); 
				cwin << drawx1 << drawx2; 
			}
			if (i == 1 || i == 3 || i == 5 || i == 7)  
			{
				Point cir(x_input, y_input); 
				cwin << Circle(cir, 1.5); 
			}

		}

		Point messageanchor(-8.5, 9.0);
		cwin << Message(messageanchor, "Game Over!");
		play = cwin.get_string(" >>> Enter y or Y to play again! <<< :");
		cwin.clear(); 

		if (play == "y" || play == "Y") 
		{
			game = true;
		}
		else 
		{
			game = false;
			Point thx(-3.0, 0.0);
			cwin << Message(thx, "THANKS FOR PLAYING!");
		}

	} while (game); 

	return 0;
}