#include <bits/stdc++.h>
using namespace std;
class Rectangle
{
private:
    float x1, x2, y1, y2;

public:
    void set(float a1, float b1, float a2, float b2);
    void show();
    Rectangle(float a1 = 0, float b1 = 0, float a2 = 0, float b2 = 0)
    {
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
    };
};
void Rectangle::set(float a1, float b1, float a2, float b2)
{
    x1 = a1;
    y1 = b1;
    x2 = a2;
    y2 = b2;
}
void Rectangle::show()
{
    cout << fixed << setprecision(1);
    float s;
    s = (x1 - x2) * (y1 - y2);
    if (s < 0)
        s = 0 - s;
    if (s == 0)
        cout << "Area is:0" << endl;
    else
        cout << "Area is:" << s << endl;
}
int main()
{
    Rectangle p[3];
    p[1].set(1, 1, 2.5, 4);
    p[2].set(3, 3.2, 5, 5);
    p[1].show();
    p[3].show();

    return 0;
}