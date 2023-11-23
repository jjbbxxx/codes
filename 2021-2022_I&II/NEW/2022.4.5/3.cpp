#include <bits/stdc++.h>
using namespace std;
bool checkdate(int y, int m, int d)
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
int sum(int y, int m, int d)
{
    unsigned char x[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, s = 0;
    for (i = 1; i < y; i++)
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            s += 366;
        else
            s += 365;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        x[2] = 29;
    for (i = 1; i < m; i++)
        s += x[i];
    s += d;
    return s;
}
class date
{
private:
    int y, m, d;
public:
    bool set(int a, int b, int c)
    {
        if (checkdate(a, b, c) == 0)
            cout << "date invalid!" << endl;
        else
        {
            y = a;
            m = b;
            d = c;
        }
        return true;
    };
    date(int a=0, int b=1, int c=1)
    {
        if (checkdate(a, b, c) == 0)
            cout << "date invalid!" << endl;
        else
        {
            y = a;
            m = b;
            d = c;
        }
    };
    int operator-(const date &d);
    friend date operator+(int a, const date &d);
    friend date operator+(const date &d, int a);
    date &operator++();
    date operator++(int);
    friend ostream& operator<<(ostream &out,const date& dt);
    friend istream& operator>>(istream &in,date& dt);
};
int date::operator-(const date &d)
{
    int s1, s2;
    int y1, y2, m1, m2, d1, d2;
    y1 = this->y;
    y2 = d.y;
    m1 = this->m;
    m2 = d.m;
    d1 = this->d;
    d2 = d.d;
    s1 = sum(y1, m1, d1);
    s2 = sum(y2, m2, d2);
    return (s1 > s2) ? s1 - s2 : s2 - s1;
}
date operator+(int a, const date &dt)
{
    int y, m, d;
    y = dt.y;
    m = dt.m;
    d = dt.d;
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
    d += a;
    if (d > dmax)
    {
        d -= dmax;
        m++;
    }
    if (m > 12)
    {
        m -= 12;
        y++;
    }
    return date(y, m, d);
}
date operator+(const date &dt, int a)
{
    int y, m, d;
    y = dt.y;
    m = dt.m;
    d = dt.d;
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
    d += a;
    if (d > dmax)
    {
        d -= dmax;
        m++;
    }
    if (m > 12)
    {
        m -= 12;
        y++;
    }
    return date(y, m, d);
}
date &date::operator++()
{
    int y, m, d;
    y = this->y;
    m = this->m;
    d = this->d;
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
    this->d++;
    if (this->d > dmax)
    {
        this->d -= dmax;
        this->m++;
    }
    if (this->m > 12)
    {
        this->m -= 12;
        this->y++;
    }
    return *this;
}
date date::operator++(int)
{
    date temp = *this;
    ++*this;
    return temp;
}
ostream& operator<<(ostream &out,const date& dt){
    out<<dt.y<<'.'<<dt.m<<'.'<<dt.d<<endl;
    return out;
}
istream& operator>>(istream &in,date& dt){
    in>>dt.y>>dt.m>>dt.d;
    return in;

}
int main()
{
    date a,b;
    cout<<"input date A:";
    cin>>a;
    cout<<"input date B:";
    cin>>b;
    cout<<(a-b)<<endl;
    cout<<(a+10)<<endl;
    cout<<(10+a)<<endl;
    cout<<b++<<endl;
    cout<<++b<<endl;
    cout<<++++b<<endl;
    return 0;
}