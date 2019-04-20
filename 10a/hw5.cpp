/*
Description: Houses graphics assignment. Asks user for how many houses on a street and plots them using classes.
Known bugs: Only plots the first two houses...  Nothing else works! Most of the program is broken / unfinished.
*/


#include "ccc_win.h"

class House {
public:
	House();											
	House(int newhousenumber, Point newlocation);		
	Point getlocation() const;							 
	int gethousenum() const;							 
	void move(House moved, double dx, double dy);	
	void draw();										 

private:												 
	int housenumber;									 
	Point location;										 
};


void House::move(House moved, double dx, double dy) {   
	double lx, ly;									    
	lx = location.get_x();							    
	ly = location.get_y();
	double dlx, dly = 0.0;							    
	dlx = dx;
	dlx = dy;
	dlx = dx + lx;									    
	dly = dy + ly;
	moved.draw();
}


House::House() {										 
	housenumber = 0;									 
	location = Point(0.0, 0.0);							 
}

House::House(int newhousenumber, Point newlocation) {	 
	housenumber = newhousenumber;						 
	location = newlocation;								 
}

void House::draw() {									 
	double x = 0.0;										 
	double y = 0.0;										 
	x = location.get_x();								 
	y = location.get_y();								 
	Point P (x, y);										 
	Circle H (P, 1.0);									 
	cwin << H;											 
	Message M (P, housenumber);							 
	cwin << M;											 
}

int House::gethousenum() const {						 
	return housenumber;									 
}

Point House::getlocation() const {						 
	return location;									 
}


class Street {
public:
	Street();												 
	Street(int newnumhouses, House newfirst, House newlast);  
	void plot();											 
	House getfirsthouse() const;							 
	House getlasthouse() const;								 
	int	gettotalhouses() const;								 

private:													 
	House first;
	House last;
	int totalhouses;
};

Street::Street() {											 
	totalhouses = 0;										 
	House(1, Point(0.0,1.0));								 
	House(2, Point(2.0,3.0));								 
}

House Street::getfirsthouse() const {  
	return first;
}

House Street::getlasthouse() const {  
	return last;
}

int Street::gettotalhouses() const {  
	return totalhouses;
}

Street::Street(int newnumhouses, House newfirst, House newlast) {  
	first = newfirst;
	last = newlast;
	totalhouses = newnumhouses;
}

void Street::plot() {										 

	first.draw();
	last.draw();

	int divisor = 0;
	divisor = totalhouses;
	Point A = first.getlocation();	 
	Point B = last.getlocation();	 
	double ax = A.get_x();			 
	double ay = A.get_y();			 
	double bx = B.get_x();			 
	double by = B.get_y();			 
	double changexs = (ax - bx) / 1.0 * divisor;  
	double changeys = (ay - by) / 1.0 * divisor;  
	House M;
	M = first;

	for (int j = 0; j < totalhouses; j++)
	{	
		M.move(M,changexs, changeys);
		M.draw();
	}
}


int ccc_win_main() {

	int numhouses = cwin.get_int("How many houses will you plot on the street?");
	int houseNumStart = cwin.get_int("Enter the first house address number");
	int houseNumEnd = cwin.get_int("Enter the last house address number");
	Point houseLocStart = cwin.get_mouse("Click the location of the first house...");
	Point houseLocEnd = cwin.get_mouse("Click the location of the last house...");

	 
	House first(houseNumStart, houseLocStart);   
	House last(houseNumEnd, houseLocEnd);		 
	Street S(numhouses, first, last);			 
	S.plot();									 

	 

	return 0;
}