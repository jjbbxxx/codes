// struct or class?
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	void set(int a, int b);

	void show();
	
	bool equals(Point &p2);
	
};

void Point::set(int a, int b)
{
	x = a;
	y = b;
}

void Point::show()
{
	cout << "(" << x << "," << y << ")" << endl;
}

bool Point::equals(Point &p2)
{
	if (x == p2.x && y == p2.y)
		return true;
	else
		return false;
}
int main()
{
	Point p1;
	p1.set(0, 0);
	p1.show();
	Point p2;
	p2.set(1, 1);
	p2.show();
	cout << "p1==p2?" << p1.equals(p2) << endl;
}
