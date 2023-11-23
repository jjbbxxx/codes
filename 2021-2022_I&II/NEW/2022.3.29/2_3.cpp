#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    float x, y;

public:
    void set(float a, float b);
    void show();
    Point(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    };
};
void Point::set(float a, float b)
{
    x = a;
    y = b;
}
void Point::show()
{
    cout << fixed << setprecision(1);
    cout << "(" << x << ',' << y << ") ";
}
class PointSet
{
private:
    int num;        // The number of points in the set
    Point point[5]; // Array of points
public:
    PointSet(int a = 0)
    {
        num = a;
        if (a > 5)
            num = 5;
        for (int i = 0; i < num; i++)
        {
            point[i].set(0, 0);
        }
    };                  // No point by default
    bool add(Point &p); // Add points to the set.
    // If there are more than 5 points in the set, the join fails.
    Point get(int n); // Take out the n-th point,
    // the numbering of the points starts from 0.
    // Check the plausibility of the number.
    // If the point does not exist, a prompt message is displayed.
    void setAll(float x, float y);            // Set all points in the set to the same coordinate x, y
    int getNum();                             // Returns the number of elements
    bool resetPoint(int n, float x, float y); // Set the nth point in the set to
    // the new coordinates x, y,
    //  or return ¡°false¡± if the point does not exist
    void show(); // Show all elements
};

bool PointSet::add(Point &p)
{
    if (num == 5)
    {
        cout << "add fail!" << endl;
        return false;
    }
    else
    {
        point[num] = p;
        num++;
        cout << "add succeed!" << endl;
    }
    return true;
}
Point PointSet::get(int n)
{
    if (n > num)
    {
        cout << "num invalid!" << endl;
        return point[0];
    }
    return point[n];
}
void PointSet::setAll(float x, float y)
{
    for (int i = 0; i < num; i++)
    {
        point[i].set(x, y);
    }
}
int PointSet::getNum()
{
    return num;
}
bool PointSet::resetPoint(int n, float x, float y)
{
    if (n > num)
    {
        cout << "num invalid!" << endl;
        return false;
    }
    point[n - 1].set(x, y);
    cout << "set succeed!" << endl;
    return true;
}
void PointSet::show()
{
    for (int i = 0; i < num; i++)
    {
        point[i].show();
    }
    cout << endl;
}
int main()
{
    Point a(2.6, 4.3);
    PointSet b(4);
    b.show();
    cout << "num:" << b.getNum() << endl;
    b.add(a);
    b.show();
    b.add(a);
    b.resetPoint(23543, 34, 35321);
    b.resetPoint(2, 3.2, 4.4);
    b.show();
    b.setAll(1.2, 3.4);
    b.show();
    (b.get(3)).show();
    return 0;
}