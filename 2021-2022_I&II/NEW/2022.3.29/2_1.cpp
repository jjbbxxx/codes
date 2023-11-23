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
        cout << "Create point(" << a << ',' << b << ")." << endl;
        x = a;
        y = b;
    };
};
void Point::set(float a,float b){
    x=a;
    y=b;
}
void Point::show()
{
    cout<<fixed<<setprecision(1);
    cout << "point is(" << x << ',' << y << ")." << endl;
}
int main()
{
    Point p[3];
    p[1].set(1.0, 2.0);
    p[2].set(3.0, 4.0);
    p[1].show();

    return 0;
}