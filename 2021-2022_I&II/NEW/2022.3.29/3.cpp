#include <bits/stdc++.h>
using namespace std;
bool checkdate(int y,int m,int d)
{
    int yjg, dmax;
    if (y % 4 != 0)
        yjg = 0;
    else if (y % 100 == 0 && y % 400 != 0)
        yjg = 0;
    else
        yjg = 1;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 | m == 12)
        dmax = 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        dmax = 30;
    else if (m == 2 && yjg == 0)
        dmax = 28;
    else if (m == 2 && yjg == 1)
        dmax = 29;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > dmax)
        return false;
    return true;
}

class date
{
private:
    int y, m, d;

public:
    bool set(int a, int b, int c)
    {
        if (checkdate(a,b,c) == 0)
            cout << "date invalid!" << endl;
        else
        {
            y = a;
            m = b;
            d = c;
        }
        return true;
    };
    void show();
    friend class people;
};


void date::show()
{
    cout << y << '.' << m << '.' << d;
}
class people
{
private:
    int number;
    char *name;
    char sex;
    date birthday;
    long int id;

public:
    bool check();
    void show();
    people(int num, const char *s, char x, int a, int b, int c, long int i)
    {
        name = new char(strlen(s) + 1);
        strcpy(name, s);
        birthday.set(a, b, c);
        number=num;
        sex=x;
        id=i;
    };
    ~people()
    {
        delete[] name;
    };
};
bool people::check()
{
    if (checkdate(birthday.y,birthday.m,birthday.d) == 1)
        return true;
    else
        return false;
}
void people::show()
{
    cout << "number:" << number << endl;
    cout << "name:" << name << endl;
    cout << "sex:" << sex << endl;
    cout << "birthday:";
    this->birthday.show();
    cout << endl;
    cout << "id:" << id << endl;
}
int main()
{
    people xiaolan(1,"xiaolan",'f',2008,9,21,74751);
    xiaolan.show();
    return 0;
}