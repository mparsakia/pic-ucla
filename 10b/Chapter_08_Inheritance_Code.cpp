#include <vector> 
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

class Point2D
{
public:
	Point2D() {}
	Point2D(double a, double b) { x = a; y = b; }

	void setx(double a) { x = a; }
	void sety(double b) { x = b; }

	double getx() const { return x; }
	double gety() const { return y; }
	
	virtual void  print() const { std::cout << "(" << getx() << "," << gety() << ")"; }

private:
	double x;
	double y;
};



class Point3D : public Point2D
{
public:
	Point3D() {}
	Point3D(double a, double b, double c) :Point2D(a, b), z(c) {}
	double getz() const { return z; }
	virtual void  print() const { std::cout << "(" << getx() << "," << gety() << "," << getz() << ")"; }
private:
	double z;
};

class ColorPoint2D : public Point2D
{
public:
	ColorPoint2D() {}
	ColorPoint2D(double a, double b, string input_color):Point2D(a, b), color(input_color) {}
	virtual void  print() const { cout << color << ", ";  std::cout << "(" << getx() << "," << gety() << ")"; }	
private:
	string color;
};


// Abstract container class 

class BaseIntContainer
{

public:

	typedef unsigned int size_type; // alias for the size type

	BaseIntContainer() : num(0), p(NULL) { tmp = new int[10]; } // tmp is some temporary storage of size 10

	size_type get_size() const { return num; }
	
	int* get_p() const { return p; }

	// abstract methods that do not require implementation

	virtual void print() const = 0;
	
	virtual void memalloc()  = 0;
	
	// When an object is destroyed then the destructor 
	// of the base class is executed first, then that of derived one.
	// Thus: To employ polymorphism one has to have the destructor in the base class to be virtual.
	
	// do not forget to delete memory
	virtual ~BaseIntContainer() 
	{ 
		delete tmp;
	  cout << "Base Destructor: The destructor of the base class is executed!\n";
	}

protected:

	int* p;

	size_type num;

	int* tmp; // some temporary storage of size 10
	

};

//
class IntContainer : public BaseIntContainer
{

public:

	IntContainer() : BaseIntContainer() {};

	IntContainer(size_type n) { num = n; memalloc(); };

	virtual void print() const { for (size_type i = 0; i < get_size(); i++) cout << get_p()[i]; }

	virtual void memalloc() { if (p == NULL) p = new int[get_size()]; }

	// do not forget to delete memory
	// but only the memory allocated in the derived class! do not delete tmp here!
	~IntContainer() { delete p; cout << "Derived Destructor: Memory is reclaimed!\n"; /* Do not delete tmp; ERROR!*/ }

private:

};



//BaseIntContainer(size_type n) { num = n; if (num != 0) p = new double[num]; };

int main()
{

	// Example 1: Polymorphism in action:

	vector<Point2D*> p(3);

	p[0] = new Point2D(1, 2);
	p[1] = new ColorPoint2D(1, 2, "blue");
	p[2] = new Point3D(1, 2, 3);

	// using polymorphic features
	for (int i = 0; i < 3; i++)
	{
		p[i]->print(); cout << endl;
	}


	// using polymorphic features
	for (int i = 0; i < 3; i++)
	{
		delete p[i];
	}



	// Example 2:

	// BaseIntContainer* bc = new BaseIntContainer; //This will be an error!

	BaseIntContainer* p1;
	
	IntContainer*     p2;

	p1 = new IntContainer(5); // allowed due to polymorphism

	p2 = new IntContainer(5); 

	// When an object is destroyed then the destructor 
	// of the base class is executed first, then that of derived one.
	// Thus: To employ polymorphism one has to have the destructor in the base class to be virtual
	// Look at the comments for the destructor

	delete p1; 

	delete p2;

	// Observe that p1 will reclaim the memory 

	return 0;	

}
